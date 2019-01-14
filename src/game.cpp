#include "../inc/game.h"
#include "../inc/termcolor.hpp"
#include <iostream>
#include <vector>

Game::Game(char tribe, int diff) : m_tribe(tribe), m_difficulty(diff)
{
    std::cout << "Starting game with " << m_tribe << std::endl;
}

void
Game::run()
{
    std::cout << "running game..." << std::endl;
}