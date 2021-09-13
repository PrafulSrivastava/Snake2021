#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include <iostream>
#include <functional>
#include <vector>
#include "IEntity.hpp"
#include <memory>
#include <stdlib.h>

namespace Game{

    namespace GridConfig{
        using GAME_GRID = std::vector<std::vector<char>>;
        constexpr auto BOUNDRY_HEIGHT = 20;
        constexpr auto BOUNDRY_WIDTH = 22;
        constexpr auto BRICKS = 'H';
        constexpr auto DEFAULT = ' ';
    }

    namespace SnakeConfig{
        using SPAWN_COORD = std::pair<int, int>;
        using BODY_COORD = std::pair<int, int>;
        using BODY_COORD_VECTOR = std::vector<BODY_COORD>;
        using POOP_VECTOR = std::vector<BODY_COORD>;
        using BODY_VECTOR = std::vector<char>;
        using SCORE_CALLBACK = std::function<void()>;
        using STATE_CALLBACK = std::function<void(const bool&)>;
        using FOOD_CONSUMED_CALLBACK = std::function<void(const bool&)>;

        constexpr auto MAX_LENGTH = 20;
        constexpr auto MIN_LENGTH = 1;
        constexpr auto ROW_ORIGIN = GridConfig::BOUNDRY_HEIGHT / 2;
        constexpr auto COL_ORIGIN = GridConfig::BOUNDRY_WIDTH / 2;
        
        constexpr auto HEAD = '@';
        constexpr auto TAIL = '#';
        constexpr auto BODY = 'o';
        constexpr auto EMPTY = '.';
        constexpr auto POOP = '%';

        constexpr auto UP = 'w';
        constexpr auto DOWN = 's';
        constexpr auto LEFT = 'a';
        constexpr auto RIGHT = 'd';
        constexpr auto EXIT = static_cast<char>(27);
        constexpr auto PAUSE = static_cast<char>(9);

        constexpr auto DUMP = 'p';
        enum class eDIRECTION{ UP = 0, DOWN, LEFT, RIGHT, UNKNOWN};
    }

    namespace FoodConfig{
        using SPAWN_COORD = std::pair<int, int>;
        constexpr auto FOOD = '*';
        constexpr auto MIN_COORD = 1;
        constexpr auto ROW_ADJUSTMENT = 1;
        constexpr auto COL_ADJUSTMENT = 3;
    }

    namespace UtilityConfig{
        using COORD = std::pair<int, int>;
        enum class eFAULTY_COORD {LCOL = 0, RCOL, UROW, DROW, NOT_FAULTY};
        constexpr auto INVALID_POS = -1;
    }

    namespace GameConfig{
        using ENTITY_VECTOR = std::vector<std::shared_ptr<Game::IEntity>>;
        constexpr auto DELAY = 100;
        constexpr auto HELP = "Press [TAB] to Pause \nPress [Esc] to Exit \nPress [W, S, A, D] to Move around";
        constexpr auto SCORE = "$$ Score $$ : ";
        constexpr auto GAME_OVER = "(-_-) GAME OVER!!";
    }

    namespace ColorConfig{
        constexpr auto DEFAULT = "";
        constexpr auto BLACK = "\033[30m";
        constexpr auto RED = "\033[31m";
        constexpr auto GREEN = "\033[32m";
        constexpr auto YELLOW = "\033[33m";
        constexpr auto BLUE = "\033[34m";
        constexpr auto MAGENTA = "\033[35m";
        constexpr auto CYAN = "\033[36m";
        constexpr auto ORANGE = "\033[37m";
        constexpr auto BOLD_BLACK = "\033[1m\033[30m";
        constexpr auto BOLD_RED = "\033[1m\033[31m";
        constexpr auto BOLD_GREEN = "\033[1m\033[32m";
        constexpr auto BOLD_YELLOW = "\033[1m\033[33m";
        constexpr auto BOLD_BLUE = "\033[1m\033[34m";
        constexpr auto BOLD_MAGENTA = "\033[1m\033[35m";
        constexpr auto BOLD_CYAN = "\033[1m\033[36m";
        constexpr auto BOLD_ORANGE = "\033[1m\033[37m";

        constexpr auto BOLD = "\033[1m";        
    }

}

#endif
