#include "SFML/Graphics.hpp"
#include "Cell.h"
#include "Board.h"

#include "Game.h"


int main()
{
    int window_width = 800;
    int window_height = 600;
    float length_cell = 20;
    
    Game game (window_width, window_height, length_cell);
    game.run();
    
}
