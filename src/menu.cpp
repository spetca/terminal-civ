#include "../inc/game.h"
#include "../inc/menu.h"
#include "../inc/termcolor.hpp"
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void
Menu::input_cursor()
{
    cout << "          :" << termcolor::blink;
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
    constexpr auto menu_entry_text = R"(
          1. Start New Game
          2. Resume Game
          3. View Highscores
          4. Info
          5. Exit
    )";

    // splash screen + menu
    draw_splash();
    cout << termcolor::blue << sp << greetings_text << gamename_text << endl;
    cout << termcolor::reset;

    // main menu
    cout << termcolor::red << menu_entry_text << endl;
    cout << termcolor::reset;

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

    cout << termcolor::green << termcolor::bold << splash << endl;
    cout << termcolor::reset;
}

void
Menu::main_menu_input()
{
    input_cursor();
    char c;
    cin >> c;

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

    vector<string> tribe_selection{
        "Select a Tribe  | Tribe Starts With",   "-------------------------------------",
        "| 1. Tribe1     |   Perk 1          |", "| 2. Tribe2     |   Perk 1          |",
        "| 2. Tribe2     |   Perk 1          |", "| 3. Tribe3     |   Perk 1          |",
        "| 4. Tribe4     |   Perk 1          |", "| 5. Tribe5     |   Perk 1          |",
        "| 6. Tribe6     |   Perk 1          |", "-------------------------------------"
    };

    vector<string> difficulty_selection{ "Select Difficulty",
                                         "-------------------------------------",
                                         "1",
                                         "2",
                                         "3",
                                         "4",
                                         "5" };

    // changes to make it an arrow pick and highlight
    int highlight_line = 0;
    char input;
    while (input != 'd') {
        for (int i = 0; i < tribe_selection.size(); i++) {
            if (i == highlight_line + 2)
                cout << termcolor::on_yellow << termcolor::red;

            cout << tribe_selection[i] << endl;

            if (i == highlight_line + 2)
                cout << termcolor::reset;
        }
        input = cin.get();
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
        cout << "w - up, s - down, d - next" << endl;
    }
    int tribe = highlight_line + 1;
    window_clear();

    // changes to make it an arrow pick and highlight
    highlight_line = 0;
    input = 'a';
    while (input != 'd') {
        for (int i = 0; i < difficulty_selection.size(); i++) {
            if (i == highlight_line + 2)
                cout << termcolor::on_yellow << termcolor::red;

            cout << difficulty_selection[i] << endl;

            if (i == highlight_line + 2)
                cout << termcolor::reset;
        }
        input = cin.get();
        switch (input) {
        case 'w': // key up
            highlight_line = highlight_line - 1;
            if (highlight_line < 0)
                highlight_line = 6;
            highlight_line = (highlight_line) % 6;

            break;

        case 's': // key down
            highlight_line = highlight_line + 1;
            highlight_line = (highlight_line) % 6;
            break;
        }
        window_clear();
        cout << "w - up, s - down, d - next" << endl;
    }
    window_clear();
    int difficulty = highlight_line + 1;
    cout << tribe << ", " << difficulty << endl;
    // Game game(input, diff);
    // game.run();
}

void
Menu::show_score()
{
    cout << "High score" << endl;
}