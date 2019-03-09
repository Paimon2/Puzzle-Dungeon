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
#include <SFML/Graphics.hpp>
#include "tile.hpp"



class Level {
private:
	sf::Texture brickTexture;
	sf::Texture levelBackgroundTexture;
	sf::Sprite levelBackground;
public:
	std::vector<Tile> tiles;
	
	inline void scaleEverything(sf::Vector2u windowSize) {
		tiles.clear();
		generateBorders(windowSize);

		float ScaleX = (float)windowSize.x / levelBackgroundTexture.getSize().x;
		float ScaleY = (float)windowSize.y / levelBackgroundTexture.getSize().y;

		levelBackground.setScale(ScaleX, ScaleY);
	}

	inline void generateBorders(sf::Vector2u windowSize = sf::Vector2u(1024, 818)) {

		// Top: left-right
		for (int i = 0; i < windowSize.x / 45; i++) {
			Tile brickTile;
			brickTile.tilesprite.setTexture(brickTexture);
			brickTile.tilesprite.setPosition(i * brickTexture.getSize().x - i*2, -20);
			tiles.push_back(brickTile);
		}

		// Bottom: left-right
		for (int i = 0; i < windowSize.x / 45; i++) {
			Tile brickTile;
			brickTile.tilesprite.setTexture(brickTexture);
			brickTile.tilesprite.setPosition(i * brickTexture.getSize().x - i * 2, windowSize.y - 20);
			tiles.push_back(brickTile);
		}

		// Left: top-down

		for (int i = 0; i < windowSize.y / 45; i++) {
			Tile brickTile;
			brickTile.tilesprite.setTexture(brickTexture);
			brickTile.tilesprite.setPosition(-40, i * brickTexture.getSize().y - 20);
			tiles.push_back(brickTile);
		}

		// Right: top-down

		for (int i = 0; i < windowSize.y / 45; i++) {
			Tile brickTile;
			brickTile.tilesprite.setTexture(brickTexture);
			brickTile.tilesprite.setPosition(windowSize.x - 10, i * brickTexture.getSize().y - 20);
			tiles.push_back(brickTile);
		}

	}

	inline void loadLevel(int levelNumber) {
		
		switch (levelNumber) {

		case 1: {
			
			/* For each level, we will have different textures.
			Some of these may be the same as the previous level,
			but it is a design decision to reload all textures
			when a level is loaded.
			*/


			brickTexture.loadFromFile("Textures//brick.png");
			levelBackgroundTexture.loadFromFile("Textures//Lvl1Bckrnd.png");
			levelBackgroundTexture.setRepeated(true);
			levelBackground.setTexture(levelBackgroundTexture);
			
			float ScaleX = (float)1366 / levelBackgroundTexture.getSize().x;
			float ScaleY = (float)818 / levelBackgroundTexture.getSize().y;    

			levelBackground.setScale(ScaleX, ScaleY);      

			tiles.clear();

			generateBorders();
			
			
		}

		}


	}

	inline void drawTiles(sf::RenderWindow &window, sf::Shader &lightingShader) {
		window.draw(levelBackground);

		for (Tile tile : tiles) {
			window.draw(tile.tilesprite);
		}
	}
};
#endif