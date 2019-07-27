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


#include "GameData.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include "GUIToolkit.hpp"



class MainMenu {
public:
    bool isInMainMenu;
	bool hasPreviousSave;

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

	void setPreviousSave(bool hasPrevSave);
	MainMenu();

	Button continueGameButton;
	Button newGameButton;
	Button mechButton;
	Button quitButton;
private:

sf::RectangleShape rect;
sf::Sprite windowContentsSprite;
sf::Texture windowContentsTexture;

};

MainMenu::MainMenu() {
#ifdef MACOS
	buttonTexture.loadFromFile(resourcePath() + "GUI//MainMenuButton.png");
    gameLogoTexture.loadFromFile("GUI//GameLogo.png");
	textFont.loadFromFile(resourcePath() + "Fonts//Robotronica.ttf");
#else
	buttonTexture.loadFromFile("GUI//PauseMenuButton.png");
    gameLogoTexture.loadFromFile("Textures//PuzzleDungeon.png");
	textFont.loadFromFile("Fonts//Robotronica.ttf");
#endif
	hasPreviousSave = false;
	isInMainMenu = true;
	
    //blurShader.setUniform("texture", sf::Shader::CurrentTexture);
    gameLogo.setTexture(gameLogoTexture);
    gameLogo.setPosition(220, 30);

    continueGameButton.buttonSprite.setPosition(80, 250);
    continueGameButton.buttonSprite.setTexture(buttonTexture);
	continueGameButton.text.setFont(textFont);
    continueGameButton.text.setString(" Continue game");
	

	//newGameButton.setCallback([this](){isGamePaused = !isGamePaused; });

    newGameButton.buttonSprite.setPosition(80, 350);
    newGameButton.buttonSprite.setTexture(buttonTexture);
	newGameButton.text.setFont(textFont);
    newGameButton.text.setString("   New game");

    mechButton.buttonSprite.setPosition(80, 450);
    mechButton.buttonSprite.setTexture(buttonTexture);
    mechButton.text.setFont(textFont);
    mechButton.text.setString("    How To Play");
    
    quitButton.buttonSprite.setPosition(80, 550);
    quitButton.buttonSprite.setTexture(buttonTexture);
	quitButton.text.setFont(textFont);
    quitButton.text.setString("Quit to desktop");
    quitButton.setCallback([](){ exit(0); });

	rect.setFillColor(sf::Color(32, 32, 32, 200));
}

inline void MainMenu::setPreviousSave(bool hasPrevSave) {
	hasPreviousSave = hasPrevSave;
	continueGameButton.isEnabled = hasPreviousSave;
}


inline void MainMenu::draw(sf::RenderWindow &window){

	if (!isInMainMenu)
		return;

	rect.setPosition(window.mapPixelToCoords(sf::Vector2i(window.getSize() / 568u)));
	rect.setSize(sf::Vector2f(window.getSize()));
	window.draw(rect);

    window.draw(gameLogo);
    continueGameButton.draw(window);
    newGameButton.draw(window);
    mechButton.draw(window);
    quitButton.draw(window);
	

    
}



#endif
