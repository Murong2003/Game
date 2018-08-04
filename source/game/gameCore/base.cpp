/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of Game.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#include "base.h"

void Game::Core::Backend::initializeEngine() {
	GLFWwindow *temp_window;
	glfwInit();
	temp_window = glfwCreateWindow(60, 60, "[Game] Initialize engine...", nullptr, nullptr);
	glfwMakeContextCurrent(temp_window);
	glewInit();
	glfwDestroyWindow(temp_window);
}

void Game::Core::Backend::GLFW::poll() {
	glfwPollEvents();
}

void Game::Core::Backend::GLFW::quit() {
	glfwTerminate();
}

void Game::Core::Backend::GL::enable(Game::type_uint in_type) {
	glEnable(in_type);
}

void Game::Core::Backend::GL::disable(Game::type_uint in_type) {
	glDisable(in_type);
}

Game::type_uint Game::Core::Backend::GL::checkError() {
	std::string temp_output;
	Game::type_uint temp_error = glGetError();

	if (temp_error != GL_NO_ERROR) {
		temp_output = "Find an OpenGL error: " + std::to_string(temp_error);
		switch (temp_error) {
		case GL_INVALID_ENUM:
			temp_output += " (invalid enum)";
			break;
		case GL_INVALID_VALUE:
			temp_output += " (invalid value)";
			break;
		case GL_STACK_OVERFLOW:
			temp_output += " (stack overflow)";
			break;
		case GL_STACK_UNDERFLOW:
			temp_output += " (stack underflow)";
			break;
		case GL_OUT_OF_MEMORY:
			temp_output += " (out of memory)";
			break;
		case GL_INVALID_FRAMEBUFFER_OPERATION:
			temp_output += " (invalid frame buffer operation)";
			break;
		}

		stream_console_error << temp_output;
	}

	return temp_error;
}
