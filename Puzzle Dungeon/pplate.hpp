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
	} else {
		// Do nothing
	}
}

