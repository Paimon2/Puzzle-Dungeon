/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
License pending
*/
// C++ dependencies
#include <iostream>
// Local dependencies
#include "GameInstance.hpp"

int main() {
	/*If we want multiple instances, or want async running, use threads.*/
	GameInstance mainInstance;
	mainInstance.run();
	return 0; 
}	

