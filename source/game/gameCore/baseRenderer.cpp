/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of Game.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#include "base.h"

Game::Core::BaseRenderer::Renderer Game::Core::BaseRenderer::initializeRenderer() {
	// Load shader source
	std::string temp_vertex_source, temp_fragment_source;
	Game::Engine::BaseFile::File temp_file_vertex, temp_file_fragment;
	temp_file_vertex.open("../resource/shader/vertex.txt", true);
	temp_file_fragment.open("../resource/shader/fragment.txt", true);
	temp_vertex_source = temp_file_vertex.read().c_str();
	temp_fragment_source = temp_file_fragment.read().c_str();
	temp_file_vertex.close();
	temp_file_fragment.close();

	// Load vertex
	Game::Engine::BaseFile::File temp_file_vertex_array;
	std::vector<std::string> temp_array_string;
	std::vector<double> temp_array;
	temp_file_vertex_array.open("../resource/shader/array.txt", true);
	temp_array_string = temp_file_vertex_array.readArray();
	for (Game::type_id i = 0; i < temp_array_string.size(); i++) {
		temp_array.emplace_back(Game::Engine::ToolConversion::toDouble(temp_array_string[i]));
	}

	// Create shader
	Game::Core::BaseRenderer::Renderer temp_shader(temp_vertex_source, temp_fragment_source, temp_array);
	return temp_shader;
}

Game::Core::BaseRenderer::Renderer::Renderer(std::string in_vertex_source, std::string in_fragment_source, std::vector<double> in_vertex_array)
	: shader_vertex_source(in_vertex_source), shader_fragment_source(in_fragment_source) {
	double temp_array[$GAME_ARRAY_MAX$];
	Game::Engine::ToolConversion::toDoubleArray(in_vertex_array, *temp_array);
	
	// Create and bind VAO & VBO
	glGenVertexArrays(1, &this->shader_vao);
	glGenBuffers(1, &this->shader_vbo);
	glBindVertexArray(this->shader_vao);
	glBindBuffer(GL_ARRAY_BUFFER, this->shader_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(temp_array), temp_array, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_DOUBLE, false, 5 * sizeof(double), (void*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 2, GL_DOUBLE, false, 5 * sizeof(double), (void*)(3 * sizeof(double)));
	glEnableVertexAttribArray(1);

	// Create shader
	this->compileShader(GL_VERTEX_SHADER);
	this->compileShader(GL_FRAGMENT_SHADER);

	// Link program
	this->linkProgram();
}

Game::Core::BaseRenderer::Renderer::~Renderer() {
	glDeleteVertexArrays(1, &this->shader_vao);
	glDeleteBuffers(1, &this->shader_vbo);
	glDeleteShader(this->shader_vertex);
	glDeleteShader(this->shader_fragment);
	glDeleteProgram(this->shader_program);
}

void Game::Core::BaseRenderer::Renderer::compileShader(Game::type_uint in_type) {
	Game::type_id temp_shader = glCreateShader(in_type);
	std::string temp_source = (in_type == GL_VERTEX_SHADER) ? this->shader_vertex_source : this->shader_fragment_source;

	glShaderSource(temp_shader, 1, (char**)temp_source.c_str(), nullptr);
	glCompileShader(temp_shader);

	Game::type_status temp_shader_status = true;
	glGetShaderiv(temp_shader, GL_COMPILE_STATUS, (int*)temp_shader_status);

	if (temp_shader_status == false) {
		char temp_log[$GAME_ARRAY_MAX$];
		Game::type_uint temp_log_size = 0;
		glGetShaderInfoLog(temp_shader, $GAME_ARRAY_MAX$, (int*)temp_log_size, temp_log);

		std::string temp_output = "Failed to compile shader: " + temp_log_size + '>' + temp_source;
		___output_console_error(temp_output);
	}
	
	// Deposit
	(in_type == GL_VERTEX_SHADER) ? this->shader_vertex = temp_shader : this->shader_fragment = temp_shader;
}

void Game::Core::BaseRenderer::Renderer::linkProgram() {
	Game::type_id &temp_program_return = this->shader_program;
	Game::type_id temp_program = glCreateProgram();
	glAttachShader(temp_program, this->shader_vertex);
	glAttachShader(temp_program, this->shader_fragment);
	glLinkProgram(temp_program);

	Game::type_status temp_shader_status = true;
	glGetShaderiv(temp_program, GL_LINK_STATUS, (int*)temp_shader_status);

	if (temp_shader_status == false) {
		char temp_log[$GAME_ARRAY_MAX$];
		Game::type_uint temp_log_size = 0;
		glGetProgramInfoLog(temp_program, $GAME_ARRAY_MAX$, (int*)temp_log_size, temp_log);

		std::string temp_output = "Failed to link shader program: " + *temp_log;
		___output_console_error(temp_output);
	}

	// Deposit
	temp_program_return = temp_program;
}

void Game::Core::BaseRenderer::Renderer::useProgram() const {
	glUseProgram(this->shader_program);
}
