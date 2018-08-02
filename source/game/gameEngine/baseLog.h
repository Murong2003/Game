/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of game engine.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#ifndef GAME_ENGINE_BASE_LOG_H
#define GAME_ENGINE_BASE_LOG_H

#include "base.h"

namespace Game {
	namespace Engine {
		namespace BaseLog {
			enum class StreamLevel {
				INFO,
				WARNING,
				ERROR
			};

			void output(Game::Engine::BaseLog::StreamLevel in_level, std::string in_message);
		}
	}
}

#define ___output_console(in_level, in_message) Game::Engine::BaseLog::output(in_level, in_message)
#define ___output_console_info(in_message) ___output_console(Game::Engine::BaseLog::StreamLevel::INFO, in_message)
#define ___output_console_warning(in_message) ___output_console(Game::Engine::BaseLog::StreamLevel::WARNING, in_message)
#define ___output_console_error(in_message) ___output_console(Game::Engine::BaseLog::StreamLevel::ERROR, in_message)

#endif // !GAME_ENGINE_BASE_LOG_H
