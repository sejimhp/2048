#include <Siv3D.hpp>

class Game {
	int map[4][4];
public:
	Game();

	void run();
	void draw();
	int check();
};