#include "gameWorld.h"
#include "enemy.h"

GameWorld::GameWorld(): enemy(100), texts() {
    isGameOver = false;
	damage = 10;
}

bool GameWorld::loadBackround() {
	if (!backroundTexture.loadFromFile("sfml-assets/background.png")) {
		std::cout << "ERROR: Could not load backround image.";
		return false;
	}

	backround.setTexture(backroundTexture);
    backround.scale(sf::Vector2f(1.6, 2.25));
	return true;
}

bool GameWorld::performSetup() {
	isGameOver = false;
    enemy = Enemy(100);
    texts = Texts();
	return loadBackround() && enemy.performSetup() && texts.perfromSetup();
}

bool GameWorld::runGame() {
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML Game");
    sf::Clock clock;
    clock.restart();

    while (window.isOpen()) {
        if (!isGameOver)
            time = clock.getElapsedTime();

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                return false;
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (!isGameOver) {
                    if (enemy.checkIfHit(sf::Mouse::getPosition(window))) {
                        isGameOver = enemy.takeDamage(damage);
                    }
                }
            }
            if (event.type == sf::Event::KeyPressed) {
                if (isGameOver && sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    return true;
                }
            }
        }

        window.clear();
        window.draw(backround);

        if (isGameOver) {
            texts.drawEndGameTexts(&window, time);
        }
        else {
            enemy.draw(&window);
            texts.drawInGameTexts(&window, time, enemy.energy);
        }

        window.display();
    }

    return false;
}