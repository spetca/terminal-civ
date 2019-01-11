#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include "../inc/menu.h"
#include "../inc/termcolor.hpp"
void Menu::run_game()
{
    constexpr auto greetings_text = "Welcome to ";
    constexpr auto gamename_text = "Terminal Civ!";
    constexpr auto sp = "  ";

    std::ostringstream str_os;
    

    constexpr auto menu_entry_text = R"(
          1. Play a New Game
          2. Continue Previous Game
          3. View Highscores and Statistics
          4. Exit
    )";
//test
    draw_splash(); 
    std::cout << sp << greetings_text << termcolor::blue << gamename_text << std::endl;
    std::cout << termcolor::reset;

    std::cout <<  termcolor::red << menu_entry_text << std::endl;
    std::cout << termcolor::reset;
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

    
    std::cout << termcolor::green << splash << std::endl; 
    std::cout << termcolor::reset; 
}

