/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/

#ifndef _UTILITIES_HPP_
#define _UTILITIES_HPP_

#include <SFML/Graphics.hpp>
#include <cmath>

#ifdef MACOS
#include "MacTools/ResourcePath.hpp"
#endif

namespace Utilities {

	// Quick and easy access to a font
	static sf::Font basicFont;


	/*
	* @brief Get the app bundle resource path on Mac systems, or return
	* an empty string on other systems.
	* @return See @brief
	*/
	std::string getResourcePath() {
#ifdef MACOS
		return resourcePath();
#else
		return "";
#endif
	}

	/*
	* @brief The distance between two points on a 2D plane.
	*/
	float euclideanDistance(sf::Vector2f pointOne, sf::Vector2f pointTwo) {
		float x = pointOne.x - pointTwo.x;
		float y = pointOne.y - pointTwo.y;
		float dist = 0.f;

		dist = powf(x, 2) + powf(y, 2);
		dist = sqrtf(dist);
		
		return dist;
	}

	bool areSpritesColliding(sf::Sprite& sprite1, sf::Sprite& sprite2) {
		return (sprite1.getGlobalBounds().intersects(sprite2.getGlobalBounds()));
	}
}

#endif
