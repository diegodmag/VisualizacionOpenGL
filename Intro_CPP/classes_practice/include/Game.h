#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Player.h"
#include "Enemy.h"

class Game
{
private:
    sf::RenderWindow m_window;
    Player& m_player;
    std::vector<Enemy>& m_enemies; 
    sf::Event m_event;

    float m_deltaTime;

public:

    Game(Player& player, std::vector<Enemy>& enemies);

    void Update();

};

#endif