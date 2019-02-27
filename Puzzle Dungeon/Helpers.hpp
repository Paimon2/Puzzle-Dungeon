/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/

#ifndef _HELPERS_HPP_
#define _HELPERS_HPP_

#include <vector>
#include "SFML/Graphics.hpp"
#include "Level.hpp"
#include "tile.hpp"

namespace Helpers {

	bool areSpritesColliding(sf::Sprite &sprite1, sf::Sprite &sprite2) {
		return (sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds()));
	}

	bool checkCharacterCollision(Level &currentLevel, sf::Vector2f coords){
		for(Tile &tile : currentLevel.tiles) {
			if (tile.tilesprite.getGlobalBounds().contains(coords)) {
				return true;
			}	
		}

		return false;
	}


}


#endif