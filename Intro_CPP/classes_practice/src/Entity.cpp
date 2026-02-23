#include "Entity.h"

    Entity::Entity(sf::Color color, float radius, float x, float y, float speed)
        : m_speed{speed}{
            m_shape.setRadius(radius);
            m_shape.setOrigin(radius,radius);
            m_shape.setFillColor(color);
            m_position[0] = x;
            m_position[1] = y;
            m_shape.setPosition(x, y); 
        }

    Entity::~Entity(){
        
    }

    void Entity::ComputeMovement(float deltaTime){
        if(math::linear::Magnitude(m_direction) >0){
            m_direction = math::linear::Normalize(m_direction);
            m_position += m_direction*m_speed*deltaTime;
            // Graphics
            m_shape.setPosition(m_position[0], m_position[1]);
        }
    }

    const sf::Drawable& Entity::getDrawable() const {return m_shape;}

    const math::linear::Vector2D& Entity::getPosition()const {return m_position;}

