#ifndef IENTITY_HPP
#define IENTITY_HPP

namespace Game{
    class IEntity{
    public:
        virtual void vMove() = 0;
        virtual void vDraw() = 0;
        virtual void vLogic() = 0;
    };
}

#endif