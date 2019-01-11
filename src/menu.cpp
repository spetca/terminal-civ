#include "../inc/menu.h"
#include "../inc/termcolor.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>

void
Menu::run()
{
    constexpr auto greetings_text = "Welcome to ";
    constexpr auto gamename_text = "~~termtopia!~~";
    constexpr auto sp = "  ";

    std::ostringstream str_os;

    constexpr auto menu_entry_text = R"(
          1. Play a New Game
          2. Continue Previous Game
          3. View Highscores and Statistics
          4. Info
          5. Exit
    )";
    // splash screen + menu
    draw_splash();
    std::cout << termcolor::blue << sp << greetings_text << gamename_text << std::endl;
    std::cout << termcolor::reset;

    std::cout << termcolor::red << menu_entry_text << std::endl;
    std::cout << termcolor::reset;

    // get user option
    main_menu_input();
}

void
Menu::draw_splash()
{
    const auto splash = R"(
 _                            _              _        
| |                          | |            (_)       
| |_ ___ _ __ _ __ ___  _ __ | |_ ___  _ __  _  __ _  
| __/ _ \ '__| '_ ` _ \| '_ \| __/ _ \| '_ \| |/ _` | 
| ||  __/ |  | | | | | | |_) | || (_) | |_) | | (_| | 
 \__\___|_|  |_| |_| |_| .__/ \__\___/| .__/|_|\__,_| 
                       | |            | |             
                       |_|            |_|                                                                                                                              
    )";

    std::cout << termcolor::green << splash << std::endl;
    std::cout << termcolor::reset;
}

void
Menu::main_menu_input()
{
    std::cout << "          :";
    char c;
    std::cin >> c;

    switch (c) {
    case '1':
        start_game();
        break;

    case '2':
        // continue_game();
        break;

    case '3':
        // show_score();
        break;

    case '4':
        // info
        break;
    case '5':
        exit(EXIT_SUCCESS);
        break;
    default:
        run();
    }
}

void
Menu::start_game()
{
    constexpr auto tribe_pick = R"(
          1. Tribe1
          2. Tribe2
          3. Tribe3
          4. Tribe4
          5. Tribe5
          6. Tribe6
    )";
    std::cout << termcolor::yellow << "Starting New Game..." << std::endl;
    std::cout << termcolor::reset;
    std::cout << tribe_pick << std::endl;
}

void
Menu::show_score()
{
    std::cout << "High score" << std::endl;
}