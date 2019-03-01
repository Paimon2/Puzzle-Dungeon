/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/

#ifndef _GAMEDATA_HPP_
#define _GAMEDATA_HPP_

#include "json.hpp"
#include <fstream>
#include <iomanip>

class GameData {
	nlohmann::json data;
	void loadGameData();
	void generateInitialGameData();
	void saveGameData();
};

inline void GameData::loadGameData() {
	std::ifstream i("GameData.json");
	i >> data;
}

inline void GameData::generateInitialGameData()
{
	data["progress"]["level"] = 0;

	// Video settings
	data["settings"]["max_fps"] = 60;
	data["settings"]["fullscreen"] = false;
	data["settings"]["show_fps"] = false;
	
	// Audio settings (levels from 0 to 100)
	data["settings"]["music_volume"] = 100;
	data["settings"]["sound_volume"] = 100;


	saveGameData();
}

inline void GameData::saveGameData()
{
	std::ofstream o("GameData.json");
	o << std::setw(4) << data << std::endl;
}


#endif