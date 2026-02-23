#ifndef LERPMOVEMENT_H
#define LERPMOVEMENT_H

#include "IMovementBehavior.h"

class LerpMovement: public IMovementBehavior{

    void Move(  math::linear::Vector2D& pos, 
                const math::linear::Vector2D& target, 
                float speed, 
                float dt) override {
        
        pos[0] = math::functions::Lerp(pos[0], target[0], dt*speed);
        pos[1] = math::functions::Lerp(pos[1], target[1], dt*speed);
    }

};

#endif