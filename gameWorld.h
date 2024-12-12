#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <iostream>

#include "enemy.h"
#include "texts.h"

#ifndef GAMEWORLD_H
#define GAMEWORLD_H

class GameWorld {
	private:
		bool isGameOver;
		int damage;
		sf::Texture backroundTexture;
		sf::Sprite backround;
		sf::Time time;
		Enemy enemy;
		Texts texts;
		bool loadBackround();
	public:
		GameWorld();
		bool performSetup();
		bool runGame();
};

#endif