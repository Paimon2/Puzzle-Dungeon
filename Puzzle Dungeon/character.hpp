#include <iostream>
#include <string.h>
#include <SFML/Graphics.hpp>

class Character { 
public:
	void setPosition(float x, float y);
	void setTexture(std::string myTexture);
	void move(sf::Keyboard::Key key);
	sf::Sprite mySprite;
private:
	sf::Texture texture;
};

void Character::setPosition(float x, float y) {
	mySprite.setPosition(x, y);
}

void Character::setTexture(std::string MyTexture) {
	texture.loadFromFile(MyTexture);
	mySprite.setTexture(texture);
}


void Character::move(sf::Keyboard::Key key) {
	sf::Vector2f movement(0.f, 0.f);
	switch(key) {
		case sf::Keyboard::A:
			mySprite.move(-5.f, 0.f);
			break;
		case sf::Keyboard::W:
			mySprite.move(0.f, -5.f);
			break;
		case sf::Keyboard::S:
			mySprite.move(0.f, 5.f);
			break;
		case sf::Keyboard::D:
			mySprite.move(5.f, 0.f);
			break;
		default:
			break;
	}

}


/*

	GameInstance class checks for input, switch case (A, W, D, S)
	Tells Character class which one was pressed in a sf::Keyboard::Key value, 
	Character moves according to key

	*/
