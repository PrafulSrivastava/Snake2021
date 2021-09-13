#ifndef CGAME_HPP
#define CGAME_HPP

#include "Globals.hpp"

namespace Game{
    class CGame{
    public:
        static void vInitialize();
        static bool bGetGameState();
        static void vSetGameState(const bool& state);
        static GameConfig::ENTITY_VECTOR& vecGetEntityVector();
        static void vRunGameLoop();
        static void vIncrementScore();
    private:
        static bool m_bGameOver;
        static GameConfig::ENTITY_VECTOR m_entities;
        static int m_score;
        static int m_delay;
        static bool m_bDelayControl;
    };
}

#endif