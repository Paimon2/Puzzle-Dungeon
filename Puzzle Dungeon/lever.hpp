#include "tile.hpp"
#include <iostream>
#include <functional>

class Lever {
public:
	void setFeatures(std::string MyTexture, int x, int y);
	void checkIntersect(sf::Sprite SpriteTwo, std::function<void()>func);
private: 
	Tile lever;
};

void Lever::setFeatures(std::string MyTexture, int x, int y) {
	lever.setFeatures(MyTexture, x, y);
}


void Lever::checkIntersect(sf::Sprite SpriteTwo, std::function<void()>func) {
	if (lever.tilesprite.getGlobalBounds().intersects(SpriteTwo.getGlobalBounds())) { 
		func();
	} else {
		// Do nothing
	}
}
