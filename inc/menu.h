#pragma once

class Menu
{
private:
    void start_game();
    void continue_game();
    void draw_splash();
    void get_intput();
    void main_menu_input();
    void show_score();
    void window_clear();
    void input_cursor();

public:
    void run();
};
