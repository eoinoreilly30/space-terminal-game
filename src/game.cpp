#include <string>
#include <ncurses.h>

#include "game.h"

WINDOW* wnd;

struct {
    vec2i pos;
    char disp_char;
} player;

Game::Game() {
    wnd = initscr();
    cbreak();
    noecho();
    clear();
    refresh();
    keypad(wnd, true);
    nodelay(wnd, true);
    curs_set(0);

    if(!has_colors()) {
        endwin();
        printf("ERROR: Terminal does not support color.\n");
        exit(1);
    }

    // start_color();
    // init_pair(1, COLOR_WHITE, COLOR_BLACK);
    // wbkgd(wnd, COLOR_PAIR(1));
    box(wnd, 0, 0);
}

void Game::run() {
    player.disp_char = '0';
    player.pos = {10, 5};

    mvaddch(player.pos.y, player.pos.x, player.disp_char);
    refresh();

    while(1);
}

Game::~Game() {
    endwin();
}
