#include <string>
#include <ncurses.h>
#include <unistd.h>
#include <vector>

#include "game.h"
#include "sprites.h"

WINDOW* wnd;

Game::Game() {
    wnd = initscr();
    cbreak();
    noecho();
    clear();
    refresh();
    keypad(wnd, true);
    nodelay(wnd, true);
    curs_set(0);
    // box(wnd, 0, 0);
}

void Game::run() {
    int bottom, right;
    getmaxyx(wnd, bottom, right);
    Boundary game_area(0, bottom, 0, right);
    SpriteManager sprite_manager(game_area);

    position ship_pos = {right/2, bottom-10};

    std::vector<std::vector<char>> ship_body = {
        {' ', ' ', '|', ' ', ' '},
        {' ', '/', '_', '\\', ' ' },
        {'|', ' ', ' ', ' ', '|'},
        {'|', '-', '-', '-', '|'}
    };

    Sprite ship(ship_body, ship_pos);

    int frame_tick = 0;
    while(1) {
        bool exit = false;
        int keyboard_in = wgetch(wnd);

        for(auto s : sprite_manager.getSprites()) {
            s.clear();
        }

        if(frame_tick % 10 == 0) {
            sprite_manager.updateScreen();
        }


        for(auto s : sprite_manager.getSprites()) {
            s.draw();
        }

        ship.clear();

        switch(keyboard_in) {
            case 'q':
            exit = true;
            break;
            case KEY_LEFT:
            ship.moveLeft();
            break;
            case KEY_RIGHT:
            ship.moveRight();
            break;
            default:
            break;
        }

        ship.draw();

        refresh();
        
        if(exit) break;
        
        frame_tick++;
        usleep(10000);
    }
}

Game::~Game() {
    endwin();
}


// case KEY_UP:
// ship.moveUp(1);
// break;
// case KEY_DOWN:
// ship.moveDown(1);
// break;