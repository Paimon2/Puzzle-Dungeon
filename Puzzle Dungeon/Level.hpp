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
    // Base blocks
    sf::Texture brickTexture;
    sf::Texture crateTexture;
    sf::Texture frogTexture;
    sf::Texture pressurePlateTexture;
    sf::Texture rockTexture;
    sf::Texture leftDoorTexture;
    sf::Texture rightDoorTexture;


    // Used throughout different levels
    Tile frogSprite;
    // Doors
    Tile leftDoor;
    Tile rightDoor;

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

        Tile leftDoor;
        leftDoor.type = TileType::CustomCodeOnInteraction;
       // leftDoor.clickCallback = [](){ showNextLevel(); };
        leftDoor.tilesprite.setPosition(10, 380);
        leftDoor.tilesprite.setTexture(leftDoorTexture);
        tiles.push_back(leftDoor);
        
        Tile rightDoor;
        rightDoor.type = TileType::Normal;
        // rightDoor.clickCallback = [](){ showPreviousLevel(); (will we?) };
        rightDoor.tilesprite.setPosition(1320, 380);
        rightDoor.tilesprite.setTexture(rightDoorTexture);
        tiles.push_back(rightDoor);

        switch(levelNumber) {

        case 1: {

            Tile toPush;
            toPush.type = TileType::Normal;
            toPush.tilesprite.setPosition(530, 500);
            toPush.tilesprite.setTexture(pressurePlateTexture);
            tiles.push_back(toPush);

            Tile rockSprite;
            rockSprite.type = TileType::Normal;
            rockSprite.tilesprite.setPosition(930, 500);
            rockSprite.usesPhysics = true;
            rockSprite.tilesprite.setTexture(rockTexture);
            tiles.push_back(rockSprite);

            
            frogSprite.type = TileType::Normal;
            frogSprite.tilesprite.setPosition(930, 700);
            frogSprite.tilesprite.setTexture(frogTexture);
            tiles.push_back(frogSprite);

            // Boundaries for entry
            for (int i = 0; i < 8; i++) {
                Tile toPush;
                toPush.type = TileType::Normal;
                toPush.tilesprite.setPosition(700, i * 47 + 430);
                toPush.tilesprite.setTexture(crateTexture);
                tiles.push_back(toPush);
            }
            break;
                }

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
			
            
            leftDoorTexture.loadFromFile(Utilities::getResourcePath() + "Textures//DoorLeft.png");
            rightDoorTexture.loadFromFile(Utilities::getResourcePath() + "Textures//DoorRight.png");


            brickTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Brick.png");
            crateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Crate.png");
            frogTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Frog.png");
            rockTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Rock2.png");


            pressurePlateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//PressurePlate.png");

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
        for(Tile &tile : tiles) {
            /* WARNING!
             * Having checkIntersect() here could have
             * unintended consequences that may potientally
             * break very important physics functionality.
             */
            tile.checkIntersect(characterSprite, tiles);
            tile.checkMouseOver(window);
        }
        for(Tile tile : tiles){

            tile.draw(window, characterSprite);
        }
	}
	
};



#endif
