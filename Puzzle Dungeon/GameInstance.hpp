/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
License pending
*/

#ifndef _GAMEINSTANCE_HPP_
#define _GAMEINSTANCE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Level.hpp"

class GameInstance {
public:
	Level currentLevel;
	void run();
	GameInstance();
private:
	void checkEventsOnce();
	void drawLayers();
	sf::RenderWindow gameWindow;
};

#endif

GameInstance::GameInstance() :
	gameWindow(sf::VideoMode(1024, 768), "Puzzle Dungeon")
	{
	/*Don't hog up all the GPU...*/
	gameWindow.setVerticalSyncEnabled(true);
	/*Ensure the window is created in the centre of the screen*/
	sf::VideoMode videoMode = sf::VideoMode::getDesktopMode();
	gameWindow.setPosition(sf::Vector2i(
		videoMode.width / 2 - 512,
		videoMode.height / 2 - 384
	));

	}

/*
@brief Only checks for events once.
Use in a loop to check repeatedly.
*/
inline void GameInstance::checkEventsOnce()
{
		sf::Event event; // Check for events 
		while (gameWindow.pollEvent(event)) { //PollEvent returns true is there were any pending events
			switch (event.type) {
			case sf::Event::Closed:
				gameWindow.close();
			case sf::Event::KeyPressed:
				// do nothing for now
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

	// Layers go here

	gameWindow.display();
}

inline void GameInstance::run() {

	while (gameWindow.isOpen()) {
		checkEventsOnce();
		drawLayers();
	}

}


