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
	temp_file_vertex.open("../resource/shader/vertex.vert", true);
	temp_file_fragment.open("../resource/shader/fragment.frag", true);
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

	// Set up the OpenGL
	Game::Core::Backend::GL::enable(GL_DEPTH_TEST);

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
	const char *temp_source = (in_type == GL_VERTEX_SHADER) ? this->shader_vertex_source.c_str() : this->shader_fragment_source.c_str();

	glShaderSource(temp_shader, 1, &temp_source, nullptr);
	glCompileShader(temp_shader);
	
	// Deposit
	(in_type == GL_VERTEX_SHADER) ? this->shader_vertex = temp_shader : this->shader_fragment = temp_shader;

	// Check
	this->cheekError(in_type);
}

void Game::Core::BaseRenderer::Renderer::linkProgram() {
	Game::type_id &temp_program_deposit = this->shader_program;
	Game::type_id temp_program = glCreateProgram();
	glAttachShader(temp_program, this->shader_vertex);
	glAttachShader(temp_program, this->shader_fragment);
	glLinkProgram(temp_program);

	// Deposit
	temp_program_deposit = temp_program;

	// Cheek
	this->cheekError(GL_PROGRAM);
}

void Game::Core::BaseRenderer::Renderer::useProgram() const {
	glUseProgram(this->shader_program);
}

void Game::Core::BaseRenderer::Renderer::cheekError(Game::type_uint in_type) {
	int temp_status;
	char temp_log[$GAME_ARRAY_MAX$];
	std::string temp_message = "Failed to ";

	if (in_type == GL_VERTEX_SHADER) {
		glGetShaderiv(this->shader_vertex, GL_COMPILE_STATUS, &temp_status);
	} else if (in_type == GL_FRAGMENT_SHADER) {
		glGetShaderiv(this->shader_fragment, GL_COMPILE_STATUS, &temp_status);
	} else if (in_type == GL_PROGRAM) {
		glGetProgramiv(this->shader_program, GL_LINK_STATUS, &temp_status);
	}

	if (temp_status == false) {
		if (in_type == GL_PROGRAM) {
			glGetShaderInfoLog(this->shader_program, $GAME_ARRAY_MAX$, nullptr, temp_log);
			temp_message += "link program: \n";
		} else {
			if (in_type == GL_VERTEX_SHADER) {
				glGetShaderInfoLog(this->shader_program, $GAME_ARRAY_MAX$, nullptr, temp_log);
				temp_message += "compile vertex shader: \n";
			} else if (in_type == GL_FRAGMENT_SHADER) {
				glGetShaderInfoLog(this->shader_program, $GAME_ARRAY_MAX$, nullptr, temp_log);
				temp_message += "compile fragment shader: \n";
			}
		}

		temp_message += temp_log;
		___output_console_error << temp_message;
	}
}

void Game::Core::BaseRenderer::Renderer::setBool(std::string in_name, bool in_value) const {
	glUniform1i(glGetUniformLocation(this->shader_program, in_name.c_str()), (int)in_value);
}

void Game::Core::BaseRenderer::Renderer::setInt(std::string in_name, int in_value) const {
	glUniform1i(glGetUniformLocation(this->shader_program, in_name.c_str()), in_value);
}

void Game::Core::BaseRenderer::Renderer::setFloat(std::string in_name, float in_value) const {
	glUniform1f(glGetUniformLocation(this->shader_program, in_name.c_str()), in_value);
}

void Game::Core::BaseRenderer::Renderer::setVec2(std::string in_name, const glm::vec2 &in_value) const {
	glUniform2fv(glGetUniformLocation(this->shader_program, in_name.c_str()), 1, &in_value[0]);
}

void Game::Core::BaseRenderer::Renderer::setVec2(std::string in_name, float in_x, float in_y) const {
	glUniform2f(glGetUniformLocation(this->shader_program, in_name.c_str()), in_x, in_y);
}

void Game::Core::BaseRenderer::Renderer::setVec3(std::string in_name, const glm::vec3 &in_value) const {
	glUniform3fv(glGetUniformLocation(this->shader_program, in_name.c_str()), 1, &in_value[0]);
}

void Game::Core::BaseRenderer::Renderer::setVec3(std::string in_name, float in_x, float in_y, float in_z) const {
	glUniform3f(glGetUniformLocation(this->shader_program, in_name.c_str()), in_x, in_y, in_z);
}

void Game::Core::BaseRenderer::Renderer::setVec4(std::string in_name, const glm::vec4 &in_value) const {
	glUniform4fv(glGetUniformLocation(this->shader_program, in_name.c_str()), 1, &in_value[0]);
}

void Game::Core::BaseRenderer::Renderer::setVec4(std::string in_name, float in_x, float in_y, float in_z, float in_w) {
	glUniform4f(glGetUniformLocation(this->shader_program, in_name.c_str()), in_x, in_y, in_z, in_w);
}

void Game::Core::BaseRenderer::Renderer::setMat2(std::string in_name, const glm::mat2 &in_mat) const {
	glUniformMatrix2fv(glGetUniformLocation(this->shader_program, in_name.c_str()), 1, false, &in_mat[0][0]);
}

void Game::Core::BaseRenderer::Renderer::setMat3(std::string in_name, const glm::mat3 &in_mat) const {
	glUniformMatrix3fv(glGetUniformLocation(this->shader_program, in_name.c_str()), 1, false, &in_mat[0][0]);
}

void Game::Core::BaseRenderer::Renderer::setMat4(std::string in_name, const glm::mat4 &in_mat) const {
	glUniformMatrix4fv(glGetUniformLocation(this->shader_program, in_name.c_str()), 1, false, &in_mat[0][0]);
}
