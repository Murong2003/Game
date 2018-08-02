/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of game engine.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#ifndef GAME_ENGINE_BASE_FILE_H
#define GAME_ENGINE_BASE_FILE_H

#include "base.h"

namespace Game {
	namespace Engine {
		namespace BaseFile {
			class File {
			public:
				~File();

				// Operator
				void open(std::string in_path, bool in_read);
				void close();
				std::string read();
				void write(std::string in_string);
				std::vector<std::string> readArray();
			private:
				std::fstream stream;
			};
		}
	}
}

#endif // !GAME_ENGINE_BASE_FILE_H
