/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/


#ifndef _TILE_HPP_
#define _TILE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <functional>
#include <string.h>

enum TileType {
	Normal = 0,
	PressurePlate = 1,
	Door = 2,
};

class Tile {
public:
	void setFeatures(std::string texture, float x, float y);
	void setCollideCallback(std::function<void()> callback);
	void checkIntersect(sf::Sprite spriteTwo);
	TileType type;
	sf::Sprite tilesprite;
	/*
	If this is true, the tile will move around if the player
	pushes it.
	*/
	bool usesPhysics;
private:
	bool standTimeout;
	sf::Texture t; 
	std::function<void()> collideCallback;
};

//Set the texture, x and y position all at once. 
inline void Tile::setFeatures(std::string texture, float x, float y) {
	t.loadFromFile(texture);
	tilesprite.setTexture(t);
	tilesprite.setPosition(x, y);
}

void Tile::checkIntersect(sf::Sprite spriteTwo) {
	if (tilesprite.getGlobalBounds().intersects(spriteTwo.getGlobalBounds())) {
			try {
				if (!standTimeout) {
					standTimeout = true;
					collideCallback();
				}
			}
			catch (...) {
				// Do nothing; callback not set. THIS IS NORMAL.
			}
		}
	else {
		standTimeout = false;
	}
}


/*
* @brief When the user collides with this tile, 
* the lambda below will be executed.
* @param callback lambda to be executed
*/
inline void Tile::setCollideCallback(std::function<void()> callback)
{
	collideCallback = callback;
}



#endif
