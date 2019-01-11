#pragma once

class Menu
{
private:
    void start_game();
    void save_game();
    void continue_game();
    void end_game();
    void draw_splash();
    void print_menu();
    void get_intput();
    void main_menu_input();
    void show_score();

public:
    void run();
};
