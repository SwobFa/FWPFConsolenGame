#include "pch.h"
#include <fstream>
#include "Game.h"

using namespace std;

int main() 
{
	while (true) {
		Game game;
		short mapNumber = game.ChooseMap();
		game.StartGame(mapNumber);
	}

	return 0;
}
