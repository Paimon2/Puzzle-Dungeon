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
#include <functional>
#include <vector>
#include <string.h>
#include "Utilities.hpp"
#include "Question.hpp"
#include <cmath>
#include <thread>

enum TileType {
    Normal = 0,
    PressurePlate = 1,
    Door = 2,
    Viewable = 3,
    Chest = 4,
    CustomCodeOnInteraction = 5
};

class Tile {
public:
    void setFeatures(std::string texture, float x, float y);
    void checkIntersect(sf::Sprite &spriteTwo, std::vector<Tile> &tileList);
    void draw(sf::RenderWindow& window, std::vector<Tile> &tileList, sf::Sprite& characterSprite);
    void checkMouseOver(sf::RenderWindow& window);
    void testChange();
    TileType type;
    Tile();
    std::function<void()> clickCallback;
    /*
    *** SPECIAL CONDITIONAL MEMBERS ***
    */
    sf::Text clickOnMeMessageText;
    sf::Sprite viewableImage;
    std::function<void()> customCodeOnInteraction;
    sf::Sprite tilesprite;
    std::vector<DialogueScreen> dialogueScreens;
    bool isMouseOver = false;
    void setCollideCallback(std::function<void()> callback);

    bool isPickedUp;
    bool pickable;
    /*
    *** PHYSICS MEMBERS ***
    */
    // If this is true, the tile will move around if the player pushes it.
    bool usesPhysics = false;
    /*
    * How fast the tile is moving in either the X or Y direction.
    * By the way: velocity = speed

    * directionalVelocities[0] = positive velocity in the X direction
    * directionalVelocities[1] = positive velocity in the Y direction
    * directionalVelocities[2] = negative velocity in the X direction
    * directionalVelocities[3] = negative velocity in the Y direction
    * These are FLOATING POINT ARRAYS. Do not perform integer maths
    * without casting! We don't want warnings.
    */
    float directionalVelocities[5] = {0, 0, 0, 0, 0};
    std::function<void()> collideCallback;
private:
    bool standTimeout = true;
    sf::Texture t;

};


Tile::Tile() {
    isPickedUp = false;
    pickable = false;
}

void Tile::testChange()
{
tilesprite.setPosition(45, 50);
}


//Set the texture, x and y position all at once.
void Tile::setFeatures(std::string texture, float x, float y) {
    t.loadFromFile(texture);
    tilesprite.setTexture(t);
    tilesprite.setPosition(x, y);
}


void Tile::draw(sf::RenderWindow& window, std::vector<Tile> &tileList, sf::Sprite& characterSprite) {


    sf::Vector2i mousePos = sf::Mouse::getPosition();
    sf::Vector2f pixelPos = window.mapPixelToCoords(mousePos);

    /* We are an object that can be picked up,
    * and the cursor is currently over us.
    */

    if(type == TileType::Normal) {
        tilesprite.setColor(sf::Color(255, 255, 255, 255));
        window.draw(tilesprite);
        return;
    }

  if (isMouseOver && type == TileType::CustomCodeOnInteraction){

      if(Utilities::euclideanDistance(tilesprite.getPosition(),
                                      sf::Vector2f(characterSprite.getPosition().x,
                                                   characterSprite.getPosition().y)) > 100.f) {

           clickOnMeMessageText.setFont(Utilities::basicFont);
           tilesprite.setColor(sf::Color(255, 255, 255, 255));
          clickOnMeMessageText.setString("Move closer to interact");
          clickOnMeMessageText.setColor(sf::Color::Yellow);
          clickOnMeMessageText.setCharacterSize(20);
          clickOnMeMessageText.setPosition(mousePos.x - 250, mousePos.y - 170);
          window.draw(tilesprite);
          window.draw(clickOnMeMessageText);
          //return;
        }
      else{
           clickOnMeMessageText.setFont(Utilities::basicFont);
           tilesprite.setColor(sf::Color(200, 200, 200, 255));
          clickOnMeMessageText.setString("Click to interact");
          clickOnMeMessageText.setCharacterSize(20);
          clickOnMeMessageText.setColor(sf::Color::Green);

          clickOnMeMessageText.setPosition(mousePos.x - 250, mousePos.y - 170);
          window.draw(tilesprite);
          window.draw(clickOnMeMessageText);

          if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
          {
              try {
                  clickCallback();

              } catch (...) {

              }
                return;

          }
         // return;
      }

      }

    if(isPickedUp && pickable) {

        for(Tile &currentTile : tileList){
            sf::Vector2f coords = tilesprite.getPosition();
            if (currentTile.tilesprite.getGlobalBounds().contains(coords)) {
                if(tilesprite.getGlobalBounds() == currentTile.tilesprite.getGlobalBounds())
                    continue;
                if(currentTile.type == TileType::PressurePlate)
                    continue;
                tilesprite.setPosition(mousePos.x - 290, mousePos.y - 167);
                clickOnMeMessageText.setColor(sf::Color(255, 0, 0, 255));
                tilesprite.setColor(sf::Color(255, 255, 255, 200));

                clickOnMeMessageText.setString("Cannot place here");
                clickOnMeMessageText.setCharacterSize(20);
                clickOnMeMessageText.setPosition(mousePos.x - 250, mousePos.y - 170);
                window.draw(tilesprite);
                window.draw(clickOnMeMessageText);
                return;
            }
        }


        if(Utilities::euclideanDistance(tilesprite.getPosition(),
                                        sf::Vector2f(characterSprite.getPosition().x,
                                                     characterSprite.getPosition().y)) > 100.f
                                        && pickable && isPickedUp) {
    tilesprite.setPosition(mousePos.x - 290, mousePos.y - 167);
    clickOnMeMessageText.setColor(sf::Color(255, 200, 0, 255));
    tilesprite.setColor(sf::Color(255, 255, 255, 200));

    clickOnMeMessageText.setString("Move closer to place");
    clickOnMeMessageText.setCharacterSize(20);
    clickOnMeMessageText.setPosition(mousePos.x - 250, mousePos.y - 170);
    window.draw(tilesprite);
    window.draw(clickOnMeMessageText);
    return;
    }
        else if(pickable){
            tilesprite.setPosition(mousePos.x, mousePos.y);
            tilesprite.setPosition(mousePos.x - 290, mousePos.y - 167);
            clickOnMeMessageText.setString("Left click to place");
            clickOnMeMessageText.setCharacterSize(20);
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                isPickedUp = false;
                tilesprite.setPosition(mousePos.x - 290, mousePos.y - 167);
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
            }
            clickOnMeMessageText.setPosition(mousePos.x - 250, mousePos.y - 170);
            clickOnMeMessageText.setColor(sf::Color(0, 255, 0, 255));
            tilesprite.setColor(sf::Color(255, 255, 255, 200));
            window.draw(tilesprite);
            window.draw(clickOnMeMessageText);
            return;
        }

    }

    if (isMouseOver && pickable) {

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (Utilities::euclideanDistance(characterSprite.getPosition(),
                                            tilesprite.getPosition())
                                            < 100.f) {
                isPickedUp = true;
                std::this_thread::sleep_for(std::chrono::milliseconds(200));
            }
        }

        clickOnMeMessageText.setFont(Utilities::basicFont);
        clickOnMeMessageText.setCharacterSize(14);
        clickOnMeMessageText.setFillColor(sf::Color::White);
        clickOnMeMessageText.setPosition(mousePos.x - 250, mousePos.y - 170);

        if (Utilities::euclideanDistance(characterSprite.getPosition(),
                                        tilesprite.getPosition())
                                        > 50.f) {

            clickOnMeMessageText.setString("Move closer to interact");
            clickOnMeMessageText.setCharacterSize(20);
            window.draw(tilesprite);
            window.draw(clickOnMeMessageText);
            return;
        }


        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            try {
                 clickCallback();
            }
           catch(std::bad_function_call){
               std::cerr << "[CRITICAL] Bad function call to Tile (clickCallback())" << std::endl;
           }
        }

        clickOnMeMessageText.setString("Click to interact");
        clickOnMeMessageText.setCharacterSize(20);
        tilesprite.setColor(sf::Color(200, 200, 200, 200));
        window.draw(tilesprite);
        window.draw(clickOnMeMessageText);
    }

    else {
        tilesprite.setColor(sf::Color(255, 255, 255));
        window.draw(tilesprite);
    }

}

void Tile::checkIntersect(sf::Sprite &spriteTwo, std::vector<Tile> &tileList) {

    /*
    * @brief If the speed in any direction is greater than 0,
    * it will gradually decrease. Otherwise, it will be set to 0
    * anyway.
    */


    if (Utilities::euclideanDistance(tilesprite.getPosition(), spriteTwo.getPosition()) < 25)

      {


          try {

              collideCallback();
              return;
          }

          catch(...) {
              // Do nothing
              return;
          }

      }

    for (int i = 0; i < sizeof(directionalVelocities); i++) {
        directionalVelocities[i] = std::fmax(0, directionalVelocities[i] - 0.2f);
    }


    // Move the sprite based on the directional velocities.
    // If they are 0, this doesn't do anything.
    // ALSO, check for collisions.
    for (Tile &tile : tileList) {


        // Ensure we're not doing collision detection
        // against ourselves

        if (tile.tilesprite.getGlobalBounds()
            == tilesprite.getGlobalBounds()) {
            continue;
        }


        /* If we collide with something else, transfer half our energy to the other tile.
        * This means we also lose half our energy.
         */
        if (tile.tilesprite.getGlobalBounds().intersects(tilesprite.getGlobalBounds())) {

            if (!tile.usesPhysics) {
                tile.directionalVelocities[2] = directionalVelocities[0] / 2.0f;
                tile.directionalVelocities[1] = directionalVelocities[3] / 2.0f;
                tile.directionalVelocities[3] = directionalVelocities[1] / 2.0f;
                tile.directionalVelocities[0] = directionalVelocities[2] / 2.0f;
            }

            if (tile.usesPhysics) {
                for (int i = 0; i < sizeof(directionalVelocities); i++) {
                    directionalVelocities[i] /= 1.8f;
                }

            }


        }


    }



    tilesprite.move(directionalVelocities[0] - directionalVelocities[2],
        directionalVelocities[1] - directionalVelocities[3]);




            if (!usesPhysics)
                return;
                /*
                * Calculate all this centre/differences stuff.
                * We use this later to determine which side of the
                * tile sprite was collided with.
                * Reference:
                * https://www.gamedev.net/forums/topic/
                * 662182-sfml-bounding-box-but-how-to-implment-collision-with-side-detection/
                * (MODIFIED)
                * (sorry for the double lines - we have an 80 column standard!)
                */
                sf::IntRect tileRect = tilesprite.getTextureRect();
                sf::IntRect playerRect = spriteTwo.getTextureRect();

                int tileXCentre = (tileRect.left + (tileRect.width / 2));
                int tileYCentre = (tileRect.top + (tileRect.height / 2));

                int playerXCentre = (playerRect.left + (playerRect.width / 2));
                int playerYCentre = (playerRect.top + (playerRect.height / 2));

                int xDifference = playerXCentre - tileXCentre;
                int yDifference = playerYCentre - tileYCentre;

                int positiveX = 0;
                int positiveY = 0;

                /*
                positive X = to the right
                positive Y = to the top
                */

                float xAxisDistance = spriteTwo.getPosition().x - tilesprite.getPosition().x;
                float yAxisDistance = tilesprite.getPosition().y - spriteTwo.getPosition().y;


                  directionalVelocities[4] = xAxisDistance / 8;
                  directionalVelocities[0] = -xAxisDistance / 8;
                  directionalVelocities[1] = xAxisDistance / 8;
                  directionalVelocities[2] = fabsf(xAxisDistance / 5);


}

inline void Tile::checkMouseOver(sf::RenderWindow &window)
{
    /* If we're not an object on the floor, don't
    * bother doing all these calculations.
    */

    /* Detect if the cursor is intersecting the tile.
    * Note: The cursor has a size of exactly 1x1 pixels.
    */

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    sf::Vector2f pixelPos = window.mapPixelToCoords(mousePos);


    // Super ugly collision detection. But it works.
    // Detect if the mouse is intersecting the tile.
    if (pixelPos.x <= tilesprite.getPosition().x + tilesprite.getTextureRect().width
        && pixelPos.x + 1 >= tilesprite.getPosition().x && pixelPos.y <= tilesprite.getPosition().y +
        tilesprite.getTextureRect().height &&
        pixelPos.y + 1 >= tilesprite.getPosition().y)
    {
        isMouseOver = true;
    }

    else {
        isMouseOver = false;
    }
}






/*
* @brief When the user collides with this tile,
* the lambda below will be executed.
* @param callback lambda to be executed
*/
inline void Tile::setCollideCallback(std::function<void()> callback)
{
    collideCallback = callback;
}



#endif
