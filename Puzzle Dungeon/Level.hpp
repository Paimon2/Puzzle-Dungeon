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
   
    // Coloured Textures
    sf::Texture redCrateTexture;
    sf::Texture redPressurePlateTexture;
    sf::Texture greenCrateTexture;
    sf::Texture greenPressurePlateTexture;
    sf::Texture blueCrateTexture;
    sf::Texture bluePressurePlateTexture;


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
      		pPlate.tilesprite.setPosition(683, 400); // FIRST PRESSURE PLATE - MOVES firstMoveCrate;
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
      						crate.tilesprite.setPosition(660 + bord * 65, 100); // FIRST LINE OF BOX OF CRATES 
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
      					Tile centerPlate; 							// MOVES secondMoveCrate
      					centerPlate.type = TileType::PressurePlate;
      					centerPlate.tilesprite.setPosition(725, 165); // CENTER PRESSURE PLATE
      					centerPlate.tilesprite.setTexture(pressurePlateTexture);
      					tiles.push_back(centerPlate);     					
      					break; 
      				}

      				case 2: 
      					for (int bord2 = 0; bord2 < 2; bord2++) {
      						Tile crate;
      						crate.type = TileType::Normal;
      						crate.tilesprite.setTexture(crateTexture);
      						crate.tilesprite.setPosition(660 + bord2 * 130, 230); // THIRD ROW POSITIONS
      						tiles.push_back(crate);
      					}

      					Tile firstMoveCrate; // MOVED BY pPlate
      					firstMoveCrate.type = TileType::Normal;
      					firstMoveCrate.tilesprite.setTexture(crateTexture);
      					firstMoveCrate.tilesprite.setPosition(725, 230);
      					tiles.push_back(firstMoveCrate);



      					break;
      				

      			}
      		for (int i = 0; i < 9; i++) {
      			Tile crateTwo;
      			crateTwo.type = TileType::Normal;
      			crateTwo.tilesprite.setTexture(crateTexture);
      			crateTwo.tilesprite.setPosition(225, 100 + (65 * i));
      			tiles.push_back(crateTwo);
      		}

      			Tile secondMoveCrate;			//MOVED BY CenterPlate - at the bottom of the line concealing door
      			secondMoveCrate.type = TileType::Normal;
      			secondMoveCrate.tilesprite.setTexture(crateTexture);
      			secondMoveCrate.tilesprite.setPosition(225, 100 + (65 * 9));
      			tiles.push_back(secondMoveCrate);


      		}
      		break;
        }
        case 3: {

            Tile pPlateOne; 
            pPlateOne.type = TileType::PressurePlate;
            pPlateOne.tilesprite.setTexture(pressurePlateTexture);
            pPlateOne.tilesprite.setPosition(675, 100);
            tiles.push_back(pPlateOne);

            // SECOND PRESSURE PLATE, AT TOP OF ENTRY -- 
            Tile pPlateTwo;
            pPlateTwo.type = TileType::PressurePlate;
            pPlateTwo.tilesprite.setTexture(pressurePlateTexture);
            pPlateTwo.tilesprite.setPosition(675, 690);
            tiles.push_back(pPlateTwo);

            // RED PPLATE, LEFT, 
            Tile redPlateThree;
            redPlateThree.type = TileType::PressurePlate;
            redPlateThree.tilesprite.setTexture(redPressurePlateTexture);
            redPlateThree.tilesprite.setPosition(295, 700);
            tiles.push_back(redPlateThree);

            //RED PPLATE, RIGHT
            Tile redPlateFour;
            redPlateFour.type = TileType::PressurePlate;
            redPlateFour.tilesprite.setTexture(redPressurePlateTexture);
            redPlateFour.tilesprite.setPosition(370, 700);
            tiles.push_back(redPlateFour);

            // FINAL PRESSURE PLATE, AT TOP ON FAR LEFT
            Tile pPlateFive;
            pPlateFive.type = TileType::PressurePlate;
            pPlateFive.tilesprite.setTexture(pressurePlateTexture);
            pPlateFive.tilesprite.setPosition(295, 100);
            tiles.push_back(pPlateFive);
            // MOVABLE CRATES 
            // First movable crate, at entry
            Tile firstMoveCrate;
            firstMoveCrate.type = TileType::Normal;
            firstMoveCrate.tilesprite.setTexture(crateTexture);
            firstMoveCrate.tilesprite.setPosition(685, 603);
            tiles.push_back(firstMoveCrate);

            // Second crate, in middle of first wall of crates
            Tile secondMoveCrate;
            secondMoveCrate.type = TileType::Normal;
            secondMoveCrate.tilesprite.setTexture(crateTexture);
            secondMoveCrate.tilesprite.setPosition(580, 390);
            tiles.push_back(secondMoveCrate);

            // Third crate, below third gray pressure plate (far left)
            Tile thirdMoveCrate;
            thirdMoveCrate.type = TileType::Normal;
            thirdMoveCrate.tilesprite.setTexture(crateTexture);
            thirdMoveCrate.tilesprite.setPosition(290, 175);
            tiles.push_back(thirdMoveCrate);


            // Fourth crate, below lower red crate
            Tile fourthMoveCrate;
            fourthMoveCrate.type = TileType::Normal;
            fourthMoveCrate.tilesprite.setTexture(crateTexture);
            fourthMoveCrate.tilesprite.setPosition(490, 340);
            tiles.push_back(fourthMoveCrate); 

           // Fifth crate, below higher red crate
            Tile fifthMoveCrate;
            fifthMoveCrate.type = TileType::Normal;
            fifthMoveCrate.tilesprite.setTexture(crateTexture);
            fifthMoveCrate.tilesprite.setPosition(490, 170);
            tiles.push_back(fifthMoveCrate);

            // Sixth crate, above left red crate 
            Tile sixthMoveCrate;
            sixthMoveCrate.type = TileType::Normal;
            sixthMoveCrate.tilesprite.setTexture(crateTexture);
            sixthMoveCrate.tilesprite.setPosition(370, 625);
            tiles.push_back(sixthMoveCrate);

            //Seventh crate, above right red crate
            Tile seventhMoveCrate;
            seventhMoveCrate.type = TileType::Normal;
            seventhMoveCrate.tilesprite.setTexture(crateTexture);
            seventhMoveCrate.tilesprite.setPosition(295, 625);
            tiles.push_back(seventhMoveCrate);

            // Eighth crate, in the middle of line of crates that conceal left door
            Tile eighthMoveCrate;
            eighthMoveCrate.type = TileType::Normal;
            eighthMoveCrate.tilesprite.setTexture(crateTexture);
            eighthMoveCrate.tilesprite.setPosition(200, 465);
            tiles.push_back(eighthMoveCrate);


           // FIRST WALL OF CRATES FROM RIGHT, EXCLUDING ONE CRATE (SECOND MOVEABLE CRATE)

            for (int line = 0; line < 5; line++) {
              Tile crate;
              crate.type = TileType::Normal;
              crate.tilesprite.setTexture(crateTexture);
              crate.tilesprite.setPosition(580, 90 + 75 * line); // Second line
              tiles.push_back(crate);
            }

            for (int i = 0; i < 4; i++) {
              Tile crate;
              crate.type = TileType::Normal;
              crate.tilesprite.setTexture(crateTexture);
              crate.tilesprite.setPosition(580, 465 + (75 * i)); 
              tiles.push_back(crate);
            }

           // END OF FIRST LINE FROM RIGHT

            //LAST LINE OF CRATES, CONCEALING LEFT DOOR, EXCLUDING EIGHTH CRATE

            for (int line = 0; line < 5; line++) {
              Tile crate;
              crate.type = TileType::Normal;
              crate.tilesprite.setTexture(crateTexture);
              crate.tilesprite.setPosition(200, 90 + 75 * line); //Line of crates covering door
              tiles.push_back(crate);
            }
      
            for (int bLine = 0; bLine < 3; bLine++) {
              Tile crate;
              crate.type = TileType::Normal;
              crate.tilesprite.setTexture(crateTexture);
              crate.tilesprite.setPosition(200, 696 - bLine * 75);
              tiles.push_back(crate);
            }

            // END LAST LINE OF CRATES

            // LINE OF CRATES THAT SEPARATE LEFT GRAY PPLATE FROM RED PPLATES

            for (int line = 0; line < 5; line++) {
              Tile crate;
              crate.type = TileType::Normal;
              crate.tilesprite.setTexture(crateTexture);
              crate.tilesprite.setPosition(390, 90 + 75 * line); 
              tiles.push_back(crate);
            }

            // END WALL 

            // OPPOSING COLUMNS OF THREE CRATES AT ENTRY
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

            // END OPPOSING COLUMNS OF THREE CRATES AT ENTRY


            // SECTION SURROUNDING RED PRESSURE PLATES
            for (int sideWall = 0; sideWall < 2; sideWall++) {
              Tile sideCrate;
              sideCrate.type = TileType::Normal;
              sideCrate.tilesprite.setTexture(crateTexture);
              sideCrate.tilesprite.setPosition(455, 700 - sideWall * 75);
              tiles.push_back(sideCrate);
            }
            // END SECTION SURROUNDING RED PRESSURE PLATES
    	
            // Place the Red Crates
    		    for (int i = 0; i < 2; i++) { 
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
            // Place Rocks
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
        case 4: {

          // Green Crate Goes to Green Pressure Plate
          Tile greenCrate;
          greenCrate.type = TileType::Normal;
          greenCrate.tilesprite.setTexture(greenCrateTexture);
          greenCrate.tilesprite.setPosition(1180, 390); 
          tiles.push_back(greenCrate);

          // For Green Crate - Plate
          Tile greenPressurePlate;
          greenPressurePlate.type = TileType::PressurePlate;
          greenPressurePlate.tilesprite.setTexture(greenPressurePlateTexture);
          greenPressurePlate.tilesprite.setPosition(845, 390);
          tiles.push_back(greenPressurePlate);

          // Black Plate - activated by rock
          Tile blackPlate;
          blackPlate.type = TileType::PressurePlate;
          blackPlate.tilesprite.setTexture(pressurePlateTexture);
          blackPlate.tilesprite.setPosition(945, 190);
          tiles.push_back(blackPlate);

          // Right Red Crate
          Tile redCrateOne; 
          redCrateOne.type = TileType::Normal;
          redCrateOne.tilesprite.setTexture(redCrateTexture);
          redCrateOne.tilesprite.setPosition(685, 705);
          tiles.push_back(redCrateOne);
          // Left Red Crate
          Tile redCrateTwo;
          redCrateTwo.type = TileType::Normal;
          redCrateTwo.tilesprite.setTexture(redCrateTexture);
          redCrateTwo.tilesprite.setPosition(385, 705);
          tiles.push_back(redCrateTwo);
          // Right Red Plate
          Tile redPlateOne;
          redPlateOne.type = TileType::PressurePlate;
          redPlateOne.tilesprite.setTexture(redPressurePlateTexture);
          redPlateOne.tilesprite.setPosition(490, 190);
          tiles.push_back(redPlateOne);
          // Left Red Plate
          Tile redPlateTwo;
          redPlateTwo.type = TileType::PressurePlate;
          redPlateTwo.tilesprite.setTexture(redPressurePlateTexture);
          redPlateTwo.tilesprite.setPosition(325, 190);
          tiles.push_back(redPlateTwo);

          //Rock in centre
          Tile rockSprite;
          rockSprite.type = TileType::Normal;
          rockSprite.tilesprite.setTexture(rockTexture);
          rockSprite.tilesprite.setPosition(490, 405);
          tiles.push_back(rockSprite);
          // BEGIN : MOVABLE CRATES

          // First Crate - in front of Green Plate
          Tile crateOne;
          crateOne.type = TileType::Normal;
          crateOne.tilesprite.setTexture(crateTexture);
          crateOne.tilesprite.setPosition(760, 390); 
          tiles.push_back(crateOne);
          // Second crate - conceals gray pressure plate
          Tile crateTwo;
          crateTwo.type = TileType::Normal;
          crateTwo.tilesprite.setTexture(crateTexture);
          crateTwo.tilesprite.setPosition(845, 215); 
          tiles.push_back(crateTwo);
          // Third crate - above left red crate
          Tile crateThree;
          crateThree.type = TileType::Normal;
          crateThree.tilesprite.setTexture(crateTexture);
          crateThree.tilesprite.setPosition(385, 620); 
          tiles.push_back(crateThree);
          // Aboce right red crate
          Tile crateFour;
          crateFour.type = TileType::Normal;
          crateFour.tilesprite.setTexture(crateTexture);
          crateFour.tilesprite.setPosition(685, 620); 
          tiles.push_back(crateFour);
          // Below left red plate
          Tile crateFive;
          crateFive.type = TileType::Normal;
          crateFive.tilesprite.setTexture(crateTexture);
          crateFive.tilesprite.setPosition(325, 275); 
          tiles.push_back(crateFive);
          // Below right red plate
          Tile crateSix;
          crateSix.type = TileType::Normal;
          crateSix.tilesprite.setTexture(crateTexture);
          crateSix.tilesprite.setPosition(490, 275); 
          tiles.push_back(crateSix);
          // ib the middle of last row of crates; before left door
          Tile crateSeven;
          crateSeven.type = TileType::Normal;
          crateSeven.tilesprite.setTexture(crateTexture);
          crateSeven.tilesprite.setPosition(150, 405); 
          tiles.push_back(crateSeven); 
          

          // BEGIN: TRIVIAL CRATES (WALLS)

          // Wall surrounding entrance; path to green plate
          for (int i = 0; i < 6; i++) {
            int x = 1255 - (85 * i);
            for (int j = 0; j < 2; j++) {
              int y = 315 + (j * 155);
              Tile crate;
              crate.type = TileType::Normal;
              crate.tilesprite.setTexture(crateTexture);
              crate.tilesprite.setPosition(x, y);
              tiles.push_back(crate);
            }
          }

          // Row of crates at top of area
          for (int i = 0; i < 14; i++) {
            Tile crate;
            crate.type = TileType::Normal;
            crate.tilesprite.setTexture(crateTexture);
            crate.tilesprite.setPosition(1255 - (85 * i), 105); 
            tiles.push_back(crate);
          }

          // Back line of crates
         for (int line = 0; line < 4; line++) {
              Tile crate;
              crate.type = TileType::Normal;
              crate.tilesprite.setTexture(crateTexture);
              crate.tilesprite.setPosition(150, 105 + 75 * line); 
              tiles.push_back(crate);
            }
      
            for (int bLine = 0; bLine < 4; bLine++) {
              Tile crate;
              crate.type = TileType::Normal;
              crate.tilesprite.setTexture(crateTexture);
              crate.tilesprite.setPosition(150, 696 - bLine * 75);
              tiles.push_back(crate);
            }
          // End back line of crates

          // Crates beside red crates (bottom)
            for (int i = 0; i < 2; i++) {
              int x = 300 + (310 * i); 
              for (int j = 0; j < 2; j++) {
                x = x + (j * 165);
                Tile crate;
                crate.type = TileType::Normal;
                crate.tilesprite.setTexture(crateTexture);
                crate.tilesprite.setPosition(x, 705);
                tiles.push_back(crate);
              }
            }

          // Crates beside red plates (top)
            for (int i = 0; i < 2; i++) {
              int x = 240 + (170 * i); 
              for (int j = 0; j < 2; j++) {
                x = x + (j *170);
                Tile crate;
                crate.type = TileType::Normal;
                crate.tilesprite.setTexture(crateTexture);
                crate.tilesprite.setPosition(x, 190);
                tiles.push_back(crate);
              }
            }

          break;
          }
        case 5: {
          
          // Gray Pressure Plate in top-right corner - opens crateOne
          Tile grayPlateOne;
          grayPlateOne.type = TileType::PressurePlate;
          grayPlateOne.tilesprite.setTexture(pressurePlateTexture);
          grayPlateOne.tilesprite.setPosition(1231, 110);
          tiles.push_back(grayPlateOne);
          // The Only Red Crate here... opens crateThree
          Tile redCrate;
          redCrate.type = TileType::Normal;
          redCrate.tilesprite.setTexture(redCrateTexture);
          redCrate.tilesprite.setPosition(976, 185);
          tiles.push_back(redCrate); 
          // Opens crateFive
          Tile greenPlate; 
          greenPlate.type = TileType::PressurePlate;
          greenPlate.tilesprite.setTexture(greenPressurePlateTexture);
          greenPlate.tilesprite.setPosition(976, 335);
          tiles.push_back(greenPlate);

          Tile redPlate; 
          redPlate.type = TileType::PressurePlate;
          redPlate.tilesprite.setTexture(redPressurePlateTexture);
          redPlate.tilesprite.setPosition(976, 410);
          tiles.push_back(redPlate);

          // blueCrate goes on this - 
          Tile bluePlate; 
          bluePlate.type = TileType::PressurePlate;
          bluePlate.tilesprite.setTexture(bluePressurePlateTexture);
          bluePlate.tilesprite.setPosition(976, 485);
          tiles.push_back(bluePlate);
          // destroys crateTwo
          Tile grayPlateTwo;
          grayPlateTwo.type = TileType::PressurePlate;
          grayPlateTwo.tilesprite.setTexture(pressurePlateTexture);
          grayPlateTwo.tilesprite.setPosition(976, 560);
          tiles.push_back(grayPlateTwo);
          // Below first
          Tile grayPlateThree;
          grayPlateThree.type = TileType::PressurePlate;
          grayPlateThree.tilesprite.setTexture(pressurePlateTexture);
          grayPlateThree.tilesprite.setPosition(976, 635);
          tiles.push_back(grayPlateThree);
          // 
          Tile greenCrate;
          greenCrate.type = TileType::Normal;
          greenCrate.tilesprite.setTexture(greenCrateTexture);
          greenCrate.tilesprite.setPosition(976, 710);
          tiles.push_back(greenCrate);

          Tile blueCrate;
          blueCrate.type = TileType::Normal;
          blueCrate.tilesprite.setTexture(blueCrateTexture);
          blueCrate.tilesprite.setPosition(250, 713);
          tiles.push_back(blueCrate);

          Tile grayPlateFour;
          grayPlateFour.type = TileType::PressurePlate;
          grayPlateFour.tilesprite.setTexture(pressurePlateTexture);
          grayPlateFour.tilesprite.setPosition(100, 713);
          tiles.push_back(grayPlateFour);

          Tile rockSprite;
          //rockSprite.pickable = true;
          rockSprite.type = TileType::Normal;
          rockSprite.tilesprite.setTexture(rockTexture);
          rockSprite.tilesprite.setPosition(1165, 409);
          tiles.push_back(rockSprite);

          Tile rockSpriteTwo;
          //rockSprite.pickable = true;
          rockSpriteTwo.type = TileType::Normal;
          rockSpriteTwo.tilesprite.setTexture(rockTexture);
          rockSpriteTwo.tilesprite.setPosition(1165, 509);
          tiles.push_back(rockSpriteTwo);

          Tile rockSpriteThree;
          //rockSprite.pickable = true;
          rockSpriteThree.type = TileType::Normal;
          rockSpriteThree.tilesprite.setTexture(rockTexture);
          rockSpriteThree.tilesprite.setPosition(255, 120);
          tiles.push_back(rockSpriteThree);

           Tile rockSpriteFour;
          //rockSprite.pickable = true;
          rockSpriteFour.type = TileType::Normal;
          rockSpriteFour.tilesprite.setTexture(rockTexture);
          rockSpriteFour.tilesprite.setPosition(255, 580);
          tiles.push_back(rockSpriteFour);
 
          // MOVABLE CRATES: 

          // Front crate, at top - opened by grayPlateOne
          Tile crateOne; 
          crateOne.type = TileType::Normal;
          crateOne.tilesprite.setTexture(crateTexture);
          crateOne.tilesprite.setPosition(1051, 110);
          tiles.push_back(crateOne);
         
          // destroyed by grayPlateTwo - in front of blue crate
          Tile crateTwo;
          crateTwo.type = TileType::Normal;
          crateTwo.tilesprite.setTexture(crateTexture);
          crateTwo.tilesprite.setPosition(400, 713);
          tiles.push_back(crateTwo);
         
          // destroyed by redPlate - in front of blue crate 
          Tile crateThree;
          crateThree.type = TileType::Normal;
          crateThree.tilesprite.setTexture(crateTexture);
          crateThree.tilesprite.setPosition(475, 713);
          tiles.push_back(crateThree);

          //destroyed by grayPlateFour - release rocks
          Tile crateFour;
          crateFour.type = TileType::Normal;
          crateFour.tilesprite.setTexture(crateTexture);
          crateFour.tilesprite.setPosition(325, 110);
          tiles.push_back(crateFour);
         
          // Destroyed by greenPlate - release bottom rock
          Tile crateFive;
          crateFive.type = TileType::Normal;
          crateFive.tilesprite.setTexture(crateTexture);
          crateFive.tilesprite.setPosition(325, 563);
          tiles.push_back(crateFive);  

          // Destroyed by grayPlateThree
          Tile crateSix;
          crateSix.type = TileType::Normal;
          crateSix.tilesprite.setTexture(crateTexture);
          crateSix.tilesprite.setPosition(250, 335);
          tiles.push_back(crateSix);  
          // Destroyed by Blue Plate
          Tile crateSeven; 
          crateSeven.type = TileType::Normal;
          crateSeven.tilesprite.setTexture(crateTexture);
          crateSeven.tilesprite.setPosition(175, 335);
          tiles.push_back(crateSeven); 

          // BEGIN : WALLS OF CRATES: 1051, 

          // First wall of crates, blocking pressure plates
          for (int i = 0; i < 8; i++) {
            Tile crate;
            crate.type = TileType::Normal;
            crate.tilesprite.setTexture(crateTexture);
            crate.tilesprite.setPosition(1051, 185 + i * 75);
            tiles.push_back(crate);

          }
          // Row of crates above blue crate + gray plate
          for (int i = 0; i < 6; i++) {
            Tile crate;
            crate.type = TileType::Normal;
            crate.tilesprite.setTexture(crateTexture);
            crate.tilesprite.setPosition(100 + i * 75, 638);
            tiles.push_back(crate);
          }

          //Back Line of crates

          for (int i = 0; i < 3; i++) {
            Tile crate;
            crate.type = TileType::Normal;
            crate.tilesprite.setTexture(crateTexture);
            crate.tilesprite.setPosition(175, 110 + 75 * i);
            tiles.push_back(crate);
          }

          for (int i = 0; i < 3; i++) {
            Tile crate;
            crate.type = TileType::Normal;
            crate.tilesprite.setTexture(crateTexture);
            crate.tilesprite.setPosition(175, 563 - 75 * i);
            tiles.push_back(crate);
          }

          // Just below the red crate
          Tile crate;
          crate.type = TileType::Normal;
          crate.tilesprite.setTexture(crateTexture);
          crate.tilesprite.setPosition(976, 260);
          tiles.push_back(crate);

          // Series of crates forming the blockade... 
          for (int a = 0; a < 2; a++) {
            int x = 250 + (75 * a);
            for (int i = 0; i < 2; i++) {
              int y = 185 + (i * 225);
              for (int j = 0; j < 2; j++) {
                y = y + j * 75;
                Tile crate;
                crate.type = TileType::Normal;
                crate.tilesprite.setTexture(crateTexture);
                crate.tilesprite.setPosition(x, y);
                tiles.push_back(crate);
              }
            }
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
        
        case 3: {
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
        case 4: {
            leftDoorTexture.loadFromFile(Utilities::getResourcePath() + "Textures//DoorLeft.png");
            rightDoorTexture.loadFromFile(Utilities::getResourcePath() + "Textures//DoorRight.png");


            brickTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Brick.png");
            crateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Crate.png");
            frogTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Frog.png");
            rockTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Rock2.png");


            pressurePlateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//PressurePlate.png");
            redPressurePlateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//redPressurePlate.png");
            redCrateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Crate_Tile_Red_.png");
            greenCrateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//GreenCrate.png");
            greenPressurePlateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//GreenPressurePlate.png");

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
      case 5: 
            leftDoorTexture.loadFromFile(Utilities::getResourcePath() + "Textures//DoorLeft.png");
            rightDoorTexture.loadFromFile(Utilities::getResourcePath() + "Textures//DoorRight.png");


            brickTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Brick.png");
            crateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Crate.png");
            frogTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Frog.png");
            rockTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Rock2.png");


            pressurePlateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//PressurePlate.png");
            redPressurePlateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//redPressurePlate.png");
            redCrateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//Crate_Tile_Red_.png");
            greenCrateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//GreenCrate.png");
            greenPressurePlateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//GreenPressurePlate.png");
            blueCrateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//blueCrate.png");
            bluePressurePlateTexture.loadFromFile(Utilities::getResourcePath() + "Textures//bluePPlate.png");


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
