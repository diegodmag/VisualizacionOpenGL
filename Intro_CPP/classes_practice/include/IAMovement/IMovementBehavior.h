#ifndef IMOVEMENTBEHAVIOR_H
#define IMOVEMENTBEHAVIOR_H

#include "Vector2D.h"

class IMovementBehavior{

public: 

    IMovementBehavior()=default;

    virtual ~IMovementBehavior()=default;

    virtual void Move(math::linear::Vector2D& currentPos, 
                      const math::linear::Vector2D& target, 
                      float speed, float dt) = 0;

};

#endif