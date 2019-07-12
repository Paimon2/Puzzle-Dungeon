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
#include "Helpers.hpp"
#include "Level.hpp"


class Character { 
public:
	void setPosition(float x, float y);
	void setTexture(const std::string &texturePath);
	void checkMovement(Level &currentLevel);
	void draw(sf::RenderWindow &window, sf::View &view);
	sf::Sprite sprite;
private:
	sf::Texture texture;
};

inline void Character::draw(sf::RenderWindow &window, sf::View &view) {
	window.draw(sprite);
}

void Character::setPosition(float x, float y) {
	sprite.setPosition(x, y);
}

/*
* @brief Set the texture of a character
* @param texturePath The path to the texture
*/
void Character::setTexture(const std::string &texturePath) {
	texture.loadFromFile(texturePath);
	sprite.setTexture(texture);
}

/*
* @brief Move the character according to which key(s) are held down
* @param currentLevel A reference pointer to the current level
*/
void Character::checkMovement(Level &currentLevel) {
	/*
	I opted for this instead of a switch-case statement as it allows
	multiple keys to be registered at the same time as well as reducing
	movement lag.
	- Omar
	*/
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if(!Helpers::checkCharacterCollision(
			currentLevel,
			sf::Vector2f(sprite.getPosition().x,
            sprite.getPosition().y - 1.5f)
			))
		{
            sprite.move(0.f, -1.5f);
		}
		
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if(!Helpers::checkCharacterCollision(
			currentLevel,
            sf::Vector2f(sprite.getPosition().x - 1.5f,
			sprite.getPosition().y
			)))
		{
            sprite.move(-1.5f, 0.f);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if(!Helpers::checkCharacterCollision(
			currentLevel,
			sf::Vector2f(sprite.getPosition().x,
            sprite.getPosition().y + texture.getSize().y + 1.5f
			)))
		{
            sprite.move(0.f, 1.5f);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if(!Helpers::checkCharacterCollision(
			currentLevel,
            sf::Vector2f(sprite.getPosition().x + 2.f,
			sprite.getPosition().y
			)))
		{
            sprite.move(1.5f, 0.f);
		}
	}

}


#endif
