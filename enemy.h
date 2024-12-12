#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>

#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
private:
	sf::Texture enemyTexture;
	sf::Sprite enemySprite;
	sf::SoundBuffer attackSoundBuffer;
	sf::Sound attackSound;
public:
	Enemy(int);
	int energy;
	bool performSetup();
	bool checkIfHit(sf::Vector2i);
	bool takeDamage(int);
	void draw(sf::RenderWindow*);
};

#endif