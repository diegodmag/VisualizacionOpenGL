#include "Levels.h"

#include <cmath>
#include "Vector2D.h"
#include "Player.h"

void level::level_1(sf::RenderWindow& window){
    // Player - Visual representation
    sf::CircleShape playerModel(15);
    playerModel.setOrigin(15, 15);
    playerModel.setFillColor(sf::Color::Green);
    // Player vector
    math::linear::Vector2D playerPosition(400.f, 300.f);
    //Speed
    float speed = 4.f;

    sf::Event event; 

    while(window.isOpen()){

        // -- Event System < son señales, cosas que se quieren leer una unica vez 
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        // -- Real Time Input State < Se lee continuamente el estado tecla o mouse
        sf::Vector2 mousWorldCoords = window.mapPixelToCoords(sf::Mouse::getPosition(window));

        // Using our Vector2D class 
        math::linear::Vector2D mousePosition {mousWorldCoords.x,mousWorldCoords.y};
        
        // Follow mouse logic
        // Direction to follow
        math::linear::Vector2D direction = mousePosition - playerPosition;
        direction = math::linear::Normalize(direction); 
        math::linear::Vector2D velocity = direction*speed;
        
        playerPosition+=velocity; 

        // Convert into sf::Vector2f
        sf::Vector2 finalPosition {playerPosition.x, playerPosition.y};

        // Set visual position
        playerModel.setPosition(finalPosition);

        // Draw 
        window.clear(sf::Color::Black);
        window.draw(playerModel);
        window.display();
    }

}

void level::level_2(sf::RenderWindow& window){


    Player p1 (15, 400.0f, 300.0f);
    sf::Event event;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        p1.getDirection() = {0.0f, 0.0f}; 

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            // playerDirection.y -= 1.f; 
            p1.getDirection().y -= 1.f; 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            // playerDirection.y += 1.f; 
            p1.getDirection().y += 1.f; 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            // playerDirection.x -= 1.f; 
            p1.getDirection().x -= 1.f; 
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            // playerDirection.x += 1.f; 
            p1.getDirection().x += 1.f; 
        }

        math::linear::Vector2D player_move = p1.getMovement();
        // std::cout<<playerPosition<<'\n';

        sf::Vector2 finalPosition{player_move.x, player_move.y};

        p1.returnShape().setPosition(finalPosition);
        // Draw
        window.clear(sf::Color::Black);
        window.draw(p1.returnShape());
        window.display();
    }
    
}