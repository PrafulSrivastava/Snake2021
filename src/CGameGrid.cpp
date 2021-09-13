#include "CGameGrid.hpp"
#include "CUtility.hpp"

namespace Game{

    GridConfig::GAME_GRID CGameGrid::m_grid(GridConfig::BOUNDRY_HEIGHT, std::vector<char>(GridConfig::BOUNDRY_WIDTH, GridConfig::DEFAULT));

    CGameGrid::CGameGrid(){
        vResetGrid();
    }

    GridConfig::GAME_GRID& CGameGrid::vecGetGameGrid(){
        return m_grid;
    }
    void CGameGrid::vDraw(){
        system("clear");
        CUtility::vPrint(ColorConfig::ORANGE, GameConfig::HELP, true);

        for(int row = 0; row < GridConfig::BOUNDRY_HEIGHT ; row++){
            for(int col = 0; col < GridConfig::BOUNDRY_WIDTH; col++){
                auto Color = ColorConfig::DEFAULT;
                if(col == 0 || col == GridConfig::BOUNDRY_WIDTH-1){
                    Color = ColorConfig::MAGENTA;
                }
                else if(row == 0 || row == GridConfig::BOUNDRY_HEIGHT-1){
                    Color = ColorConfig::MAGENTA;
                }
                else{
                    if(m_grid[row][col] == FoodConfig::FOOD){
                        Color = ColorConfig::BOLD_CYAN;
                    }
                    else if(m_grid[row][col] == SnakeConfig::POOP){
                        Color = ColorConfig::YELLOW;
                    }
                    else if(m_grid[row][col] != GridConfig::DEFAULT){
                        if(m_grid[row][col] == SnakeConfig::HEAD)
                            Color = ColorConfig::BOLD_ORANGE;
                        else if(m_grid[row][col] == SnakeConfig::TAIL)
                            Color = ColorConfig::ORANGE;
                        else
                            Color = ColorConfig::GREEN;
                    }
                }    
                CUtility::vPrint(Color, m_grid[row][col], false);       
            }
            std::cout<<std::endl;
        }
        vResetGrid();
    }

    void CGameGrid::vLogic(){

    }

    void CGameGrid::vMove(){
        
    }
    void CGameGrid::vResetGrid(){
        for(int row = 0; row < GridConfig::BOUNDRY_HEIGHT; row++){
            for(int col = 0; col < GridConfig::BOUNDRY_WIDTH ; col++){
                if(col == 0 || col == GridConfig::BOUNDRY_WIDTH-1){
                    m_grid[row][col] = GridConfig::BRICKS;
                }
                else if(row == 0 || row == GridConfig::BOUNDRY_HEIGHT-1){
                    m_grid[row][col] = GridConfig::BRICKS;                    
                }
                else{
                    m_grid[row][col] = GridConfig::DEFAULT;
                }
            }
        }
    }
}