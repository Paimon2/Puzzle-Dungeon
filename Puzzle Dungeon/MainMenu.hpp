/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/

#ifndef _MAINMENU_HPP_
#define _MAINMENU_HPP_

#ifdef MACOS
#include "MacTools/ResourcePath.hpp"
#endif


#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "GUIToolkit.hpp"


class MainMenu {
public:
    bool isInMainMenu;

	sf::Texture buttonTexture;
    sf::Texture gameLogoTexture;
    sf::Font textFont;

    sf::Sprite gameLogo;

	/*
	@brief Draw the menu menu.
	Call this regardless of whether or not we're actually paused.
	Checks will be performed to ensure the menu's not drawn while paused.
	@param window A reference pointer to the sf::RenderWindow
	on which to draw on
	*/
	void draw(sf::RenderWindow &window);

	MainMenu();

private:
sf::RectangleShape rect;
sf::Sprite windowContentsSprite;
sf::Texture windowContentsTexture;
Button continueGameButton;
Button newGameButton;
Button settingsButton;
Button helpAboutButton;
};

MainMenu::MainMenu() {
#ifdef MACOS
	buttonTexture.loadFromFile(resourcePath() + "GUI//MainMenuButton.png");
    gameLogoTexture.loadFromFile("GUI//GameLogo.png");
	textFont.loadFromFile(resourcePath() + "Fonts//Robotronica.ttf");
#else
	buttonTexture.loadFromFile("GUI//PauseMenuButton.png");
    gameLogoTexture.loadFromFile("GUI//GameLogo.png");
	textFont.loadFromFile("Fonts//Robotronica.ttf");
#endif

    //blurShader.setUniform("texture", sf::Shader::CurrentTexture);
    gameLogo.setTexture(buttonTexture);

    continueGameButton.buttonSprite.setPosition(80, 200);
    continueGameButton.buttonSprite.setTexture(buttonTexture);
	continueGameButton.text.setFont(textFont);
	continueGameButton.text.setString("Continue game");
	if (/*hasPreviousSave: !! REMOVE false*/ false) {
		continueGameButton.isEnabled = false;
	}
	//newGameButton.setCallback([this](){isGamePaused = !isGamePaused; });


    newGameButton.buttonSprite.setPosition(80, 300);
    newGameButton.buttonSprite.setTexture(buttonTexture);
	newGameButton.text.setFont(textFont);
	newGameButton.text.setString(" New game");

    settingsButton.buttonSprite.setPosition(80, 400);
    settingsButton.buttonSprite.setTexture(buttonTexture);
    settingsButton.text.setFont(textFont);
	settingsButton.text.setString("  Settings");

    helpAboutButton.buttonSprite.setPosition(80, 500);
    helpAboutButton.buttonSprite.setTexture(buttonTexture);
	helpAboutButton.text.setFont(textFont);
	helpAboutButton.text.setString("  Help/About");


	rect.setFillColor(sf::Color(32, 32, 32, 200));
}


inline void MainMenu::draw(sf::RenderWindow &window){

	if (!isInMainMenu)
		return;

	rect.setPosition(window.mapPixelToCoords(sf::Vector2i(window.getSize() / 568u)));
	rect.setSize(sf::Vector2f(window.getSize()));
	window.draw(rect);


    continueGameButton.draw(window);
    newGameButton.draw(window);
    settingsButton.draw(window);
    helpAboutButton.draw(window);
	

    
}



#endif