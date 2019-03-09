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
#include <SFML/Graphics.hpp>

class GameData {
public:
	// Actual json data object
	nlohmann::json data;
	void load();
	// Only call when GameData.json is empty or doesn't exist.
	void generateInitialGameData();
	void save();
};

inline void GameData::load() {
	std::ifstream i("GameData.json");
	if (!i.is_open())
		return;
	i >> data;
}

inline void GameData::generateInitialGameData()
{
	data["progress"]["level"] = 0;

	// Video settings
	data["settings"]["max_fps"] = 60;
	data["settings"]["fullscreen"] = false;
	data["settings"]["show_fps"] = false;
	data["settings"]["screen_resolution_width"] = sf::VideoMode::getDesktopMode().width;
	data["settings"]["screen_resolution_height"] = sf::VideoMode::getDesktopMode().height;

	// Audio settings (levels from 0 to 100)
	data["settings"]["music_volume"] = 100;
	data["settings"]["sound_volume"] = 100;


	save();
}

inline void GameData::save()
{
	std::ofstream o("GameData.json");
	o << std::setw(4) << data << std::endl;
}


#endif