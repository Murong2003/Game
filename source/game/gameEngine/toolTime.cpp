/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of game engine.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#include "toolTime.h"

std::string Game::Engine::ToolTime::getCurrentTime(Game::Engine::ToolTime::Type in_type) {
	std::time_t temp_time;
	std::time(&temp_time);

	char temp_string[$GAME_ARRAY_MAX$];
	std::string temp_format;

	switch (in_type) {
	case Game::Engine::ToolTime::ALL:
		temp_format = "%Y%m%d%H%M%S";
		break;
	case Game::Engine::ToolTime::ALL_FORMAT:
		temp_format = "%Y-%m-%d %H:%M:%S";
		break;
	case Game::Engine::ToolTime::DATE:
		temp_format = "%Y%m%d";
		break;
	case Game::Engine::ToolTime::DATE_FORMAT:
		temp_format = "%Y-%m-%d";
		break;
	case Game::Engine::ToolTime::TIME:
		temp_format = "%H%M%S";
		break;
	case Game::Engine::ToolTime::TIME_FORMAT:
		temp_format = "%H:%M:%S";
		break;
	}
	
	// Formatting
	std::strftime(temp_string, sizeof(temp_string), temp_format.c_str(), localtime(&temp_time));
	return temp_string;
}
