/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/


//TO DO ! Change 818 on line 54 to a percentage for compatability.

#ifndef _QUESTION_HPP_
#define _QUESTION_HPP_ 

#include <chrono> // time, used in the display() function
#include <SFML/Graphics.hpp> 
#include <SFML/Window.hpp>
#include <iostream>
#include <functional>

/* A single screen containing dialogue.
 * Includes a question and two options.
 */
class DialogueScreen {
public:
    // @brief The question that's to be asked
    sf::Text dialogueText;
    // @brief Two options in text
    sf::Text option1;
    sf::Text option2;
    // Depending on which option the user chooses,
    // another dialogue screen is sometimes shown.
    //
    // @brief This is shown if the user selects option 1.
    static DialogueScreen option1Screen;
    // @brief This is shown if the user selects option 2.
    static DialogueScreen option2Screen;
    // @brief The actual container for all the dialogue components
    sf::RectangleShape dialbox;
    //
    // @intro Below are functions that are publicly accessible.
    //
    // @brief This sets up the dialogue screen so that it can be used.
    // It involves setting fonts, sizes etc. and adjusting everything else.
    // Call this AFTER you have set all other options.
    // @params None
    // @throws Nothing
    void setup(sf::RenderWindow &window);
    // TODO IMPL: @brief Sets a current dialogue screen as active
    void setActive();
private:
    sf::Font renderFont;
    void displayEverything(sf::RenderWindow &window);
};

void DialogueScreen::setup(sf::RenderWindow &window) {
    renderFont.loadFromFile("Fonts//Robotronica.ttf");
    // Set option 1's text info
    option1.setFont(renderFont);
    option1.setCharacterSize(32);
    option1.setFillColor(sf::Color::White);
    // Set option 2's text info
    option2.setFont(renderFont);
    option2.setCharacterSize(32);
    option2.setFillColor(sf::Color::White);
    // Set the dialogue's text info
    dialogueText.setFont(renderFont);
    dialogueText.setCharacterSize(32);
    dialogueText.setFillColor(sf::Color::White);
    // Set option 1's position
    option1.setPosition(60, 600);
    // Set option 2's position
    option2.setPosition(60, 40);
    // Set the dialogue text's position
    dialogueText.setPosition(100, 70);
    // Set size for the box
    unsigned int x = window.getSize().x;
    unsigned int y = window.getSize().y;
    float z = y * 20/100;
    dialbox.setSize(sf::Vector2f(x-2, z));
    dialbox.setOutlineThickness(0.5f);
    dialbox.setFillColor(sf::Color(0, 0, 0, 150));
    dialbox.setPosition(1.f, y-z-1);

}

void DialogueScreen::setActive(){

}

void DialogueScreen::displayEverything(sf::RenderWindow &window){
    window.draw(dialbox);
    window.draw(dialogueText);
    window.draw(option1);
    window.draw(option2);
}

#endif
