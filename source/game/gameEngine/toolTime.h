/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of game engine.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#ifndef GAME_ENGINE_TOOL_TIME_H
#define GAME_ENGINE_TOOL_TIME_H

#include "base.h"

namespace Game {
	namespace Engine {
		namespace ToolTime {
			enum Type {
				ALL, // For example: 20180804120000
				ALL_FORMAT, // For example: 2018-08-04 12:00:00
				DATE, // For example: 20180804
				DATE_FORMAT, // For example: 2018-08-04
				TIME, // For example: 120000
				TIME_FORMAT // For example: 12:00:00
			};

			std::string getCurrentTime(Game::Engine::ToolTime::Type in_type);
		}
	}
}


#endif // !GAME_ENGINE_TOOL_TIME_H
