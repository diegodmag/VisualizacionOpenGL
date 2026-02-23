#include "Game.h"

#include <random>

int main(){

    

    // sf::Color color, float radius, float x, float y, float speed
    Player p1{sf::Color::Green, 15, 400.0f, 300.0f, 100.0f};
    
    math::linear::Vector2D enemy_offset {30.f, 30.f};
    math::linear::Vector2D enemy_1_initial_pos {p1.getPosition()+enemy_offset} ;
    Enemy enemy_1{sf::Color::Red, 15, enemy_1_initial_pos[0], enemy_1_initial_pos[0], 2.0f};
    
    math::linear::Vector2D enemy_2_initial_pos {p1.getPosition()+(-enemy_offset)} ;
    Enemy enemy_2{sf::Color::Red, 15, enemy_2_initial_pos[0], enemy_2_initial_pos[0], 2.0f};
    // Enemy enemy_1{sf::Color::Red, 15, 400.0f, 300.0f, 4.0f};
    
    std::vector<Enemy> enemies {enemy_1, enemy_2};
    
    Game game{p1, enemies};

    game.Update();
}
