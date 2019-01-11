#include <iostream>
#include <sstream>
#include <vector>
#include "../inc/menu.h"
#include "../inc/color.h"
void Menu::run_game()
{
    constexpr auto greetings_text = "Welcome to ";
    constexpr auto gamename_text = "Terminal Civ!";
    constexpr auto sp = "  ";

    std::ostringstream str_os;
    std::ostringstream title_richtext;
    title_richtext << bold_on << sp << greetings_text << blue << gamename_text
                 << def << bold_off << "\n";

    constexpr auto menu_entry_text = R"(
          1. Play a New Game
          2. Continue Previous Game
          3. View Highscores and Statistics
          4. Exit
    )";
//test
    system("CLS");
    draw_splash(); 
    //get tribe

    //get difficulty

    //get board size

    //run_game
}

















void Menu::draw_splash() {
    const auto splash = R"(
 _____                   _             _   _____ _        
|_   _|                 (_)           | | /  __ (_)       
  | | ___ _ __ _ __ ___  _ _ __   __ _| | | /  \/___   __ 
  | |/ _ \ '__| '_ ` _ \| | '_ \ / _` | | | |   | \ \ / / 
  | |  __/ |  | | | | | | | | | | (_| | | | \__/\ |\ V /  
  \_/\___|_|  |_| |_| |_|_|_| |_|\__,_|_|  \____/_| \_/   
                                                          
                                                                                                                               
    )";

    std::ostringstream splash_screen; 
    splash_screen << green << bold_on << splash << bold_off << def; 
    splash_screen << '\n\n\n'; 
    std::cout << splash_screen.str(); 
}

