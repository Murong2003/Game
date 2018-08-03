/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of game engine.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#include "baseLog.h"

Game::Engine::BaseLog::Log::Log(Game::Engine::BaseLog::StreamLevel in_level, std::string in_message, std::string in_file, std::string in_function, Game::type_uint in_line)
	: level(in_level), _file(in_file), _function(in_function), _line(in_line) {
	this->stream << "[" << in_message << "]";

	switch (in_level) {
	case Game::Engine::BaseLog::StreamLevel::INFO:
		this->stream << "[Info] ";
		break;
	case Game::Engine::BaseLog::StreamLevel::WARNING:
		this->stream << "[Warning] ";
		break;
	case Game::Engine::BaseLog::StreamLevel::ERROR:
		this->stream << "[Error] ";
		break;
	}
}

Game::Engine::BaseLog::Log::~Log() {
	if (this->level == Game::Engine::BaseLog::StreamLevel::ERROR) {
		this->stream << std::endl
			<< "\tFile:\t" << this->_file << std::endl
			<< "\tFunction:\t" << this->_function << std::endl
			<< "\tLine:\t" << this->_line << std::endl;
	}

	this->stream << std::endl;

	if (this->level == Game::Engine::BaseLog::StreamLevel::ERROR)
		this->output(std::cerr);
	else
		this->output(std::cout);
}

void Game::Engine::BaseLog::Log::output(std::ostream &in_ostream) const {
	std::string temp_message = this->stream.str();
	in_ostream << temp_message;
}
