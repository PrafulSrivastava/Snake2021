#include "CGame.hpp"
#include "CGameGrid.hpp"
#include "CFood.hpp"
#include "CSnake.hpp"
#include <iostream>
#include <thread>

namespace Game{

    bool CGame::m_bGameOver = false;
    bool CGame::m_bDelayControl = false;
    GameConfig::ENTITY_VECTOR CGame::m_entities;
    int CGame::m_score = 0;
    int CGame::m_delay = GameConfig::DELAY;

    void CGame::vInitialize(){
        srand(time(NULL));

        std::shared_ptr<Game::CGameGrid> sharedPtrGameGrid = std::make_shared<Game::CGameGrid>();

        std::shared_ptr<Game::CFood> sharedPtrFood = std::make_shared<Game::CFood>(sharedPtrGameGrid);
        m_entities.push_back(sharedPtrFood);

        Game::SnakeConfig::SPAWN_COORD origin = {Game::SnakeConfig::ROW_ORIGIN, Game::SnakeConfig::COL_ORIGIN};      

        std::shared_ptr<Game::CSnake> sharedPtrSnake = std::make_shared<Game::CSnake>(origin, sharedPtrGameGrid, sharedPtrFood);
        sharedPtrSnake->vSetScoreCallBack(vIncrementScore);  
        sharedPtrSnake->vSetGameStateCallBack(vSetGameState); 
        sharedPtrSnake->vSetFoodConsumedCallBack(std::bind(&CFood::vSetFoodStatus, sharedPtrFood, std::placeholders::_1)); 
        m_entities.push_back(sharedPtrSnake);

        m_entities.push_back(sharedPtrGameGrid);
    }

    bool CGame::bGetGameState(){
        return !m_bGameOver;
    }

    void CGame::vSetGameState(const bool& state){
        m_bGameOver = !state;
    }

    GameConfig::ENTITY_VECTOR& CGame::vecGetEntityVector(){
        return m_entities;
    }

    void CGame::vRunGameLoop(){
        vInitialize();
        auto& entities = vecGetEntityVector();
        while(bGetGameState()){
            
            for(auto entity: entities){
                
                entity->vMove();
                entity->vLogic();
                entity->vDraw();                
                
            }
            CUtility::vPrint(ColorConfig::BOLD_BLUE, GameConfig::SCORE, false);
            CUtility::vPrint(ColorConfig::ORANGE, std::to_string(m_score), true);
            
            if(m_bDelayControl){
                m_delay-=10;
                m_bDelayControl= false;
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(m_delay));
        }
       CUtility::vPrint(ColorConfig::BOLD_RED, GameConfig::GAME_OVER, true);
    }

    void CGame::vIncrementScore(){
        if(m_score % 5 == 0 && m_score != 0){
            m_bDelayControl = true;
        }
        m_score++;
    }
}