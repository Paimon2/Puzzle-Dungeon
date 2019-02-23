/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/

#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <iostream>
#include <string.h>
#include <SFML/Graphics.hpp>



class Character { 
public:
	void setPosition(float x, float y);
	void setTexture(const std::string &texturePath);
	void checkMovement();
	sf::Sprite sprite;
private:
	sf::Texture texture;
};

void Character::setPosition(float x, float y) {
	sprite.setPosition(x, y);
}

void Character::setTexture(const std::string &texturePath) {
	texture.loadFromFile(texturePath);
	sprite.setTexture(texture);
}


void Character::checkMovement() {
	/*
	I opted for this instead of a switch-case statement as it allows
	multiple keys to be registered at the same time as well as reducing
	movement lag.
	*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		sprite.move(0.f, -5.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		sprite.move(-5.f, 0.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		sprite.move(0.f, 5.f);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		sprite.move(5.f, 0.f);
	}

}


/*

	GameInstance class checks for input, switch case (A, W, D, S)
	Tells Character class which one was pressed in a sf::Keyboard::Key value, 
	Character moves according to key

	*/

#endif