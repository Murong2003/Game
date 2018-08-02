/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of Game.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#ifndef GAME_CORE_BASE_H
#define GAME_CORE_BASE_H

#include "baseInclude.h"
#include "baseTemp.h"
#include "../gameEngine/base.h"

namespace Game {
	namespace Core {
		namespace Backend {
			namespace GLFW {
				void poll();
				void quit();
			}

			void initializeEngine();
		}
	}
}

#endif // !GAME_CORE_BASE_H
