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
#include "GameInstance.hpp"
#include "GameData.hpp"


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
	void doExtraWork(int level);
	void setPreviousSave(bool hasPrevSave);
	MainMenu();

	Button continueGameButton;
	Button newGameButton;
	Button mechButton;
	Button quitButton;

	bool isClicked = false;
private:

sf::RectangleShape rect;
sf::Sprite windowContentsSprite;
sf::Texture windowContentsTexture;
sf::RectangleShape hopImage;
sf::Texture guideTexture;
sf::RectangleShape background;
sf::Texture backTexture;

sf::RectangleShape miniMap;
sf::RectangleShape miniMapBackground;
sf::Texture mapTexture1;
sf::Texture mapTexture2;
sf::Texture mapTexture3;
sf::Texture mapTexture4;
sf::Texture mapTexture5;

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
	guideTexture.loadFromFile("GUI//guide.png");
	backTexture.loadFromFile("GUI//background.png");
	mapTexture1.loadFromFile("GUI//minimap1.png");
	mapTexture2.loadFromFile("GUI//minimap2.png");
	mapTexture3.loadFromFile("GUI//minimap3.png");
	mapTexture4.loadFromFile("GUI//minimap4.png");
	mapTexture5.loadFromFile("GUI//minimap5.png");
#endif

	hasPreviousSave = false;
	isInMainMenu = true;
	
    //blurShader.setUniform("texture", sf::Shader::CurrentTexture);
    gameLogo.setTexture(gameLogoTexture);
    gameLogo.setPosition(220, 30);

    continueGameButton.buttonSprite.setPosition(80, 350);
    continueGameButton.buttonSprite.setTexture(buttonTexture);
	continueGameButton.text.setFont(textFont);
    continueGameButton.text.setString(" Continue Exploring");
	
	//newGameButton.setCallback([this](){isGamePaused = !isGamePaused; });

    newGameButton.buttonSprite.setPosition(80, 450);
    newGameButton.buttonSprite.setTexture(buttonTexture);
	newGameButton.text.setFont(textFont);
    newGameButton.text.setString("   New Journey");

    quitButton.buttonSprite.setPosition(80, 550);
    quitButton.buttonSprite.setTexture(buttonTexture);
	quitButton.text.setFont(textFont);
    quitButton.text.setString("	Quit to desktop");
    quitButton.setCallback([](){ exit(0); });

    mechButton.buttonSprite.setPosition(80, 650);
    mechButton.buttonSprite.setTexture(buttonTexture);
    mechButton.text.setFont(textFont);
    mechButton.text.setString("    How To Play");
    mechButton.setCallback([&](){ isClicked = !isClicked; });

	rect.setFillColor(sf::Color(32, 32, 32, 200));

	hopImage.setTexture(&guideTexture);
	hopImage.setPosition(55, 30);
	hopImage.setSize(sf::Vector2f(1250, 620));

	background.setTexture(&backTexture);
	background.setPosition(0, 0);
	background.setSize(sf::Vector2f(1366, 818));

	miniMap.setPosition(750, 300); 
	miniMap.setSize(sf::Vector2f(450, 350));

	miniMapBackground.setPosition(750, 300);
	miniMapBackground.setFillColor(sf::Color(198, 140, 83));
	miniMapBackground.setSize(sf::Vector2f(450,350));


}

void MainMenu::doExtraWork(int level) {

	switch (level) {
		case 1:
			miniMap.setTexture(&mapTexture1);
			break;
		case 2:
			miniMap.setTexture(&mapTexture2);
			break;
		case 3:
			miniMap.setTexture(&mapTexture3);
			break;
		case 4:
			miniMap.setTexture(&mapTexture4);
			break;
		case 5:
			miniMap.setTexture(&mapTexture5);
			break;
	}

}

inline void MainMenu::setPreviousSave(bool hasPrevSave) {
	hasPreviousSave = hasPrevSave;
	continueGameButton.isEnabled = hasPreviousSave;
}



inline void MainMenu::draw(sf::RenderWindow &window){

	if (!isInMainMenu)
		return;

	window.draw(background);

	rect.setPosition(window.mapPixelToCoords(sf::Vector2i(window.getSize() / 568u)));
	rect.setSize(sf::Vector2f(window.getSize()));
	window.draw(rect);

    window.draw(gameLogo);
    continueGameButton.draw(window);
    newGameButton.draw(window);
    mechButton.draw(window);
    quitButton.draw(window);

    window.draw(miniMapBackground);
	window.draw(miniMap); 

	 if (isClicked) {
		window.draw(hopImage);
	} else {
		//None;
	}
}



#endif
