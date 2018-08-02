/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of game engine.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#ifndef GAME_ENGINE_TOOL_CONVERSION_H
#define GAME_ENGINE_TOOL_CONVERSION_H

#include "base.h"

namespace Game {
	namespace Engine {
		namespace ToolConversion {
			char *toCharPointer(std::string in_string);
			double toDouble(std::string in_string);
			double *toDoublePointer(std::vector<double> in_vector);
			void toDoubleArray(std::vector<double> in_vector, double &in_pointer);
		}
	}
}

#endif // !GAME_ENGINE_TOOL_CONVERSION_H
