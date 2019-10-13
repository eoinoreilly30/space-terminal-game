#include <string>
#include <ncurses.h>
#include <unistd.h>

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
    box(wnd, 0, 0);
}

void Game::run() {
    position ship_pos = {20, 20};
    char ship_body[4][5] = {
        {' ', ' ', '|', ' ', ' '},
        {' ', '/', '_', '\\', ' ' },
        {'|', ' ', ' ', ' ', '|'},
        {'|', '-', '-', '-', '|'}
    };

    Sprite ship(ship_body, 4, 5, ship_pos);

    while(1) {
        bool exit = false;
        int keyboard_in = wgetch(wnd);

        ship.clear();

        switch(keyboard_in) {
            case 'q':
            exit = true;
            break;
            case KEY_UP:
            ship.incY(1);
            break;
            case KEY_DOWN:
            ship.decY(1);
            break;
            case KEY_LEFT:
            ship.decX(1);
            break;
            case KEY_RIGHT:
            ship.incX(1);
            break;
            default:
            break;
        }

        ship.draw();

        refresh();
        
        if(exit) break;
        
        usleep(10000);
    }
}

Game::~Game() {
    endwin();
}