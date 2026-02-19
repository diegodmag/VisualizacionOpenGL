#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>
#include "Vector2D.h"


class Entity{

protected: 

    sf::CircleShape m_shape; 
    math::linear::Vector2D m_position;
    math::linear::Vector2D m_direction;
    float m_speed;
    
public:

    Entity(sf::Color color, float radius, float x, float y, float speed);
    ~Entity();

    virtual void Update() = 0; // Needs to be declared by children 

    virtual void ComputeMovement();

    const sf::Drawable& getDrawable() const;
    
};


#endif