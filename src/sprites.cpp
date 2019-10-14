#include "sprites.h"
#include <ncurses.h>
#include <stdlib.h>

void Sprite::draw() {
	for(unsigned int row=0; row<body.size(); row++) {
		for(unsigned int col=0; col<body[row].size(); col++) {
			mvaddch(pos.y+row, pos.x+col, body[row][col]);
		}
	}
}

void Sprite::clear() {
	for(unsigned int row=0; row<body.size(); row++) {
		for(unsigned int col=0; col<body[row].size(); col++) {
			mvaddch(pos.y+row, pos.x+col, ' ');
		}
	}
}

position Sprite::getPosition() {
	return pos;
}

void Sprite::moveRight() {
	pos.x += 2;
}

void Sprite::moveLeft() {
	pos.x -= 2;
}

void Sprite::moveDown() {
	pos.y += 1;
}

int Boundary::getWidth() {
	return right - left;
}

int Boundary::getHeight() {
	return top - bottom;
}

bool Boundary::isInside(position sprite_pos) {
	return sprite_pos.x >= left 
	&& sprite_pos.x <= right
	&& sprite_pos.y <= bottom
	&& sprite_pos.y >= top;
}

std::vector<Sprite> SpriteManager::getSprites() {
	return sprites_displayed;
}

void SpriteManager::removeSprite(size_t i) {
	sprites_displayed.erase(sprites_displayed.begin() + i);
}

void SpriteManager::updateScreen() {
	for(size_t i=0; i<sprites_displayed.size(); i++) {
		if(!boundary.isInside(sprites_displayed.at(i).getPosition()))
			removeSprite(i);
		sprites_displayed.at(i).moveDown();
	}

	std::vector<std::vector<char>> rock_body = {{'O'}};
	int rock_x_pos = rand() % boundary.getWidth();
	position rock_pos = {rock_x_pos, 0};
	Sprite rock(rock_body, rock_pos);

	sprites_displayed.push_back(rock);
}
