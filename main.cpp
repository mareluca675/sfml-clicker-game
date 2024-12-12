#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "gameWorld.h"
#include <iostream>

int main() {
	while (true) {
		GameWorld world = GameWorld();

		if (!world.performSetup()) {
			std::cout << "ERROR: Couldn't perfrom setup.";
			return 1;
		}

		if (!world.runGame()) {
			return 0;
		}
	}

	return 0;
}