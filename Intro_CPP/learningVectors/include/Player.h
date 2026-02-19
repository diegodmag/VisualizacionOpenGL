#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>
#include "Vector2D.h"

class Player{

private: 

    // Model
    sf::CircleShape m_shape; 

    // 
    math::linear::Vector2D m_playerPosition; 
    math::linear::Vector2D m_playerDirection; 
    math::linear::Vector2D m_Velocity; 

    sf::Vector2f finalPosition{0.0f,0.0f};

    float m_speed = 4.0f; 

    void InitShape(sf::Color color, int radius){
        m_shape.setRadius(radius); 
        m_shape.setOrigin(15,15);
        m_shape.setFillColor(color); 
    }

public: 

    Player(sf::Color color, int radius, float pos_x, float pos_y)
    {
        InitShape(color, radius);
        //
        m_playerPosition[0]=pos_x; 
        m_playerPosition[1]=pos_y; 

        m_playerDirection[0]=0.0f;
        m_playerDirection[1]=0.0f;         
    }


    math::linear::Vector2D& getDirection() {
        return m_playerDirection;
    }

    // math::linear::Vector2D& getVelocity() {
    //     m_Velocity= m_playerDirection*m_speed;
    //     return m_Velocity;
    // }

    void Move(){
        m_playerDirection= math::linear::Normalize(m_playerDirection);
        m_Velocity= m_playerDirection*m_speed;
        m_playerPosition+=m_Velocity; 
        // Passed to a sf::Vector2
        finalPosition.x = m_playerPosition.x; 
        finalPosition.y = m_playerPosition.y; 

        m_shape.setPosition(finalPosition);
    }

    const sf::CircleShape& returnShape()const {
        return m_shape;
    }

};


#endif 