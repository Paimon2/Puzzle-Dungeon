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

#ifdef MACOS
#include "MacTools/ResourcePath.hpp"
#endif

int main() {
	/*If we want multiple instances, or want async running, use threads.*/
	GameInstance mainInstance;
	mainInstance.run();
	return 0; 
}	

