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
    void checkShouldDoResizeWork(sf::RenderWindow &window);

	MainMenu();

private:
sf::Sprite windowContentsSprite;
sf::Texture windowContentsTexture;
sf::Shader blurShader;
Button continueGameButton;
Button newGameButton;
Button settingsButton;
Button helpAboutButton;
};

MainMenu::MainMenu() {
#ifdef MACOS
    //blurShader.loadFromFile(resourcePath() + "Shaders/gaussianblur.frag", sf::Shader::Fragment);
	buttonTexture.loadFromFile(resourcePath() + "GUI//MainMenuButton.png");
    gameLogoTexture.loadFromFile("GUI//GameLogo.png");
	textFont.loadFromFile(resourcePath() + "Fonts//Robotronica.ttf");
#else
   // blurShader.loadFromFile("Shaders/gaussianblur.frag", sf::Shader::Fragment);
	buttonTexture.loadFromFile("GUI//PauseMenuButton.png");
    gameLogoTexture.loadFromFile("GUI//GameLogo.png");
	textFont.loadFromFile("Fonts//Robotronica.ttf");
#endif

    //blurShader.setUniform("texture", sf::Shader::CurrentTexture);
    gameLogo.setTexture(buttonTexture);

    continueGameButton.buttonSprite.setPosition(128, 200);
    continueGameButton.buttonSprite.setTexture(buttonTexture);
	continueGameButton.text.setFont(textFont);
	continueGameButton.text.setString("Continue game");
	//newGameButton.setCallback([this](){isGamePaused = !isGamePaused; });


    newGameButton.buttonSprite.setPosition(128, 300);
    newGameButton.buttonSprite.setTexture(buttonTexture);
	newGameButton.text.setFont(textFont);
	newGameButton.text.setString(" New game");

    settingsButton.buttonSprite.setPosition(128, 400);
    settingsButton.buttonSprite.setTexture(buttonTexture);
    settingsButton.text.setFont(textFont);
	settingsButton.text.setString("  Settings");

    helpAboutButton.buttonSprite.setPosition(128, 500);
    helpAboutButton.buttonSprite.setTexture(buttonTexture);
	helpAboutButton.text.setFont(textFont);
	helpAboutButton.text.setString("  Help/About");
}

inline void MainMenu::checkShouldDoResizeWork(sf::RenderWindow &window){



    windowContentsTexture.create(window.getSize().x + 1000,
		window.getSize().y);
	windowContentsTexture.update(window);
	windowContentsSprite.setTexture(windowContentsTexture);
}


inline void MainMenu::draw(sf::RenderWindow &window){

    
    checkShouldDoResizeWork(window);
    window.draw(windowContentsSprite, &blurShader);
    continueGameButton.draw(window);
    newGameButton.draw(window);
    settingsButton.draw(window);
    helpAboutButton.draw(window);

    
}



#endif