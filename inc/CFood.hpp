#ifndef CFOOD_HPP
#define CFOOD_HPP

#include "Globals.hpp"
#include "IEntity.hpp"
#include "CUtility.hpp"
#include "CGameGrid.hpp"
#include <memory>

namespace Game{
    class CFood : public IEntity{
    public:
        CFood(const std::shared_ptr<CGameGrid>& sharedPtrGameGrid);
        void vMove() override;
        void vDraw() override;
        void vLogic() override;
        bool bGetFoodStatus() const;
        void vSetFoodStatus(const bool& status);
        FoodConfig::SPAWN_COORD pairGetFoodPos() const;
    private:
        void vSpawnFood();
        bool m_consumed;
        FoodConfig::SPAWN_COORD m_pos;
        std::shared_ptr<CGameGrid> m_sharedPtrGrid;
    };
}

#endif