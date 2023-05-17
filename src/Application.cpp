#include "Game.h"
#include "globals.h"

#include <iostream>

int main(int argc, char **argv)
{
    Game *game = new Game("Kill The Square!!", globals::SCREEN_WIDTH, globals::SCREEN_HEIGHT);
    game->gameLoop();

    delete game;
    return 0;
}
