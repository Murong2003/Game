/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of Game.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#ifndef GAME_CORE_WINDOW_H
#define GAME_CORE_WINDOW_H

#include "baseInclude.h"

namespace Game {
	namespace Core {
		namespace BaseWindow {
			class Window {
			public:
				Window(std::string in_name, Game::type_uint in_size_x, Game::type_uint in_size_y);
				~Window();

				// Operator
				void focus() const;
				void refresh();
				bool getKey(Game::type_uint in_key);
				
				// Get
				std::string getName() const { return this->name; }
				Game::type_uint getSizeX() const { return this->size_x; }
				Game::type_uint getSizeY() const { return this->size_y; }
				bool getQuit() const { return this->quit; }
				GLFWwindow *getWindow() const { return this->window; }
			private:
				std::string name;
				Game::type_uint size_x, size_y;
				bool quit;
				GLFWwindow *window;
			};
		}
	}
}

#endif // !GAME_CORE_WINDOW_H
