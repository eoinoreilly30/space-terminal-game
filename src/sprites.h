typedef struct {
	int x;
	int y;
} position;

class Sprite {
private:
	char *body;
	const int rows;
	const int cols;
	position pos;

public:
	Sprite(char body[][10], const int rows, const int cols, position pos) :
	body(body),
	rows(rows),
	cols(cols),
	pos(pos) {}
	void incX(int);
	void decX(int);
	void incY(int);
	void decY(int);
	void draw();
	void clear();
};