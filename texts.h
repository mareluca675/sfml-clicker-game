#include <SFML/Graphics.hpp>

#ifndef TEXTS_H
#define TEXTS_H

class Texts {
private:
	sf::Font font;
	void setUpText(sf::Text*, sf::Vector2f);
public:
	Texts();

	sf::Text energyText;
	sf::Text timeText;
	sf::Text endGameWonText;
	sf::Text endGameTimeText;
	sf::Text endGameSpaceText;

	bool perfromSetup();
	void drawInGameTexts(sf::RenderWindow*, sf::Time, int);
	void drawEndGameTexts(sf::RenderWindow*, sf::Time);
};

#endif