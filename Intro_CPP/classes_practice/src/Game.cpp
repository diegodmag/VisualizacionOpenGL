#include "Game.h"

Game::Game(Player& player, std::vector<Enemy>& enemies)
    : m_player(player),
      m_deltaTime{0.0f},
      m_enemies(enemies)
    {

    m_window.create(sf::VideoMode(800, 600), "Vector Movement Demo");
    m_window.setFramerateLimit(60);

    }

void Game::Update(){

    sf::Clock clock;

    while (m_window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        m_deltaTime = elapsed.asSeconds(); // deltaTime
        while (m_window.pollEvent(m_event))
        {
            /* code */
            if(m_event.type == sf::Event::Closed){
                m_window.close();
            }
        }
        
        m_player.Update(m_deltaTime);
        std::cout<<m_deltaTime<<'\n';
        // for (size_t i = 0; i < std::ssize(m_enemies); i++)
        // {
        //     // --> Player position 
        //     // conpute direction 
        //     math::linear::Vector2D directionToPlayer = m_player.getPosition() - m_enemies[i].getPosition();
        //     directionToPlayer = math::linear::Normalize(directionToPlayer);
        //     // m_enemies[i].SetTarget(directionToPlayer);
        //     // m_enemies[i].SetTarget(math::linear::Vector2D{1.0f,1.0f});
        //     // std::cout<<"Updating enemies\n"; 

        //     // --> Update enemy
        //     m_enemies[i].Update(m_deltaTime);
        // }
        


        m_window.clear(sf::Color::Black);
        m_window.draw(m_player.getDrawable());
        // for (size_t i = 0; i < std::ssize(m_enemies);  i++)
        // {a
        //     /* code */
        //     m_window.draw(m_enemies[i].getDrawable());
        // }
        
        m_window.display();
    }
    
}