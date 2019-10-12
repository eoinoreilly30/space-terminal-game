#include <iostream>
#include <ncurses.h>

using namespace std;

int main()
{
    initscr();
    cbreak();
    noecho();
    clear();
    refresh();

    move(5, 5);

	std::string text = "Hello world!";
	for(int i = 0; i < text.size(); i++) {
	    addch(text[i]);
	    addch(' ');
	}

refresh();

    while(1);
    return 0;
}
