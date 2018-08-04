/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of game engine.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#include "baseConsole.h"

#ifdef $GAME_RUNTIME_WINDOWS$
#include <Windows.h>
#endif

std::ostream & Game::Engine::BaseConsole::setColor(std::ostream &in_stream, Game::Engine::BaseConsole::Color in_color) {
#ifdef $GAME_RUNTIME_WINDOWS$
	HANDLE temp_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	switch (in_color) {
	case Game::Engine::BaseConsole::Color::TEXT_WHITE:
		SetConsoleTextAttribute(temp_handle, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		break;
	case Game::Engine::BaseConsole::Color::TEXT_BLACK:
		SetConsoleTextAttribute(temp_handle, 0);
		break;
	case Game::Engine::BaseConsole::Color::TEXT_RED:
		SetConsoleTextAttribute(temp_handle, FOREGROUND_RED);
		break;
	case Game::Engine::BaseConsole::Color::TEXT_GREEN:
		SetConsoleTextAttribute(temp_handle, FOREGROUND_GREEN);
		break;
	case Game::Engine::BaseConsole::Color::TEXT_BLUE:
		SetConsoleTextAttribute(temp_handle, FOREGROUND_BLUE);
		break;
	case Game::Engine::BaseConsole::Color::TEXT_YELLOW:
		SetConsoleTextAttribute(temp_handle, FOREGROUND_RED | FOREGROUND_GREEN);
		break;
	}

	return in_stream;
#else
	switch (in_color) {
	case Game::Engine::BaseConsole::Color::TEXT_WHITE:
		in_stream << "\033[21;37m";
	case Game::Engine::BaseConsole::Color::TEXT_BLACK:
		in_stream << "\033[21;30m";
		break;
	case Game::Engine::BaseConsole::Color::TEXT_RED:
		in_stream << "\033[21;31m";
		break;
	case Game::Engine::BaseConsole::Color::TEXT_GREEN:
		in_stream << "\033[21;32m";
		break;
	case Game::Engine::BaseConsole::Color::TEXT_BLUE:
		in_stream << "\033[21;34m";
		break;
	case Game::Engine::BaseConsole::Color::TEXT_YELLOW:
		in_stream << "\033[21;33m";
		break;
	}

	return in_stream;
#endif
}
