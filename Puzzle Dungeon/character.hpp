#include <iostream>
#include <string.h>
#include <SFML/Graphics.hpp>

class Character { 
public:
	void setPosition(int x, int y);
	void setTexture(std::string MyTexture);
	void move(char key);
	sf::Sprite mySprite;
private:
	sf::Texture texture;
};

void Character::setPosition(int x, int y) {
	mySprite.setPosition(x, y);
}

void Character::setTexture(std::string MyTexture) {
	texture.loadFromFile(MyTexture);
	mySprite.setTexture(texture);
}


void Character::move(sf::Keyboard::Key key) {
	sf::Vector2f movement(0.f, 0.f);
	switch(key.code) {
		case 'A':
			mySprite.move(-5.f, 0.f);
			break;
		case 'W':
			mySprite.move(0.f, -5.f);
			break;
		case 'S':
			mySprite.move(0.f, 5.f);
			break;
		case 'D':
			mySprite.move(5.f, 0.f);
			break;
	}

}


/*

	GameInstance class checks for input, switch case (A, W, D, S)
	Tells Character class which one was pressed in a char value, 
	Character moves according to letter

	*/
