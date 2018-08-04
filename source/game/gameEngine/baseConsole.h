/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of game engine.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#ifndef GAME_ENGINE_BASE_CONSOLE_H
#define GAME_ENGINE_BASE_CONSOLE_H

#include "base.h"

namespace Game {
	namespace Engine {
		namespace BaseConsole {
			enum Color {
				TEXT_WHITE,
				TEXT_BLACK,
				TEXT_RED,
				TEXT_GREEN,
				TEXT_BLUE,
				TEXT_YELLOW
			};

			std::ostream &setColor(std::ostream &in_stream, Game::Engine::BaseConsole::Color in_color);
		}
	}
}

#endif // !GAME_ENGINE_BASE_CONSOLE_H
