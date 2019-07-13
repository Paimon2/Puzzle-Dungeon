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
#include <list> 

class QuestionBox { 
public:
	sf::Font font;
	sf::Text option1, option2;
	sf::Text dialogue;
	sf::RectangleShape dialbox;
	sf::Sprite icon;

	void setSize(sf::RenderWindow &window); //sets the size of the dialog box, relative to the size of the game window
	void addOption(std::string Dialog); // Adds an option for dialogue that a player can select
	void addDialogue(std::string Dialogue, sf::RenderWindow &window);
	void craftString(sf::Text &textobj, std::string stringobj); 
	void selectOption(sf::RenderWindow &window, std::string Reply);
	void displayOptions(sf::RenderWindow &window);
	void displayDialogue(sf::RenderWindow &window);
private:
	int x;
	int y; // A variable to store the 'x' value of the size of the Game Window
	float z; // A variable to store the new height of the dialogue box. 
	int spacer = dialbox.getPosition().x;
	int count = 0; 
};


void QuestionBox::craftString(sf::Text &textobj, std::string stringobj) {
	font.loadFromFile("arial.ttf");

	textobj.setFont(font);
	textobj.setString(stringobj);
	textobj.setCharacterSize(32);
	textobj.setFillColor(sf::Color::White);
	textobj.setPosition(1, 818 - (818 * 40/100)); // CHANGE 818 TO 'Y' FOR FLEXIBILITY -- CHANGE THE Y VARIABLE IN PRIVATE CLASS
}
 
void QuestionBox::setSize(sf::RenderWindow &window) {
	int x = window.getSize().x;
	int y = window.getSize().y;
	float z = y * 40/100;
	dialbox.setSize(sf::Vector2f(x-2, z));
	dialbox.setOutlineThickness(1.f);
	dialbox.setOutlineColor(sf::Color::White);
	dialbox.setFillColor(sf::Color::Black);
	dialbox.setPosition(1.f, y-z-1);
}




void QuestionBox::addDialogue(std::string Dialogue, sf::RenderWindow &window) {
	dialogue.setString(Dialogue);
	craftString(dialogue, Dialogue);
}


void QuestionBox::addOption(std::string Option) {
	switch(count) {
		case 0:
			craftString(option1, Option);
		case 1:
			craftString(option2, Option);
			option2.setPosition(1, 818 - (818 * 40/100) + 32);
		default:
			std::cout << "";
	}
	count++;
}


// DISPLAY FUNCTIONS MUST ALWAYS GO BETWEEN window.clear(); and window.display();
void QuestionBox::displayOptions(sf::RenderWindow &window) { 
	window.draw(dialbox);
	window.draw(option1);
	window.draw(option2);
}

void QuestionBox::displayDialogue(sf::RenderWindow &window) {
	window.draw(dialbox);
	window.draw(dialogue);

}




/* In main or other thread, check for input. 
	
	In this example, keyPressed == the key code.

	if (keyPressed == 0) { // the number here represents the Player's question to select. 
		qboxobj.selectOption(window, "The Reply to the option ") 

	}


*/


void QuestionBox::selectOption(sf::RenderWindow &window, std::string Reply) { 
	craftString(dialogue, Reply);
	displayDialogue(window);
} 



#endif 