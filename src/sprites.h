typedef struct {
    int x;
    int y;
} vec2i;

class Sprite {
private:
	char **body;
	int rows;
	int cols;
	vec2i pos;

public:
	Sprite(char**, int, int, vec2i);
	void incX();
	void decX();
	void incY();
	void decY();
	void draw();
	void clear();
};


class Ship : public Sprite {
private:
	char body[4][5] = {
		{' ', ' ', '|', ' ', ' '},
		{' ', '/', '_', '\\', ' ' },
		{'|', ' ', ' ', ' ', '|'},
		{'|', '-', '-', '-', '|'}
	};

public:
	Ship(char** body, int rows, int cols, vec2i pos) : Sprite(body, 4, 5, pos) {}
};