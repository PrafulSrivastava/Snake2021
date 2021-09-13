#ifndef CUTILITY_HPP
#define CUTILITY_HPP

#include "Globals.hpp"

namespace Game{
    class CUtility{
    public:
        static int iGetRandom(int low, int high);
        static UtilityConfig::COORD pairGetRandom(int low, int high);
        static bool bCompareCoordinates(UtilityConfig::COORD c1, UtilityConfig::COORD c2);
        static UtilityConfig::eFAULTY_COORD bIsBoundryCollision(UtilityConfig::COORD c);
        static void vPrint(const char*, std::string, bool);
        static void vPrint(const char*, int, bool);
        static void vPrint(const char*, char, bool);
        static bool bIsValidCoordinate(UtilityConfig::COORD c);
    private:
        static UtilityConfig::eFAULTY_COORD m_faultyCoord;
    };
}

#endif