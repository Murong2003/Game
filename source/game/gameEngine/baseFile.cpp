/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of game engine.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#include "baseFile.h"

void Game::Engine::BaseFile::File::open(std::string in_path, bool in_read) {
	if (in_read)
		this->stream.open(in_path, std::ios::in);
	else
		this->stream.open(in_path, std::ios::out | std::ios::ate);
}

void Game::Engine::BaseFile::File::close() {
	this->stream.close();
}

std::string Game::Engine::BaseFile::File::read() {
	std::string temp_stream[$GAME_ARRAY_MAX$];
	std::string temp_string;
	Game::type_id temp_count = 0;

	while (!this->stream.eof()) {
		std::getline(this->stream, temp_stream[temp_count]);
		temp_string += temp_stream[temp_count] + "\n";
		temp_count++;
	}

	return temp_string;
}

void Game::Engine::BaseFile::File::write(std::string in_string) {
	this->stream << in_string;
}

std::vector<std::string> Game::Engine::BaseFile::File::readArray() {
	std::vector<std::string> temp_array_vector;
	std::string temp_array[$GAME_ARRAY_MAX$];
	Game::type_id temp_count = 0;
	
	while (!this->stream.eof()) {
		std::getline(this->stream, temp_array[temp_count]);
		temp_array_vector.emplace_back(temp_array[temp_count]);
		temp_count++;
	}

	return temp_array_vector;
}

Game::Engine::BaseFile::File::~File() {
	this->close();
}

void Game::Engine::BaseFile::createDirectory(std::string in_path) {
	int temp_status = mkdir(in_path.c_str());
	if (temp_status != 0)
		stream_console_error << "Failed to create directory!";
}

bool Game::Engine::BaseFile::existDirectory(std::string in_path) {
	if ((_access(in_path.c_str(), 0)) == -1)
		return false;
	else
		return true;
}
