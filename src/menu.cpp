#include "../inc/menu.h"
#include "../inc/termcolor.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>

void
Menu::input_cursor()
{
    std::cout << "          :";
}

void
Menu::window_clear()
{
#if defined(_WIN32) || defined(_WIN64)
    std::system("cls");
#elif defined(__APPLE__)
#define TERMCOLOR_OS_MACOS
#elif defined(__unix__) || defined(__unix)
#define TERMCOLOR_OS_LINUX
#else
#error unsupported platform
#endif
}

void
Menu::run()
{
    constexpr auto greetings_text = "Welcome to ";
    constexpr auto gamename_text = "~~termtopia!~~";
    constexpr auto sp = "  ";
    constexpr auto menu_entry_text = R"(
          1. Start New Game
          2. Resume Game
          3. View Highscores
          4. Info
          5. Exit
    )";

    // splash screen + menu
    draw_splash();
    std::cout << termcolor::blue << sp << greetings_text << gamename_text << std::endl;
    std::cout << termcolor::reset;

    // main menu
    std::cout << termcolor::red << menu_entry_text << std::endl;
    std::cout << termcolor::reset;

    // get user option and proceed
    main_menu_input();
}

void
Menu::draw_splash()
{
    const auto splash = R"(
 _                      _              _       
| |                    | |            (_)      
| |_ ___ _ __ _ __ ___ | |_ ___  _ __  _  __ _ 
| __/ _ \ '__| '_ ` _ \| __/ _ \| '_ \| |/ _` |
| ||  __/ |  | | | | | | || (_) | |_) | | (_| |
 \__\___|_|  |_| |_| |_|\__\___/| .__/|_|\__,_|
                                | |            
                                |_|                                                                                                                                      
    )";

    std::cout << termcolor::green << splash << std::endl;
    std::cout << termcolor::reset;
}

void
Menu::main_menu_input()
{
    input_cursor();
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
    window_clear();
    constexpr auto tribe_pick = R"(
    Select a Tribe  | Tribe Starts With
    -------------------------------------
    | 1. Tribe1     |   Perk 1          |
    | 2. Tribe2     |   Perk 1          |
    | 3. Tribe3     |   Perk 1          |
    | 4. Tribe4     |   Perk 1          |
    | 5. Tribe5     |   Perk 1          |
    | 6. Tribe6     |   Perk 1          |
    -------------------------------------
    )";
    std::cout << termcolor::yellow << "Starting New Game..." << std::endl;
    std::cout << termcolor::reset;
    std::cout << tribe_pick << std::endl;
    input_cursor();
    char c;
    std::cin >> c;

    // Game game;
    // game.run(c);
}

void
Menu::show_score()
{
    std::cout << "High score" << std::endl;
}