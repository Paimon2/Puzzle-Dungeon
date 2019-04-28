/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/
// C++ dependencies
#include <iostream>
// Local dependencies
#include "GameInstance.hpp"
#include "Helpers.hpp"
#include "Utilities.hpp"

int main() {
	/*The singleton pattern is in place in the GameInstance class.
	This means we can have ONE, and only ONE instance of this class
	throughout the whole program! Do not create more instances!
	*/
	GameInstance mainInstance;

	mainInstance.mainCharacter.setTexture(
		Utilities::getResourcePath()
		+ "Textures//Character.png");

	Utilities::basicFont.loadFromFile(
		Utilities::getResourcePath() 
		+ "Fonts//Robotronica.ttf");

	mainInstance.run();
	return 0; 
}	

