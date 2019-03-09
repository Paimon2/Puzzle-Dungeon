/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/

#include <iostream>
#include <string>
#include <functional>

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>


#ifndef _GUITOOLKIT_HPP_
#define _GUITOOLKIT_HPP_


enum ClickableState {
    None = 0,
    Hovering = 1,
    HoldingDown = 2
};


class Button {
public:
	bool isEnabled;
    sf::Sprite buttonSprite;
    sf::Vector2f position;
    void onClick();
    void draw(sf::RenderWindow &window);
	std::function<void()> function;
	void setCallback(std::function<void()> func);
	Button() {
		isEnabled = true;
		text.setCharacterSize(24);
		text.setFillColor(sf::Color::White);
	}
	/* Text (i.e. label) for the button
  We use a wide string in lieu of a traditional
  std::string so we can hold special characters if need be.
  In some instances, we can also hold binary data.
  */
	sf::Text text;
private:
    // Is the button being hovered or clicked?
    ClickableState state;
  
};


inline void Button::onClick() {
	try {
		function();
	}
	catch (...) {
		throw std::runtime_error("Callback not set; it is nullptr");
	}
}

inline void Button::draw(sf::RenderWindow &window){

	std::string textStr = text.getString().toAnsiString();

	text.setPosition(buttonSprite.getPosition().x + 156,
		buttonSprite.getPosition().y + 35);

	if (!isEnabled) {
		buttonSprite.setColor(sf::Color(120, 120, 80));
		window.draw(buttonSprite);
		text.setFillColor(sf::Color(255, 255, 255, 80));
		window.draw(text);
		return;
	}

	

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && state == ClickableState::HoldingDown)
	{
		onClick();

	}

	sf::Vector2i mousePos = sf::Mouse::getPosition(window);
	sf::Vector2f pixelPos = window.mapPixelToCoords(mousePos);

	state = ClickableState::None;


	if(pixelPos.x <= buttonSprite.getPosition().x+buttonSprite.getTextureRect().width 
    && pixelPos.x+1 >= buttonSprite.getPosition().x && pixelPos.y <= buttonSprite.getPosition().y +
    buttonSprite.getTextureRect().height && 
    pixelPos.y+1 >= buttonSprite.getPosition().y)
    {
        state = ClickableState::Hovering;
         if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
             state = ClickableState::HoldingDown;
             
            }

    }


    // Actual drawing code
	// Change the colour if we're clicking or hovering on it
    switch(state){
        case ClickableState::Hovering:
		  buttonSprite.setColor(sf::Color(200, 200, 200));
          window.draw(buttonSprite);
          break;
        case ClickableState::HoldingDown:
			buttonSprite.setColor(sf::Color(120, 120, 120));
            window.draw(buttonSprite);
            break;
        default:
			buttonSprite.setColor(sf::Color(255, 255, 255));
			window.draw(buttonSprite);
			break;
    }

	window.draw(text);
}

inline void Button::setCallback(std::function<void()> func)
{
	function = func;
}

#endif

