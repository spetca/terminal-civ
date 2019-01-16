#pragma once
#include <string>
#include <vector>
class Menu
{
private:
    void start_game();
    void continue_game();
    void draw_splash();
    void get_intput();
    void show_score();
    void window_clear();
    void input_cursor();
    int menu_scroll(std::vector<std::string>& str, int highlight_start);

public:
    void run();
};
