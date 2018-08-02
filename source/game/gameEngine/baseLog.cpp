/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of game engine.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#include "baseLog.h"

void Game::Engine::BaseLog::output(Game::Engine::BaseLog::StreamLevel in_level, std::string in_message) {
	std::string temp_message;

	switch (in_level) {
	case Game::Engine::BaseLog::StreamLevel::INFO:
		temp_message = "[Info] " + in_message;
		break;
	case Game::Engine::BaseLog::StreamLevel::WARNING:
		temp_message = "[Warning] " + in_message;
		break;
	case Game::Engine::BaseLog::StreamLevel::ERROR:
		temp_message = "[Error] " + in_message;
		break;
	}

	if (in_level == Game::Engine::BaseLog::StreamLevel::ERROR)
		std::cerr << temp_message << std::endl;
	else
		std::cout << temp_message << std::endl;
}
