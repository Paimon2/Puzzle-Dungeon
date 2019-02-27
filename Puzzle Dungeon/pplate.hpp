/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/


#ifndef _PPLATE_HPP_
#define _PPLATE_HPP_

#include <iostream>
#include <functional>
#include "tile.hpp"
#include "character.hpp"



class PressurePlate {
public:
	void setFeatures(std::string MyTexture, int x, int y);
	void checkIntersect(sf::Sprite SpriteTwo, std::function<void()>func);
private:
	Tile pressureplate;
};

void PressurePlate::setFeatures(std::string MyTexture, int x, int y) {
	pressureplate.setFeatures(MyTexture, x, y);
}


void PressurePlate::checkIntersect(sf::Sprite SpriteTwo, std::function<void()>func) {
	if (pressureplate.tilesprite.getGlobalBounds().intersects(SpriteTwo.getGlobalBounds())) {
		func();
	}
	else {
		// Do nothing
	}
}

#endif