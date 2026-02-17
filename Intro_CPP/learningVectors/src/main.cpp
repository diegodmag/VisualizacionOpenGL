#include <SFML/Graphics.hpp>
#include <cmath>

#include "Vector2D.h"
#include "Vector2D.h"

// Normalize a vector (SFML has no built-in normalize in 2.x)
sf::Vector2f normalize(const sf::Vector2f& v)
{
    float length = std::sqrt(v.x * v.x + v.y * v.y);
    if (length == 0)
        return {0.f, 0.f};

    return v / length;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Vector Movement Demo");
    window.setFramerateLimit(60);

    // Player - Visual representation
    sf::CircleShape playerModel(15);
    playerModel.setOrigin(15, 15);
    playerModel.setFillColor(sf::Color::Green);
    // Player vector
    Vector2D playerPosition(400.f, 300.f);
    sf::Vector2f playerPos(400.f, 300.f);


    float speed = 4.f;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Mouse position (window coordinates)
        sf::Vector2f mouse =
            window.mapPixelToCoords(sf::Mouse::getPosition(window));

        // We need to get the mouse coordinates ax World Position
        Vector2D mousePosition {mouse.x, mouse.y}; 
        // std::cout<<mousePosition<<'\n';

        // -------- VECTOR MATH CORE --------

        Vector2D direr =  mousePosition- playerPosition; 
        direr = Normalize(direr);
        Vector2D veloz = direr*speed; 

        playerPosition+=veloz;
        // How is going to follow the mouse  ? 
        // Vector2D direction = mousePosition-playerPosition;// Direction to follow 
        // direction.normalize(); // Set to a normalized vector (magnitud of one) 
        // Vector2D velocity {direction[0]*speed,direction[1]*speed };
        // playerPosition = playerPosition+velocity; //

        sf::Vector2f direction = mouse - playerPos;   // subtraction
        direction = normalize(direction);              // normalization
        sf::Vector2f velocity = direction * speed;     // scalar multiplication
        
        // std::cout<<"Veloz: "<<veloz<<'\n';
        // std::cout<<"Velocity"<<velocity.x<<','<<velocity.y<<'\n'; 
        
        playerPos += velocity;                         // addition



        // ----------------------------------

        sf::Vector2f finalPosition {playerPosition.x,playerPosition.y};
        // playerModel.setPosition(finalPosition);

        playerModel.setPosition(finalPosition);
        // playerModel.setPosition(playerPos);

        // Draw 

        window.clear(sf::Color::Black);
        window.draw(playerModel);
        window.display();
    }

    return 0;
}
