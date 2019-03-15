#include <iostream>
#include <functional>
#include "tile.hpp"


class PressurePlate : Tile {
public:
	void checkIntersect(sf::Sprite SpriteTwo, std::function<void()>func);
private: 
};



void PressurePlate::checkIntersect(sf::Sprite SpriteTwo, std::function<void()>func) {
	if (tilesprite.getGlobalBounds().intersects(SpriteTwo.getGlobalBounds())) { 
		try {
			func();
		}
		catch (...) {
			std::cerr << ": pplate.hpp : no callback set\r" + __LINE__ + '\n';
		}
	} 
}

