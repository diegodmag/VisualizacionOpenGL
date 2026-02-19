#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include "Player.h"

class Game
{
private:
    sf::RenderWindow m_window;
    Player m_player;
    sf::Event m_event;
public:

    Game(Player& player);

    void Update();

};

#endif