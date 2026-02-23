#include "Enemy.h"

Enemy::Enemy(sf::Color color, float radius, float x, float y, float speed, math::linear::Vector2D& target)
    : Entity(color, radius, x, y, speed), // Inicializa la clase padre
      m_target(target)                 // Inicializa la referencia al target
{
    // Aquí el cuerpo del constructor puede ir vacío
}

void Enemy::ComputeMovement(float deltaTime){
    m_position[0] = math::functions::Lerp(m_position[0], m_target[0],deltaTime*m_speed);
    m_position[1] = math::functions::Lerp(m_position[1], m_target[1],deltaTime*m_speed);
    m_shape.setPosition(m_position[0], m_position[1]);
}

void Enemy::Update(float deltaTime){
    
    ComputeMovement(deltaTime);
}