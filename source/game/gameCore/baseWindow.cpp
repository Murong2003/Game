/* Game: A high freedom sandbox game just like Minecraft.
* This name of game is informal.
* Copyright (c) 2018 MurongSama.
*
* This file is a part of Game.
* Game is a open source game and it follows the GPLv3 protocol.
* For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
*/

#include "base.h"

void Game::Core::BaseWindow::Window::focus() const {
	glfwMakeContextCurrent(this->window);
}

void Game::Core::BaseWindow::Window::refresh() {
	glfwGetWindowSize(this->window, (int*)$window_current_size_x, (int*)$window_current_size_y);
	this->quit = glfwWindowShouldClose(this->window);

	if (this->getKey(GLFW_KEY_ESCAPE)) {
		this->quit = true;
	}

	glfwSwapBuffers(this->window);
}

bool Game::Core::BaseWindow::Window::getKey(Game::type_uint in_key) {
	return glfwGetKey(this->window, in_key);
}

Game::Core::BaseWindow::Window::Window(std::string in_name, Game::type_uint in_size_x, Game::type_uint in_size_y)
	: name(in_name), size_x(in_size_x), size_y(in_size_y), quit(false) {
	GLFWwindow *temp_window = nullptr;

	temp_window = glfwCreateWindow(in_size_x, in_size_y, in_name.c_str(), nullptr, nullptr);
	if (temp_window == nullptr)
		___output_console_error("Create window failed!");

	this->window = temp_window;
	this->focus();
}

Game::Core::BaseWindow::Window::~Window() {
	this->quit = true;
	glfwDestroyWindow(this->window);
}
