#include "CSnake.hpp"
#include "CUtility.hpp"
#include "thread"

namespace Game{
    
    CSnake::CSnake(const SnakeConfig::SPAWN_COORD& origin, 
        const std::shared_ptr<CGameGrid>& sharedPtrGameGrid,
        const std::shared_ptr<CFood>& sharedPtrFood)
    : m_origin(origin)
    , m_poopCount(0)
    , m_length(SnakeConfig::MIN_LENGTH)
    , m_sharedPtrGrid(sharedPtrGameGrid)
    , m_sharedPtrFood(sharedPtrFood)
    , m_uniqPtrKeybord(std::make_unique<keyboard>()) {

        for(int i = 0; i<SnakeConfig::MAX_LENGTH; i++){
            if(i == 0){
                m_body.push_back(SnakeConfig::HEAD);
                m_bodyCoords.push_back(m_origin);
            }            
            m_body.push_back(SnakeConfig::EMPTY);
            m_bodyCoords.push_back(SnakeConfig::BODY_COORD(UtilityConfig::INVALID_POS, UtilityConfig::INVALID_POS));
        }
    }

    void CSnake::vDraw(){
        auto& grid = m_sharedPtrGrid->vecGetGameGrid();
        for(int i = 0; i< m_length; i++){
            if(CUtility::bIsValidCoordinate(m_bodyCoords[i]) && m_body[i] != SnakeConfig::EMPTY){
                grid[m_bodyCoords[i].first][m_bodyCoords[i].second] = m_body[i];
            }
        }

        for(int i = 0; i< m_poopCount; i++){
            grid[m_vecPoopCoord[i].first][m_vecPoopCoord[i].second] = SnakeConfig::POOP;
        } 
    }
    void CSnake::vLogic(){
        
        if(m_length < 1){
            m_gameStateCb(false);
        }

        switch(m_direction){
            case SnakeConfig::eDIRECTION::UP:
                m_origin.first-=1;
                break;
            case SnakeConfig::eDIRECTION::DOWN:
                m_origin.first+=1;
                break;
            case SnakeConfig::eDIRECTION::LEFT:
                m_origin.second-=1;
                break;
            case SnakeConfig::eDIRECTION::RIGHT:
                m_origin.second+=1;
                break;
        }

        if(m_direction != SnakeConfig::eDIRECTION::UNKNOWN){
            for(auto pt: m_bodyCoords){
                if(CUtility::bCompareCoordinates(m_origin, pt)){
                    m_gameStateCb(false);
                }
            }
        }
        

        switch(CUtility::bIsBoundryCollision(m_origin)){
            case UtilityConfig::eFAULTY_COORD::UROW:
                m_origin.first = GridConfig::BOUNDRY_HEIGHT - 2;
                break;
            case UtilityConfig::eFAULTY_COORD::DROW:
                m_origin.first = 0;
                break;
            case UtilityConfig::eFAULTY_COORD::LCOL:
                m_origin.second = GridConfig::BOUNDRY_WIDTH - 2;
                break;
            case UtilityConfig::eFAULTY_COORD::RCOL:
                m_origin.second = 0;
                break;
        }

        auto foodPos = m_sharedPtrFood->pairGetFoodPos();
        SnakeConfig::BODY_COORD tempCoord = m_bodyCoords[0];
        for(int i =0; i < m_length; i++){
            auto temp = m_bodyCoords[i];
            if(i == 0){
                m_body[i] = SnakeConfig::HEAD;        
                m_bodyCoords[i] = m_origin;
            }
            else{
                if(i == (m_length - 1)){
                    m_body[i] = SnakeConfig::TAIL;
                }
                else{
                    m_body[i] = SnakeConfig::BODY;
                } 
                m_bodyCoords[i].first = tempCoord.first;
                m_bodyCoords[i].second = tempCoord.second;   
            }
            tempCoord = temp;    
        }

        if(CUtility::bCompareCoordinates(m_origin, foodPos)){
            m_foodConsumedCb(true);
            m_length++;
            m_scoreCb();
        } 

        for(auto poop: m_vecPoopCoord){
            if(CUtility::bCompareCoordinates(m_origin, poop)){
                m_gameStateCb(false);
            }
        }       
    }

    void CSnake::vMove(){
        char cmd;
        if(m_uniqPtrKeybord->kbhit()){

            cmd = static_cast<char>( m_uniqPtrKeybord->getch());
            switch(cmd){
                case SnakeConfig::UP:
                    if(m_direction != SnakeConfig::eDIRECTION::DOWN)
                        m_direction = SnakeConfig::eDIRECTION::UP;
                    break;
                case SnakeConfig::DOWN:
                    if(m_direction != SnakeConfig::eDIRECTION::UP)
                        m_direction = SnakeConfig::eDIRECTION::DOWN;
                    break;
                case SnakeConfig::LEFT:
                    if(m_direction != SnakeConfig::eDIRECTION::RIGHT)
                        m_direction = SnakeConfig::eDIRECTION::LEFT;
                    break;
                case SnakeConfig::RIGHT:
                    if(m_direction != SnakeConfig::eDIRECTION::LEFT)
                        m_direction = SnakeConfig::eDIRECTION::RIGHT;
                    break;
                case SnakeConfig::DUMP:
                    vHandlePoopSituation();
                    break;
                case SnakeConfig::EXIT:
                    m_gameStateCb(false);
                    break;
                case SnakeConfig::PAUSE:
                    m_direction = SnakeConfig::eDIRECTION::UNKNOWN;
                    break;
            }
        }
    }

    void CSnake::vSetScoreCallBack(const SnakeConfig::SCORE_CALLBACK& callback){
        m_scoreCb = callback;
    }

    void CSnake::vSetGameStateCallBack(const SnakeConfig::STATE_CALLBACK& callback){
        m_gameStateCb = callback;
    }

    void CSnake::vSetFoodConsumedCallBack(const SnakeConfig::STATE_CALLBACK& callback){
        m_foodConsumedCb = callback;
    }
    void CSnake::vHandlePoopSituation(){
        SnakeConfig::BODY_COORD tailCoord;
        tailCoord.first = m_bodyCoords[m_length - 1].first;
        tailCoord.second = m_bodyCoords[m_length - 1].second;
        m_vecPoopCoord.push_back(tailCoord);
        m_length--;
        m_poopCount++;
    }
}