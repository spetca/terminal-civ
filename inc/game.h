#pragma once
#include <vector>
enum Tribe { A, B, C, D, E };
class Game
{
private:
    Tribe m_tribe;
    int m_difficulty;
    void draw_board(int sz);
    void set_board_point(int x, int y, char c);

public:
    std::vector<std::vector<char>>* board;
    Game(Tribe tribe, int diff);
    void run();
};