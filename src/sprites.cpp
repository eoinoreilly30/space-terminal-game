#include "sprites.h"
#include <ncurses.h>

// possibly overload the + operator
void Sprite::incX(int amount) {
	pos.x += amount;
}

void Sprite::decX(int amount) {
	pos.x -= amount;
}

void Sprite::incY(int amount) {
	pos.y += amount;
}

void Sprite::decY(int amount) {
	pos.y -= amount;
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