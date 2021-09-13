#ifndef CGAMEGRID_HPP
#define CGAMEGRID_HPP

#include "Globals.hpp"
#include "IEntity.hpp"

namespace Game{
    class CGameGrid : public IEntity{
    public:
        CGameGrid();
        void vMove() override;
        void vDraw() override;
        void vLogic() override;
        void vResetGrid();
        static GridConfig::GAME_GRID& vecGetGameGrid();
    private:
        int m_rows;
        int m_cols;
        static GridConfig::GAME_GRID m_grid;
    };
}
#endif