#pragma once

class Game
{
private:
    char m_tribe;
    int m_difficulty;

public:
    Game(char tribe, int diff);
    void run();
};