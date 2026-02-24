#include "Game.h"

#include <random>

int main(){

    // Instancia de jugador 
    Player p1{sf::Color::Green, 15, 400.0f, 300.0f, 100.0f};
    
    // Distancia respecto al jugador
    math::linear::Vector2D enemy_offset {30.f, 30.f};
    math::linear::Vector2D enemy_1_initial_pos {p1.getPosition()+enemy_offset} ;
    // Instancia de enemigo
    Enemy enemy_1{sf::Color::Red, 15, enemy_1_initial_pos[0], enemy_1_initial_pos[0], 1.0f, p1.getPosition()};
    // Vector de enemigo  
    // math::linear::Vector2D enemy_2_initial_pos {p1.getPosition()-enemy_offset} ;
    // // Instancia de enemigo
    // Enemy enemy_2{sf::Color::Red, 15, enemy_2_initial_pos[0], enemy_2_initial_pos[0], 1.0f, p1.getPosition()};
    // std::vector<Enemy> enemies {enemy_1, enemy_2};
    std::vector<Enemy> enemies {enemy_1};
        
    Game game{p1, enemies};

    game.Update();
}
