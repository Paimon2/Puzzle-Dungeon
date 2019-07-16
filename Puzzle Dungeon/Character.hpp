/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/

#ifndef _CHARACTER_HPP_
#define _CHARACTER_HPP_

#include <iostream>
#include <string.h>
#include <random>

#include <SFML/Graphics.hpp>
#include "Helpers.hpp"
#include "Level.hpp"


/* Whenever we do collision detection, we look around us for objects
 * we might potientally collide with. This defines the distance
 * in units (pixels?) we look for in *almost* each direction ("probe")
 * before allowing the character to move.
 *
 * It seems like each direction should have a different value.
 * TODO Play around with these values.
 */
#define MOVEMENT_PROBE_FACTOR_UP 0.01
#define MOVEMENT_PROBE_FACTOR_DOWN 30
#define MOVEMENT_PROBE_FACTOR_LEFT 0.01
#define MOVEMENT_PROBE_FACTOR_RIGHT 0.01

enum CharacterState {
    Idle = 0,
    Walking = 1
};

class Character {
public:
    void setPosition(float x, float y);
    void setTexture(const std::string &texturePath);
    void checkMovement(Level &currentLevel);
    void draw(sf::RenderWindow &window, sf::View &view);
    void checkShouldReset(sf::RenderWindow &gameWindow);
    void load();

    sf::Sprite sprite;
    // Textures for the character standing still
    std::vector<sf::Texture> idleTextures;
    // Textures for the character walking (obviously)
    std::vector<sf::Texture> walkingTextures;
    // What is the character doing?
    CharacterState state;
    // Let's say we're drawing the 4th out of 28 animation frames currently.
    // This is where we will store the 4 - the current frame index.
    // How many frames have elapsed since we started counting?
    // TODO: Reset this when it gets to 84.
    // Why? Because number_of_frames * 3 = 84
    // This gives us an animation 3x as long.
    int framesElapsed;
};

inline void Character::load() {
    state =  CharacterState::Idle;
    framesElapsed = 0;
    // Load idle textures
    for(int i = 1; i < 29; i++) {
        sf::Texture textureToPush;
        textureToPush.loadFromFile("Animations//CharacterIdle//"
                                   + std::to_string(i) + ".png");
        idleTextures.push_back(textureToPush);
    }
    // Load walking textures
    for(int i = 1; i < 8; i++) {
        sf::Texture textureToPush;
        textureToPush.loadFromFile("Animations//CharacterWalk//"
                                   + std::to_string(i) + ".png");
        walkingTextures.push_back(textureToPush);
    }


}

inline void Character::draw(sf::RenderWindow &window, sf::View &view) {

    // What is the character doing currently?
    switch(state) {

        case CharacterState::Walking:
        {
        framesElapsed = std::min(14, framesElapsed + 1);
        if(framesElapsed == 14)
            framesElapsed = 0;
        sprite.setTexture(walkingTextures.at(framesElapsed / 2));
        window.draw(sprite);
        break;
        }

        case CharacterState::Idle:
        {
            // Reset at 84, otherwise increment.
            std::random_device rd; // obtain a random number from hardware
            std::mt19937 eng(rd()); // seed the generator
            std::uniform_int_distribution<> distr(framesElapsed, framesElapsed + 1); // define the range

            framesElapsed = std::min(84, framesElapsed + 1);
            if(framesElapsed == 84) {
                framesElapsed = 0;
            }
            // The idle animations should be at 9 FPS.
          //  int targetFrameIndex = (int)(framesElapsed / 4);
            //std::cout << framesElapsed << std::endl;
            // Set the current sprite's texture to that frame.
            sprite.setTexture(idleTextures.at(framesElapsed / 3));
            window.draw(sprite);
        }
    }

}

void Character::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

/*
* @brief Set the texture of a character
* @param texturePath The path to the texture
*/
void Character::setTexture(const std::string &texturePath) {
    std::cerr << "[character::setTexture()] [WARN] Function deprecated and inoperative!" << std::endl;
}

/*
* @brief Move the character according to which key(s) are held down
* @param currentLevel A reference pointer to the current level
*/
void Character::checkMovement(Level &currentLevel) {
    /*
    I opted for this instead of a switch-case statement as it allows
    multiple keys to be registered at the same time as well as reducing
    movement lag.
    - Omar
    */
    // Reset back if no movement detected
    state = CharacterState::Idle;


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if(!Helpers::checkCharacterCollision(
            currentLevel,
            sf::Vector2f(sprite.getPosition().x - 15.f,
            sprite.getPosition().y - MOVEMENT_PROBE_FACTOR_UP))
            && !Helpers::checkCharacterCollision(currentLevel,
                                                 sf::Vector2f(
                                                 sprite.getPosition().x + 15.f,
                                                 sprite.getPosition().y - MOVEMENT_PROBE_FACTOR_UP)
                                                 )) {
            state = CharacterState::Walking;
            sprite.move(0.f, -3.f);
        }

    }


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if(!Helpers::checkCharacterCollision(
            currentLevel,
            sf::Vector2f(sprite.getPosition().x - MOVEMENT_PROBE_FACTOR_LEFT,
            sprite.getPosition().y - 15.f))
            && !Helpers::checkCharacterCollision(currentLevel,
                                                 sf::Vector2f(
                                                 sprite.getPosition().x - MOVEMENT_PROBE_FACTOR_LEFT,
                                                 sprite.getPosition().y + 15.f)
                                                 )) {
            state = CharacterState::Walking;
        {
            state = CharacterState::Walking;
            sprite.move(-3.f, 0.f);

        }
    }
}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if(!Helpers::checkCharacterCollision(
            currentLevel,
            sf::Vector2f(sprite.getPosition().x - 15.f,
            sprite.getPosition().y + MOVEMENT_PROBE_FACTOR_DOWN))
            && !Helpers::checkCharacterCollision(currentLevel,
                                                 sf::Vector2f(
                                                 sprite.getPosition().x + 15.f,
                                                 sprite.getPosition().y + MOVEMENT_PROBE_FACTOR_DOWN)
                                                 )) {
        {
            state = CharacterState::Walking;
            sprite.move(0.f, 3.f);

        }
    }
}
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if(!Helpers::checkCharacterCollision(
            currentLevel,
            sf::Vector2f(sprite.getPosition().x + MOVEMENT_PROBE_FACTOR_RIGHT, // Bugged col detection
            sprite.getPosition().y - 15.f))
            && !Helpers::checkCharacterCollision(currentLevel,
                                                 sf::Vector2f(
                                                 sprite.getPosition().x + MOVEMENT_PROBE_FACTOR_RIGHT,
                                                 sprite.getPosition().y + 15.f )
                                                 )) {
        {
            state = CharacterState::Walking;
            sprite.move(3.f, 0.f);

        }
    }
 }


}

inline void Character::checkShouldReset(sf::RenderWindow &gameWindow) {
    // If Shift + R is pressed, reset the character.
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::R)
       && (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)
           || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))) {
        sprite.setPosition(gameWindow.getSize().x - 50, gameWindow.getSize().y / 2);
    }
}
#endif
