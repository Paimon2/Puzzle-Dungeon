/*
Puzzle Dungeon ((C) 2019)
@authors Omar Junaid, Sam Dockery
This work is licensed under the
Creative Commons Attribution-NonCommercial-NoDerivatives
4.0 International License. To view a copy of this license,
visit http://creativecommons.org/licenses/by-nc-nd/4.0/.
*/


#ifndef _EVENTHANDLER_HPP_
#define _EVENTHANDLER_HPP_

#include <thread>
#include <chrono>
#include <random>
#include <future>

#include "Level.hpp"

class EventHandler {
private:
	bool eventsRunning = false;

public:
	inline void runEventsInternal(int level,
		Level& levelObj) {
		switch (level) {

		case 1:
		{
			/*
			* TODO: Allow the player to ask a number of questions, as per
			* the SRS on Google Docs.
			*/
			std::this_thread::sleep_for(std::chrono::seconds(rand() % 10 + 7));
			// Frog jumps out of crack and speaks
			std::this_thread::sleep_for(std::chrono::seconds(12));
			// Option to choose what question to ask

		}

		case 2:
		{


		}

		case 3:
		{


		}

		case 4:
		{


		}

		case 5:
		{



		}

		default:
		{
			std::cerr << "Non-existent level no. passed to runEventsInternal!";
			break;
		}
		}

	}

	inline void runEvents(int level, Level &levelObj) {
		std::thread eventsThread([&] { runEventsInternal(level, levelObj); });
		eventsThread.detach();
	}

};







#endif 