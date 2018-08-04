/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of game engine.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#ifndef GAME_ENGINE_BASE_EXCEPTION_H
#define GAME_ENGINE_BASE_EXCEPTION_H

#include "base.h"

namespace Game {
	namespace Engine {
		namespace BaseException {
			//class ExceptionStorage {
				//ExceptionStorage(std::exception_ptr nestedException, std::chrono::system_clock::time_point const& time, std::string file, unsigned line, std::string src, std::string desc) noexcept
				//	: mNestedException(nestedException), mTime(time), mFile(file), mLine(line), mSource(src), mDescription(desc) {}
				//
				//std::exception_ptr mNestedException;
				//std::chrono::system_clock::time_point mTime;
				//std::string mFile;
				//unsigned mLine;
				//std::string mSource;
				//std::string mDescription;
			//};
		}
	}
}

#endif // !GAME_ENGINE_BASE_EXCEPTION_H
