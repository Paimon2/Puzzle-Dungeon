#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>

class Tile {
public:
	void setFeatures(std::string texture, int x, int y);
	sf::Sprite tilesprite;
private:
	sf::Texture t; 
	
};

//Set the texture, x and y position all at once. 
void Tile::setFeatures(std::string texture, int x, int y) {
	t.loadFromFile(texture);
	tilesprite.setTexture(t);
	tilesprite.setPosition(x, y);
}
