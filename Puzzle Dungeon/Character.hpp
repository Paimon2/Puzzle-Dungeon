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

enum CharacterState {
    Idle = 0,
    WalkingLeft = 1,
    WalkingRight = 2,
    WalkingUp = 3,
    WalkingDown = 4
};

class Character {
public:
    void setPosition(float x, float y);
    void setTexture(const std::string &texturePath);
    void checkMovement(Level &currentLevel);
    void draw(sf::RenderWindow &window, sf::View &view);

    void load();

    sf::Sprite sprite;
    // Textures for the character standing still
    std::vector<sf::Texture> idleTextures;
    // What is the character doing?
    CharacterState state;
    // Let's say we're drawing the 4th out of 28 animation frames currently.
    // This is where we will store the 4 - the current frame index.
    int currentFrameIndex;
    // How many frames have elapsed since we started counting?
    // TODO: Reset this when it gets to 84.
    // Why? Because number_of_frames * 3 = 84
    // This gives us an animation 3x as long.
    int framesElapsed;
};

inline void Character::load() {
    state =  CharacterState::Idle;
    framesElapsed = 0;
    currentFrameIndex = 0;
    for(int i = 1; i < 84; i++) {
        sf::Texture textureToPush;
        textureToPush.loadFromFile("Animations//CharacterIdle//" + std::to_string(i) + ".png");
        idleTextures.push_back(textureToPush);
    }




}

inline void Character::draw(sf::RenderWindow &window, sf::View &view) {
    // Reset at 61, otherwise increment.
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 eng(rd()); // seed the generator
    std::uniform_int_distribution<> distr(framesElapsed, framesElapsed + 1); // define the range

    framesElapsed = std::min(84, framesElapsed + 1);
    if(framesElapsed == 84){
    framesElapsed = 0;
    }
    // What is the character doing currently?
    switch(state) {

        case CharacterState::WalkingUp:
        {
            break; // TODO implement
        }

        case CharacterState::WalkingDown:
        {
            break; // TODO implement
        }

        case CharacterState::WalkingLeft:
        {
            break; // TODO implement
        }

        case CharacterState::WalkingRight:
        {
            break; // TODO implement
        }

        case CharacterState::Idle:
        {
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
    std::cerr << "Function deprecated and inoperative!" << std::endl;
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
        if(!Helpers::checkCharacterCollision(
            currentLevel,
            sf::Vector2f(sprite.getPosition().x - 6.f,
            sprite.getPosition().y - 3.f)
            ))
        {
            sprite.move(0.f, -3.f);
        }

    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
        if(!Helpers::checkCharacterCollision(
            currentLevel,
            sf::Vector2f(sprite.getPosition().x - 3.f,
            sprite.getPosition().y - 6.f
            )))
        {
            sprite.move(-3.f, 0.f);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        if(!Helpers::checkCharacterCollision(
            currentLevel,
            sf::Vector2f(sprite.getPosition().x + 12.f,
            sprite.getPosition().y + 6.f
            )))
        {
            sprite.move(0.f, 3.f);
        }
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        if(!Helpers::checkCharacterCollision(
            currentLevel,
            sf::Vector2f(sprite.getPosition().x + 24.f, // Bugged col detection
            sprite.getPosition().y + 6.f
            )))
        {
            sprite.move(3.f, 0.f);
        }
    }


}


#endif
