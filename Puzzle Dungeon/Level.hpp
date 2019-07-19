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
    sf::Texture redCrateTexture;
    sf::Texture redPressurePlateTexture;


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
        case 2: {

      		Tile pPlate; 
      		pPlate.type = TileType::PressurePlate;
      		pPlate.tilesprite.setPosition(683, 400);
      		pPlate.tilesprite.setTexture(pressurePlateTexture);
      		tiles.push_back(pPlate);

      		Tile rock;
      		rock.type = TileType::Normal;
      		rock.tilesprite.setPosition(800, 400);
      		rock.tilesprite.setTexture(rockTexture);
      		tiles.push_back(rock);

      		Tile rockSpriteTwo;
            rockSpriteTwo.type = TileType::Normal;
            rockSpriteTwo.tilesprite.setPosition(950, 165);
            rockSpriteTwo.usesPhysics = true;
            rockSpriteTwo.tilesprite.setTexture(rockTexture);
            tiles.push_back(rockSpriteTwo);

      		for (int i = 0; i < 3; i++) { // WITHIN THIS LOOP, '30' REPRESENTS THE WIDTH + HEIGHT OF CRATES
      		    switch(i) {
      				case 0:
      					for (int bord = 0; bord < 3; bord++) {
      						Tile crate;
      						crate.type = TileType::Normal;
      						crate.tilesprite.setTexture(crateTexture);
      						crate.tilesprite.setPosition(660 + bord * 65, 100);
      						tiles.push_back(crate);
      					}
      					break;
      				case 1: {
      					for (int midrow = 0; midrow < 2; midrow++) {
      						Tile crate;
      						crate.type = TileType::Normal;
      						crate.tilesprite.setTexture(crateTexture);
      						crate.tilesprite.setPosition(660 + midrow * 130, 165); // SECOND ROW POSITIONS
      						tiles.push_back(crate);
      					}
      					Tile pPlate; 
      					pPlate.type = TileType::PressurePlate;
      					pPlate.tilesprite.setPosition(725, 165); // MIDDLE ROW PRESSURe PLATE
      					pPlate.tilesprite.setTexture(pressurePlateTexture);
      					tiles.push_back(pPlate);     					
      					break; 
      				}

      				case 2: 
      					for (int bord2 = 0; bord2 < 3; bord2++) {
      						Tile crate;
      						crate.type = TileType::Normal;
      						crate.tilesprite.setTexture(crateTexture);
      						crate.tilesprite.setPosition(660 + bord2 * 65, 230); // THIRD ROW POSITIONS
      						tiles.push_back(crate);
      					}

      					break;
      				

      			}
      		for (int i = 0; i < 10; i++) {
      			Tile crateTwo;
      			crateTwo.type = TileType::Normal;
      			crateTwo.tilesprite.setTexture(crateTexture);
      			crateTwo.tilesprite.setPosition(225, 100 + (65 * i));
      			tiles.push_back(crateTwo);
      		}

      		}
      		break;
        }
        case 3: {
        	for (int i = 0; i < 3; i++) { // Sets the Positions of the Three Gray Pressure Plates
        		Tile pPlateGray;
        		pPlateGray.type = TileType::PressurePlate;
        		pPlateGray.tilesprite.setTexture(pressurePlateTexture);
        		switch(i) {
        			case 0:
        				pPlateGray.tilesprite.setPosition(675, 100);
        				break;
        			case 1: 
        				pPlateGray.tilesprite.setPosition(295, 100);
        				break;
        			case 2:
        				pPlateGray.tilesprite.setPosition(675, 690);
        				break;
        		} 
        		tiles.push_back(pPlateGray);
        	}

        	for (int i = 0; i < 4; i++) {
        		switch(i) {
        			case 0:
        				for (int line = 0; line < 9; line++) {
        					Tile crate;
      						crate.type = TileType::Normal;
      						crate.tilesprite.setTexture(crateTexture);
      						crate.tilesprite.setPosition(200, 90 + 75 * line); //Line of crates covering door
      						tiles.push_back(crate);
        				}
        				break;
        			case 1:
        				for (int line = 0; line < 5; line++) {
        					Tile crate;
        					crate.type = TileType::Normal;
        					crate.tilesprite.setTexture(crateTexture);
        					crate.tilesprite.setPosition(390, 90 + 75 * line); // Line first to the right of ^^
        					tiles.push_back(crate);
        				}
        				break;
        			case 2:
        				for (int line = 0; line < 9; line++) {
        					Tile crate;
      						crate.type = TileType::Normal;
      						crate.tilesprite.setTexture(crateTexture);
      						crate.tilesprite.setPosition(580, 90 + 75 * line); // Second line
      						tiles.push_back(crate);
      					}
      					break;
      				case 3:													// for the columns of three that are opposing each other
      					for (int line = 0; line < 3; line++) { 
      						Tile crate;
      						crate.type = TileType::Normal;
      						crate.tilesprite.setTexture(crateTexture);
      						crate.tilesprite.setPosition(780, 90 + 75 * line); 
      						tiles.push_back(crate);
      					}
      					
      					for (int lowline = 0; lowline < 2; lowline++) {
      						Tile crate;
      						crate.type = TileType::Normal;
      						crate.tilesprite.setTexture(crateTexture);
      						crate.tilesprite.setPosition(780, 696 - lowline * 75); 
      						tiles.push_back(crate);
      					}
      					break;
      			}
      		}
        	
        	for (int i = 0; i < 2; i++) {
        		Tile crate;
      			crate.type = TileType::Normal;
   				crate.tilesprite.setTexture(crateTexture);
   				crate.tilesprite.setPosition(290 + (195 * i), 175); // The 'blockades' on the pressure plates + red crates
   				tiles.push_back(crate);
        	}
        	for (int i = 0; i < 2; i++) {			
        		Tile crate;
        		crate.type = TileType::Normal;
        		crate.tilesprite.setTexture(crateTexture);
        		switch(i) {
        			case 0:
        				crate.tilesprite.setPosition(685, 603);
        				break;
        			case 1:
        				crate.tilesprite.setPosition(490, 390);
        				break;
        		}
        		tiles.push_back(crate);
    		}

    		for (int i = 0; i < 2; i++) {
    			switch(i) {
    				case 0: 
    					for (int topLine = 0; topLine < 3; topLine++) {
    						Tile crate;
        					crate.type = TileType::Normal;
        					crate.tilesprite.setTexture(crateTexture);
    						crate.tilesprite.setPosition(285 + topLine * 85, 615);
    						tiles.push_back(crate);
    					}
    					break;
    				case 1:
    					Tile sideCrate;
    					sideCrate.type = TileType::Normal;
    					sideCrate.tilesprite.setTexture(crateTexture);
    					sideCrate.tilesprite.setPosition(455, 700);
    					tiles.push_back(sideCrate);
    					break;
    			}
    		}

    		for (int i = 0; i < 2; i++) { // Place the Red Crates
    			Tile redCrate;
    			redCrate.type = TileType::Normal;
    			redCrate.tilesprite.setTexture(redCrateTexture);
    			switch(i) {
    				case 0:
    					redCrate.tilesprite.setPosition(490, 95);
    					break;
    				case 1:
    					redCrate.tilesprite.setPosition(490, 265);
    					break;
    			}
    			tiles.push_back(redCrate);
    		}

    		for (int i = 0; i < 2; i++) {
    			Tile redPressurePlate;
    			redPressurePlate.type = TileType::PressurePlate;
    			redPressurePlate.tilesprite.setTexture(redPressurePlateTexture);
    			switch(i) {
    				case 0:
    					redPressurePlate.tilesprite.setPosition(295, 700);
    					break;
    				case 1:
    					redPressurePlate.tilesprite.setPosition(370, 700);
    					break;
    			}
    			tiles.push_back(redPressurePlate);
    		}

    		for (int i = 0; i < 3; i++) {
    			Tile rockSprite;
    			rockSprite.type = TileType::Normal;
    			rockSprite.tilesprite.setTexture(rockTexture);
    			switch(i) {
    				case 0:
    					rockSprite.tilesprite.setPosition(950, 409);
    					break;
    				case 1:
    					rockSprite.tilesprite.setPosition(920, 650);
    					break;
    				case 2:
    					rockSprite.tilesprite.setPosition(500 ,520);

    			}
    			tiles.push_back(rockSprite);
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
        case 2: {
       		leftDoorTexture.loadFromFile(Utilities::getResourcePath() + "Textures//DoorLeft.png");
            rightDoorTexture.loadFromFile(Utilities::getResourcePath() + "Textures//DoorRight.png");


            brickTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Brick.png");
            crateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Crate.png");
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
        
        case 3:
       		leftDoorTexture.loadFromFile(Utilities::getResourcePath() + "Textures//DoorLeft.png");
            rightDoorTexture.loadFromFile(Utilities::getResourcePath() + "Textures//DoorRight.png");


            brickTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Brick.png");
            crateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Crate.png");
            redCrateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Crate_Tile_Red_.png");
            rockTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Rock2.png");


            pressurePlateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//PressurePlate.png");
            redPressurePlateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//redPressurePlate.png");

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
