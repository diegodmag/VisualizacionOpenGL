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
    float m_speed = 4.0f; 

    void InitShape(int radius){
        m_shape.setRadius(radius); 
        m_shape.setOrigin(15,15);
        m_shape.setFillColor(sf::Color::Green); 
    }

public: 

    Player(int radius, float pos_x, float pos_y)
    {

        InitShape(radius);
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

    const math::linear::Vector2D& getMovement() {
        m_playerDirection= math::linear::Normalize(m_playerDirection);
        m_Velocity= m_playerDirection*m_speed;
        m_playerPosition+=m_Velocity; 
        return m_playerPosition;
    }

    sf::CircleShape& returnShape(){
        return m_shape;
    }

    // void setShapePos(sf::Vector2& new_pos){
    //     m_shape.setPosition(new_pos);
    // }

};


#endif 