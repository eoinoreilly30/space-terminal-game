#include <vector>
#include <cstddef>

typedef struct {
	int x;
	int y;
} position;

class Sprite {
protected:
	std::vector<std::vector<char>> body;
	position pos;

public:
	Sprite(std::vector<std::vector<char>> body, position pos) : body(body), pos(pos) {}
	void draw();
	void clear();
	void moveDown();
	void moveLeft();
	void moveRight();
	position getPosition();
};

// class Ship : Sprite {
// public:
// 	Ship(std::vector<std::vector<char>> body, position pos) : Sprite(body, pos) {}
// 	virtual void moveLeft();
// 	virtual void moveRight();
// };

// class Rock : Sprite {
// public:
// 	Rock(std::vector<std::vector<char>> body, position pos) : Sprite(body, pos) {}
// 	virtual void moveDown();
// };

class Boundary {
private:
	int top;
	int bottom;
	int left;
	int right;

public:
	Boundary(int t, int b, int l, int r) : top(t), bottom(b), left(l), right(r) {}
	int getWidth();
	int getHeight();
	bool isInside(position);
};

class SpriteManager {
private:
	Boundary boundary;
	std::vector<Sprite> sprites_displayed;

public:
	SpriteManager(Boundary b) : boundary(b) {}
	void updateScreen();
	void removeSprite(size_t);
	std::vector<Sprite> getSprites();
};