#include "enemy.h"
#include <iostream>

Enemy::Enemy(int e) {
	energy = e;
}

bool Enemy::performSetup() {
	if (!enemyTexture.loadFromFile("sfml-assets/enemy.png")) {
		std::cout << "ERROR: Could not load enemy texture.";
		return false;
	}

	enemySprite.setTexture(enemyTexture);
	enemySprite.setPosition(sf::Vector2f(225, 400));
	enemySprite.scale(sf::Vector2f(2, 2));

	if (!attackSoundBuffer.loadFromFile("sfml-assets/damage.ogg")) {
		std::cout << "ERROR: Could not load enemy sound buffer.";
		return false;
	}

	attackSound.setBuffer(attackSoundBuffer);
	return true;
}

void Enemy::draw(sf::RenderWindow* window) {
	window->draw(enemySprite);
}

bool Enemy::checkIfHit(sf::Vector2i mousePosition) {
	float enemyMinX = enemySprite.getGlobalBounds().left;
	float enemyMaxX = enemySprite.getGlobalBounds().width + enemyMinX;

	float enemyMinY = enemySprite.getGlobalBounds().top;
	float enemyMaxY = enemySprite.getGlobalBounds().height + enemyMinY;

	return (enemyMinX <= mousePosition.x && mousePosition.x <= enemyMaxX && enemyMinY <= mousePosition.y && mousePosition.y <= enemyMaxY);
}

bool Enemy::takeDamage(int damage) {
	energy -= damage;
	attackSound.play();
	return (energy <= 0);
}