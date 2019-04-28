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

#ifdef MACOS
#include "MacTools/ResourcePath.hpp"
#endif


namespace Helpers {

	

/*
* @brief Check if there is a collision in a given coordinate pair
* @param currentLevel A reference pointer to the current level
* @param coords Check if there's a collision in these coordinates
* @return true if collision with any tiles, else false
*/
	bool checkCharacterCollision(Level &currentLevel, sf::Vector2f coords){
		// Iterate over all tiles, and tell us if we have a collision with any
		for(Tile &tile : currentLevel.tiles) {
			if (tile.tilesprite.getGlobalBounds().contains(coords)) {
				return true;
			}	
		}

		return false;
	}


}


#endif