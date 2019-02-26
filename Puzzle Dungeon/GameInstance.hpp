/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/

#ifndef _GAMEINSTANCE_HPP_
#define _GAMEINSTANCE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Level.hpp"
#include "Character.hpp"

#include "PauseMenu.hpp"
#include "MainMenu.hpp"

#include "GUIToolkit.hpp"

class GameInstance {
public:
	Character mainCharacter;
	Level currentLevel;
	void run();
	void initialize();
	GameInstance();
private:
	void checkEventsOnce();
	void drawLayers();
	sf::RenderWindow gameWindow;
	sf::View view;
	PauseMenu pauseMenu;
	MainMenu mainMenu;
};



GameInstance::GameInstance() :
	gameWindow(sf::VideoMode(1024, 768), "Puzzle Dungeon")
	{
	/*Don't hog up all the GPU...*/
	gameWindow.setFramerateLimit(60);
	/*Ensure the window is created in the centre of the screen*/
	sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
	
	gameWindow.setPosition(
						sf::Vector2i(
						sf::VideoMode::getDesktopMode().width / 2 -
						gameWindow.getSize().x / 2,
						sf::VideoMode::getDesktopMode().height / 2 
						- gameWindow.getSize().y / 2
						));

;

	}

/*
@brief Only checks for events once.
Use in a loop to check repeatedly.
*/
inline void GameInstance::checkEventsOnce()
{
		// First check for game logic events
		if (!pauseMenu.isPaused())
			mainCharacter.checkMovement();

		// Then check for SFML events
		sf::Event event;
		gameWindow.pollEvent(event);


		switch (event.type) {

		case sf::Event::Closed:
			gameWindow.close();
		case sf::Event::KeyPressed:
			break;
		case sf::Event::KeyReleased:
			pauseMenu.checkShouldPause(event.key.code, gameWindow);
		case sf::Event::Resized:
			pauseMenu.checkShouldDoResizeWork(gameWindow);
			view = gameWindow.getDefaultView();
			view.setSize(
						static_cast<float>(gameWindow.getSize().x),
						static_cast<float>(gameWindow.getSize().y)
						);
			gameWindow.setView(view);
		default:
			break;
		}
}

/*
@brief We should probably draw the game in layers.
1st layer: any background assets
2nd layer: any objects/tiles
3rd layer: any sprites/characters incl. power-ups
4th layer: any user interface/GUI
*/
inline void GameInstance::drawLayers()
{
	gameWindow.clear();

	// 1st layer

	// 2nd layer

	// 3rd layer
	
	gameWindow.draw(mainCharacter.sprite);

	// 4th layer
	
	pauseMenu.draw(gameWindow);
	
		// TODO Pause menu GUI
	

	gameWindow.display();
}

inline void GameInstance::initialize() {
	// Add any init code here
}

inline void GameInstance::run() {

	initialize();

	while (gameWindow.isOpen()) {
		checkEventsOnce();
		drawLayers();
	}

}


#endif