#ifndef DIRECTMOVEMENT_H
#define DIRECTMOVEMENT_H

#include "IMovementBehavior.h"

class DirectMovement: public IMovementBehavior{

private: 
    math::linear::Vector2D direction{};

public: 
    void Move(  math::linear::Vector2D& pos, 
                const math::linear::Vector2D& target, 
                float speed, 
                float dt) override {
        
        direction = math::linear::Normalize(target-pos); 
        pos += direction*(dt*(speed*100.f)); 
    }

};

#endif