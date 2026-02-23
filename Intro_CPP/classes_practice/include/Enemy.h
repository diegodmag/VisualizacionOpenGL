#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
// #include "Vector2D.h"

class Enemy : public Entity{

public:

    using Entity::Entity;


    // void SetTarget(const math::linear::Vector2D& target);
    void FollowTarget(const math::linear::Vector2D& target, float deltaTime);

    void ComputeMovement(float deltaTime) override; 

    void Update(float deltaTime) override;


};


#endif
