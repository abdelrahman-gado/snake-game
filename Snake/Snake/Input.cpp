#include "Game.h"

void Game::input()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        m_window.close();
    
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        direction = DIR_UP;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        direction = DIR_DOWN;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        direction = DIR_LEFT;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        direction = DIR_RIGHT;
    }
    
}