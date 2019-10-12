#include "sprites.h"
#include <ncurses.h>

Sprite::Sprite(char **_body, int _rows, int _cols, vec2i _pos) {
	body = _body;
	rows = _rows;
	cols = _cols;
	pos = _pos;
}

// possibly overload the + operator
void Sprite::incX() {
	pos.x += 1;
}

void Sprite::decX() {
	pos.x -= 1;
}

void Sprite::incY() {
	pos.y += 1;
}

void Sprite::decY() {
	pos.y -= 1;
}

void Sprite::draw() {
	for(int row=0; row<rows; row++) {
        for(int col=0; col<cols; col++) {
            mvaddch(pos.y+row, pos.x+col, body[row][col]);
        }
    }
}

void Sprite::clear() {
	for(int row=0; row<rows; row++) {
        for(int col=0; col<cols; col++) {
            mvaddch(pos.y+row, pos.x+col, ' ');
        }
    }
}
