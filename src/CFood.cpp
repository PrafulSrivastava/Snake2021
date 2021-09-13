#include "CFood.hpp"

namespace Game{
    CFood::CFood(const std::shared_ptr<CGameGrid>& sharedPtrGameGrid)
    : m_consumed(false)
    , m_sharedPtrGrid(sharedPtrGameGrid){
        vSpawnFood();
    }

    void CFood::vSpawnFood(){
        auto x = CUtility::iGetRandom(FoodConfig::MIN_COORD, GridConfig::BOUNDRY_HEIGHT - FoodConfig::ROW_ADJUSTMENT);
        auto y = CUtility::iGetRandom(FoodConfig::MIN_COORD, GridConfig::BOUNDRY_WIDTH - FoodConfig::COL_ADJUSTMENT);
        m_pos = {x, y};
    }

    void CFood::vDraw(){
        auto& grid = m_sharedPtrGrid->vecGetGameGrid();
        grid[m_pos.first][m_pos.second] = FoodConfig::FOOD;
    }

    void CFood::vMove(){
        
    }

    void CFood::vLogic(){
        if(m_consumed){
            vSpawnFood();
            m_consumed = false;
        }
    }

    FoodConfig::SPAWN_COORD CFood::pairGetFoodPos() const{
        return m_pos;
    }

    bool CFood::bGetFoodStatus() const{
        return m_consumed;
    }
    void CFood::vSetFoodStatus(const bool& status){
        m_consumed = status;
    }
}