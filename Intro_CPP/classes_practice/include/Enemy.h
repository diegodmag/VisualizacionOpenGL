#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
#include "IAMovement/IMovementBehavior.h"
#include "IAMovement/DirectMovement.h"
#include "IAMovement/LerpMovement.h"
// #include "Vector2D.h"

class Enemy : public Entity{

private: 

    math::linear::Vector2D& m_target; 

    // If we are using pointer a best practice is initiliazed it as nullptr
    IMovementBehavior* m_currentMovement = nullptr; 
    
public:
    LerpMovement lerpMovement {}; // default initialization 
    DirectMovement directMovement {}; 

    Enemy(sf::Color color, float radius, float x, float y, float speed, math::linear::Vector2D& target);

    void ComputeMovement(float deltaTime) override; 

    void Update(float deltaTime) override;

    void ChangeMovement(IMovementBehavior& newMovement);

};


#endif
