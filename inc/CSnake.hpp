#ifndef CSNAKE_HPP
#define CSNAKE_HPP

#include "IEntity.hpp"
#include "Globals.hpp"
#include "CFood.hpp"
#include "CGameGrid.hpp"
#include "kbhit.hpp"
#include <memory>

namespace Game{
    class CSnake : public IEntity {
    public:
        CSnake(const SnakeConfig::SPAWN_COORD& origin, 
            const std::shared_ptr<CGameGrid>& sharedPtrGameGrid,
            const std::shared_ptr<CFood>& sharedPtrFood);
        void vMove() override;
        void vDraw() override;
        void vLogic() override;
        void vSetScoreCallBack(const SnakeConfig::SCORE_CALLBACK& callback);
        void vSetGameStateCallBack(const SnakeConfig::STATE_CALLBACK& callback);
        void vSetFoodConsumedCallBack(const SnakeConfig::STATE_CALLBACK& callback);
        void vHandlePoopSituation();
    private:
        SnakeConfig::SPAWN_COORD m_origin;
        SnakeConfig::BODY_COORD_VECTOR m_bodyCoords;
        SnakeConfig::BODY_VECTOR m_body;
        std::shared_ptr<CGameGrid> m_sharedPtrGrid;
        std::shared_ptr<CFood> m_sharedPtrFood;
        std::unique_ptr<keyboard> m_uniqPtrKeybord;
        SnakeConfig::eDIRECTION m_direction;
        SnakeConfig::SCORE_CALLBACK m_scoreCb;
        SnakeConfig::STATE_CALLBACK m_gameStateCb;
        SnakeConfig::FOOD_CONSUMED_CALLBACK m_foodConsumedCb;
        SnakeConfig::POOP_VECTOR m_vecPoopCoord;
        int m_length;
        int m_poopCount;
    };
}
#endif