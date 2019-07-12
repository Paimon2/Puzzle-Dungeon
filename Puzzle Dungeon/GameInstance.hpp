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

#include "GameData.hpp"

class GameInstance {
public:
	GameData gameData;
	Character mainCharacter;
	Level currentLevel;
	void run();
	void initialize();
	GameInstance();
private:
	sf::Vector2u previousSize;
	void checkEventsOnce();
	void drawLayers();
	sf::RenderWindow gameWindow;
	sf::View view;
	PauseMenu pauseMenu;
	MainMenu mainMenu;
};



GameInstance::GameInstance() :
	gameWindow(sf::VideoMode(1366, 818), "Puzzle Dungeon")
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


	mainMenu.continueGameButton.setCallback([this]() {
		currentLevel.loadLevel(gameData.data["progress"]["level"]);
		mainMenu.isInMainMenu = false;
		currentLevel.scaleEverything(gameWindow.getSize());
		});

	mainMenu.newGameButton.setCallback([this]() {
		gameData.data["progress"]["level"] = 1;
		gameData.save();
		currentLevel.loadLevel(gameData.data["progress"]["level"]);
		mainMenu.isInMainMenu = false;
		currentLevel.scaleEverything(gameWindow.getSize());
	});
	}

/*
@brief Only checks for events once.
Use in a loop to check repeatedly.
*/
inline void GameInstance::checkEventsOnce()
{
		// First check for game logic events
		if (!pauseMenu.isPaused())
			mainCharacter.checkMovement(currentLevel);

		// Then check for SFML events
		sf::Event event;
		gameWindow.pollEvent(event);


		switch (event.type) {

        break; case sf::Event::Closed: {
			gameWindow.close();
            break;
		}
        break; case sf::Event::KeyPressed: {
            pauseMenu.checkShouldPause(gameWindow);
            break;
		}
			
        break; case sf::Event::Resized: {
			if (gameWindow.getSize() != previousSize) {
				pauseMenu.checkShouldDoResizeWork(gameWindow);
			view = gameWindow.getDefaultView();
			view.setSize(
						static_cast<float>(gameWindow.getSize().x),
						static_cast<float>(gameWindow.getSize().y)
						);
			gameWindow.setView(view);
			}
            break;
		}
			
        break; default: {
            break;
        }
			
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


	currentLevel.drawTiles(gameWindow, mainCharacter.sprite);
	mainCharacter.draw(gameWindow, view);

	// 4th layer
	
	pauseMenu.draw(gameWindow);
	mainMenu.draw(gameWindow);
		// TODO Pause menu GUI
	

	gameWindow.display();
}

inline void GameInstance::initialize() {
	// Add any init code here

	gameData.load();
	mainMenu.isInMainMenu = true;
	mainMenu.hasPreviousSave = true;
	mainCharacter.setPosition(gameWindow.getSize().x - 50, gameWindow.getSize().y / 2);
	

	try {
		auto level = gameData.data["progress"]["level"];

		if (!level) /*level == 0*/
			mainMenu.setPreviousSave(false);
	}
	
	catch (nlohmann::detail::type_error) {
		/*
		We assume the game data does not exist, so
		we generate the file.*/
		gameData.generateInitialGameData();
		mainMenu.setPreviousSave(false);
	}
	
	

}

inline void GameInstance::run() {

	initialize();

	while (gameWindow.isOpen()) {
		checkEventsOnce();
		drawLayers();
	}

}


#endif
