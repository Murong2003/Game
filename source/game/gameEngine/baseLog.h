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

			class Log {
			public:
				Log(Game::Engine::BaseLog::StreamLevel in_level, std::string in_message, std::string in_file, std::string in_function, Game::type_uint in_line);
				~Log();

				// Template
				template <typename temp_output>
				temp_output &operator<< (const temp_output &in_stream) {
					this->stream << in_stream;
					return *this; // TODO: fix bug!
				}

				// Get
				Game::Engine::BaseLog::StreamLevel getLevel() const { return this->level; }
				std::string getMessage() const { return this->stream.str(); }
				std::string getFile() const { return this->_file; }
				std::string getFunction() const { return this->_function; }
				Game::type_uint getLine() const { return this->_line; }
			private:
				Game::Engine::BaseLog::StreamLevel level;
				std::stringstream stream;
				std::string _file;
				std::string _function;
				Game::type_uint _line;

				// Operator
				void output(std::ostream &in_ostream) const;
			};
		}
	}
}

#define ___output_console(in_level) Game::Engine::BaseLog::Log::Log(in_level, $GAME_API$, __FILE__, __FUNCTION__, __LINE__)
#define ___output_console_info ___output_console(Game::Engine::BaseLog::StreamLevel::INFO)
#define ___output_console_warning ___output_console(Game::Engine::BaseLog::StreamLevel::WARNING)
#define ___output_console_error ___output_console(Game::Engine::BaseLog::StreamLevel::ERROR)

#endif // !GAME_ENGINE_BASE_LOG_H
