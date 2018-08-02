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
