#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"
// #include "Vector2D.h"

class Enemy : public Entity{

private: 

    math::linear::Vector2D& m_target; 

public:

    Enemy(sf::Color color, float radius, float x, float y, float speed, math::linear::Vector2D& target);

    void ComputeMovement(float deltaTime) override; 

    void Update(float deltaTime) override;


};


#endif
