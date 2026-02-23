#include "Enemy.h"

// void Enemy::SetTarget(const math::linear::Vector2D& target){

//     m_direction[0] = target[0];
//     m_direction[1] = target[1];

// }
void Enemy::FollowTarget(const math::linear::Vector2D& target, float deltaTime){

    // -> The coordinates should be linearly interpolate 


}

void Enemy::ComputeMovement(float deltaTime){
    
}

void Enemy::Update(float deltaTime){
    
    ComputeMovement(deltaTime);
}