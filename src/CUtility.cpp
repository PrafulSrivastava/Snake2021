#include "CUtility.hpp"

namespace Game{

    int CUtility::iGetRandom(int low, int high){
        return std::max((rand() % high), low);
    }

    UtilityConfig::COORD CUtility::pairGetRandom(int low, int high){
        return {iGetRandom(low, high), iGetRandom(low, high)};
    }

    bool CUtility::bCompareCoordinates(UtilityConfig::COORD c1, UtilityConfig::COORD c2){
        if(c1.first == c2.first){
            if (c1.second == c2.second){
                return true;
            }   
        }
        return false;
    }

    UtilityConfig::eFAULTY_COORD CUtility::bIsBoundryCollision(UtilityConfig::COORD c){
        if(c.first == 0){
            return UtilityConfig::eFAULTY_COORD::UROW;
        }
        else if(c.first == GridConfig::BOUNDRY_HEIGHT-1){
            return UtilityConfig::eFAULTY_COORD::DROW;
        }
        else if(c.second == 0){
            return UtilityConfig::eFAULTY_COORD::LCOL;
        }
        else if(c.second == GridConfig::BOUNDRY_WIDTH-1){
            return UtilityConfig::eFAULTY_COORD::RCOL;
        }
        return UtilityConfig::eFAULTY_COORD::NOT_FAULTY;
    }

    void CUtility::vPrint(const char* color, std::string str, bool newLine){
        std::cout<<color<<str;
        if(newLine){
            std::cout<<std::endl;
        }
    }
    void CUtility::vPrint(const char* color, int num, bool newLine){
        std::cout<<color<<num;
        if(newLine){
            std::cout<<std::endl;
        }
    }
    void CUtility::vPrint(const char* color, char ch, bool newLine){
        std::cout<<color<<ch;
        if(newLine){
            std::cout<<std::endl;
        }
    }

    bool CUtility::bIsValidCoordinate(UtilityConfig::COORD c){
        if(c.first == UtilityConfig::INVALID_POS || c.second == UtilityConfig::INVALID_POS){
            return false;
        }
        return true;
    }
}