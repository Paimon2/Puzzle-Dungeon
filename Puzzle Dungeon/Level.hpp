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
#include "Tile.hpp"


class Level {
private:
	sf::Texture brickTexture;
	sf::Texture levelBackgroundTexture;
	sf::Sprite levelBackground;
	int levelNum;
public:
	std::vector<Tile> tiles;
	
	inline void scaleEverything(sf::Vector2u windowSize) {
		tiles.clear();
		genLevel(levelNum);
		generateBorders(windowSize);

		float ScaleX = (float)windowSize.x / levelBackgroundTexture.getSize().x;
		float ScaleY = (float)windowSize.y / levelBackgroundTexture.getSize().y;

		levelBackground.setScale(ScaleX, ScaleY);
	}

	inline void genLevel(int levelNumber) {


        Tile toPush;
        toPush.type = TileType::Normal;
        toPush.tilesprite.setPosition(630, 500);
        toPush.usesPhysics = true;
        toPush.tilesprite.setTexture(brickTexture);
        tiles.push_back(toPush);

		// Initial RHS/right-hand-side top side of wall
		for (int i = 0; i < 17; i++) {
			// Small gap
			if (i == 10 || i == 11)
				continue;
			Tile toPush;
			toPush.type = TileType::Normal;
			toPush.tilesprite.setPosition(1200, i * 47);
			toPush.tilesprite.setTexture(brickTexture);
			tiles.push_back(toPush);
		}
		
		// Boundaries for entry
		for (int i = 0; i < 10; i++) {
			Tile toPush;
			toPush.type = TileType::Normal;
			toPush.tilesprite.setPosition(i * 47 + 730, 700);
			toPush.tilesprite.setTexture(brickTexture);
			tiles.push_back(toPush);
		}
	}

	inline void generateBorders(sf::Vector2u windowSize = sf::Vector2u(1024, 818)) {

		

        // Top: left-right
        for (int i = 0; i < windowSize.x / 45; i++) {
            Tile brickTile;
            brickTile.tilesprite.setTexture(brickTexture);
            brickTile.tilesprite.setPosition(i * (int)brickTexture.getSize().x - i*2, -20);
            tiles.push_back(brickTile);
        }

        // Bottom: left-right
        for (int i = 0; i < windowSize.x / 45; i++) {
            Tile brickTile;

            brickTile.tilesprite.setTexture(brickTexture);
            brickTile.tilesprite.setPosition(i * (int)brickTexture.getSize().x - i * 2, windowSize.y - 20);
            tiles.push_back(brickTile);
        }

        // Left-down

        for (int i = 0; i < (int)windowSize.y / 45; i++) {
            Tile brickTile;
            brickTile.tilesprite.setTexture(brickTexture);
            brickTile.tilesprite.setPosition(-40, i * (int)brickTexture.getSize().y - 20);
            tiles.push_back(brickTile);
        }

        // Right-down

        for (int i = 0; i < (int)windowSize.y / 45; i++) {
            Tile brickTile;
            brickTile.tilesprite.setTexture(brickTexture);
            brickTile.tilesprite.setPosition(windowSize.x - 10, i * (int)brickTexture.getSize().y - 20);
            tiles.push_back(brickTile);
        }

	}

	inline void loadLevel(int levelNumber) {
		levelNum = levelNumber;
		switch (levelNumber) {

		case 1: {
			
            brickTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Brick.png");
			
            levelBackgroundTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Background1.png");
			levelBackgroundTexture.setRepeated(true);
			levelBackground.setTexture(levelBackgroundTexture);
			
			float ScaleX = (float)1366 / levelBackgroundTexture.getSize().x;
			float ScaleY = (float)818 / levelBackgroundTexture.getSize().y;    

			levelBackground.setScale(ScaleX, ScaleY);      

			tiles.clear();
			genLevel(levelNumber);
			generateBorders();
			
		}

		}


	}

	inline void drawTiles(sf::RenderWindow &window, sf::Sprite &characterSprite) {
		window.draw(levelBackground);
        for(Tile tile : tiles) {
            /* WARNING!
             * Having checkIntersect() here could have
             * unintended consequences that may potientally
             * break very important physics functionality.
             */
            tile.checkIntersect(characterSprite, tiles);
            tile.draw(window, characterSprite);
        }
	}
	
};



#endif
