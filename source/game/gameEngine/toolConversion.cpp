/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of game engine.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#include "toolConversion.h"

char *Game::Engine::ToolConversion::toCharPointer(std::string in_string) {
	char *temp_string = new char[$GAME_ARRAY_MAX$];
	std::strcpy(temp_string, in_string.c_str());
	return temp_string;
}

double Game::Engine::ToolConversion::toDouble(std::string in_string) {
	char *temp_t = Game::Engine::ToolConversion::toCharPointer(in_string.c_str());
	double temp_r = 0.0;
	int temp_flag = 0;

	while (*temp_t == ' ')
		temp_t++;

	if (*temp_t == '-') {
		temp_flag = -1;
		temp_t++;
	} else {
		temp_flag = 1;
		temp_t++;
	}

	while (*temp_t != '.') {
		if ((*temp_t >= '0') && (*temp_t <= '9')) {
			temp_r *= 10;
			temp_r += (*temp_t++) - '0';
		} else
			return 0;
	}

	*temp_t++;
	int temp_i = 0, temp_a = 0;
	while (*temp_t != '\0') {
		if ((*temp_t >= '0') && (*temp_t <= '9')) {
			temp_a *= 10;
			temp_a += (*temp_t++) - '0';
			temp_i++;
		} else
			return 0;
	}

	double temp_n = 1.0;
	for (int i = 0; i < temp_i; i++)
		temp_n *= 10.0;

	double temp_d = temp_a / temp_n;
	temp_r += temp_d;
	temp_r *= temp_flag;

	return temp_r;
}

double *Game::Engine::ToolConversion::toDoublePointer(std::vector<double> in_vector) {
	double *temp_result = new double[$GAME_ARRAY_MAX$];

	for (Game::type_id i = 0; i < in_vector.size(); i++) {
		temp_result[i] = in_vector[i];
	}

	return temp_result;
}

void Game::Engine::ToolConversion::toDoubleArray(std::vector<double> in_vector, double &in_pointer) {
	double *temp_vector = Game::Engine::ToolConversion::toDoublePointer(in_vector);
	in_pointer = *temp_vector;
}
