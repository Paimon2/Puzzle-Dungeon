/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/

#ifndef _LEVEL_HPP_
#define _LEVEL_HPP_

#include <vector>
#include "Character.hpp"

class Level {
protected:
	/*
	For Sam:
	You can implement these classes if you like in other files
	(Character.hpp, Tile.hpp)
	They should have a sprite, walking speed etc. It's up to you ;)
	std::vector<Tile> tiles;*/
	std::vector<Character> characters;
	
};
#endif