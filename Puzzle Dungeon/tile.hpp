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
#include <string.h>



class Tile {
public:
	void setFeatures(std::string texture, float x, float y);
	sf::Sprite tilesprite;
private:
	sf::Texture t; 
	
};

//Set the texture, x and y position all at once. 
void Tile::setFeatures(std::string texture, float x, float y) {
	t.loadFromFile(texture);
	tilesprite.setTexture(t);
	tilesprite.setPosition(x, y);
}

#endif
