#include <SFML/Graphics.hpp>
#include <cmath>

#include "Levels.h"

// Normalize a vector (SFML has no built-in normalize in 2.x)
// sf::Vector2f normalize(const sf::Vector2f& v)
// {
//     float length = std::sqrt(v.x * v.x + v.y * v.y);
//     if (length == 0)
//         return {0.f, 0.f};

//     return v / length;
// }

void executeLevel(){ 
    sf::RenderWindow window(sf::VideoMode(800, 600), "Vector Movement Demo");
    window.setFramerateLimit(60);

    // level::level_1(window);

    level::level_2(window);
}   

int main(){
    executeLevel();
}
