#include "Game.h"

int main(){

    // sf::Color color, float radius, float x, float y, float speed
    Player p1{sf::Color::Green, 15, 400.0f, 300.0f, 4.0f};
    Game game{p1};

    game.Update();
}
