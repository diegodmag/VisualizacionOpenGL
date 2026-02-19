#include "Game.h"

Game::Game(Player& player)
    : m_player{player}{

    m_window.create(sf::VideoMode(800, 600), "Vector Movement Demo");
    m_window.setFramerateLimit(60);

    }

void Game::Update(){

    while (m_window.isOpen())
    {
        while (m_window.pollEvent(m_event))
        {
            /* code */
            if(m_event.type == sf::Event::Closed){
                m_window.close();
            }
        }
        
        m_player.Update();

        m_window.clear(sf::Color::Black);
        m_window.draw(m_player.getDrawable());
        m_window.display();
    }
    
}