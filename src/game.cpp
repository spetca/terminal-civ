#include "../inc/game.h"
#include "../inc/termcolor.hpp"
#include <iostream>
#include <vector>
const auto desert = "";
const auto farm = "▦";
const auto water = "♒";
const auto city = "⌂";
const wchar_t* vlg = L"◌";
Game::Game(Tribe tribe, int diff) : m_tribe(tribe), m_difficulty(diff)
{
    // std::cout << "Starting game with " << m_tribe << std::endl;
    board = new std::vector<std::vector<char>>(8, std::vector<char>(8, '.'));

    draw_board(8);
}

void
Game::draw_board(int sz)
{
    set_board_point(0, 0, 'p');
    for (auto r : *board) {
        for (auto c : r) {
            std::wcout << c;
            std::wcout << "  ";
        }
        std::cout << std::endl;
    }
}

void
Game::set_board_point(int x, int y, char c)
{
    (*board)[x][y] = c;
}
void
Game::run()
{
    // std::cout << "running game..." << std::endl;
}