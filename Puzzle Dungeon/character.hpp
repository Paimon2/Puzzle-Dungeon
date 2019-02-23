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
	void move(sf::Keyboard::Key key);
	sf::Sprite mySprite;
private:
	sf::Texture texture;
};

void Character::setPosition(float x, float y) {
	mySprite.setPosition(x, y);
}

void Character::setTexture(const std::string &texturePath) {
	texture.loadFromFile(texturePath);
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

#endif