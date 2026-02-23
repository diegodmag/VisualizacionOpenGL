#include "Enemy.h"

Enemy::Enemy(sf::Color color, float radius, float x, float y, float speed, math::linear::Vector2D& target)
    : Entity(color, radius, x, y, speed), // Inicializa la clase padre
      m_target(target)                 // Inicializa la referencia al target
{
    // Aquí el cuerpo del constructor puede ir vacío
}

void Enemy::ComputeMovement(float deltaTime){

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) ChangeMovement(lerpMovement);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) ChangeMovement(directMovement);

    if(m_currentMovement!=nullptr){
        m_currentMovement->Move(m_position, m_target, m_speed, deltaTime);
        
        m_shape.setPosition(m_position[0], m_position[1]);
    }
    
}

void Enemy::Update(float deltaTime){
    
    ComputeMovement(deltaTime);
}

void Enemy::ChangeMovement(IMovementBehavior& newMovement){
    m_currentMovement= (&newMovement);
}