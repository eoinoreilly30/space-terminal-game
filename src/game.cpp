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
    int in_char;
    bool exit = false;

    vec2i ship_pos = {20, 20};
    char** ptr;

    Ship ship(ptr, 4, 5, ship_pos);

    while(1) {
        in_char = wgetch(wnd);

        ship.clear();

        switch(in_char) {
            case 'q':
            exit = true;
            break;
            case KEY_UP:
            case 'w':
            ship.incY();
            break;
            case KEY_DOWN:
            case 's':
            ship.decY();
            break;
            case KEY_LEFT:
            case 'a':
            ship.decX();
            break;
            case KEY_RIGHT:
            case 'd':
            ship.incX();
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