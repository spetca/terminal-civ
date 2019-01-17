#include "../inc/game.h"
#include "../inc/menu.h"
#include "../inc/termcolor.hpp"
#include <conio.h>
#include <cstdlib>
#include <iostream>
#include <sstream>


void
Menu::input_cursor()
{
    std::cout << "          :" << termcolor::blink;
}

void
Menu::window_clear()
{
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
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

    std::vector<std::string> menu_entry_text{
        "Welcome to termtopia!",
        "-----------------------",
        "1. Start New Game",
        "2. Resume Game",
        "3. View Highscores",
        "4. Info",
        "5. Exit",
    };

    // splash screen + menu
    draw_splash();
    std::cout << termcolor::blue << sp << greetings_text << gamename_text << std::endl;
    std::cout << termcolor::reset;

    // main menu
    int c = menu_scroll(menu_entry_text, 2);
    std::cout << termcolor::reset;

    switch (c) {
    case 1:
        start_game();
        break;

    case 2:
        // continue_game();
        break;

    case 3:
        // show_score();
        break;

    case 4:
        // info
        break;
    case 5:
        exit(EXIT_SUCCESS);
        break;
    default:
        run();
    }
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

    std::cout << termcolor::green << termcolor::bold << splash << std::endl;
    std::cout << termcolor::reset;
}


void
Menu::start_game()
{
    window_clear();

    std::vector<std::string> tribe_selection{
        "Select a Tribe  | Tribe Starts With",   "-------------------------------------",
        "| 1. Tribe1     |   Perk 1          |", "| 2. Tribe2     |   Perk 1          |",
        "| 2. Tribe2     |   Perk 1          |", "| 3. Tribe3     |   Perk 1          |",
        "| 4. Tribe4     |   Perk 1          |", "| 5. Tribe5     |   Perk 1          |",
        "| 6. Tribe6     |   Perk 1          |", "-------------------------------------"
    };

    std::vector<std::string> difficulty_selection{
        "Select Difficulty",
        "-------------------------------------",
        "1",
        "2",
        "3",
        "4",
        "5"
    };

    // changes to make it an arrow pick and highlight
    int tribe = menu_scroll(tribe_selection, 2);

    // changes to make it an arrow pick and highlight
    int difficulty = menu_scroll(difficulty_selection, 2);

    std::cout << tribe << ", " << difficulty << std::endl;
    Game game((Tribe)tribe, difficulty);
    game.run();
}

void
Menu::show_score()
{
    std::cout << "High score" << std::endl;
}

int
Menu::menu_scroll(std::vector<std::string>& str, int highlight_start)
{
    // changes to make it an arrow pick and highlight
    int highlight_line = 0;
    char input;
    std::cout << "w - up, s - down, d - next" << std::endl;
    while (input != '\r') {
        for (int i = 0; i < str.size(); i++) {
            if (i == highlight_line + highlight_start)
                std::cout << termcolor::on_yellow << termcolor::red;

            std::cout << str[i] << std::endl;

            if (i == highlight_line + highlight_start)
                std::cout << termcolor::reset;
        }
        input = getch();
        switch (input) {
        case 'w': // key up
            highlight_line = highlight_line - 1;
            if (highlight_line < 0)
                highlight_line = 6;
            highlight_line = (highlight_line) % 7;

            break;

        case 's': // key down
            highlight_line = highlight_line + 1;
            highlight_line = (highlight_line) % 7;
            break;
        }
        window_clear();
        std::cout << "w - up, s - down, d - next" << std::endl;
    }
    window_clear();
    return highlight_line + 1;
}