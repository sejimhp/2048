
# include <Siv3D.hpp>

# include "Game.h"

void Main()
{
	Window::Resize(403, 403);
	Game game;
	int state = 0;

	while (System::Update())
	{
		switch (state){
		case 0:
			game.run();
			game.draw();
			state = game.check();
		case 1:
			;
		}
	}
}
