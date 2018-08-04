/* Game: A high freedom sandbox game just like Minecraft.
 * This name of game is informal.
 * Copyright (c) 2018 MurongSama.
 *
 * This file is a part of Game.
 * Game is a open source game and it follows the GPLv3 protocol.
 * For more information, see <http://www.gnu.org/licenses/gpl-3.0.html>
 */

#ifndef GAME_CORE_BASE_INCLUDE_H
#define GAME_CORE_BASE_INCLUDE_H

#pragma warning (disable: 4099)
#pragma warning (disable: 4996)

#include <string>
#include <vector>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <sstream>
#include <include/glew/glew.h>
#include <include/glfw/glfw3.h>
#include <include/glm/glm.hpp>
#include <include/glm/gtc/matrix_transform.hpp>
#include <include/glm/gtc/type_ptr.hpp>
#include <include/soil/soil.h>

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glu32.lib")
#pragma comment(lib, "library/glfw3.lib")
#pragma comment(lib, "library/glew32.lib")

#ifdef _WIN32
#define $GAME_RUNTIME_WINDOWS$
#endif

#ifdef __cplusplus
#define $GAME_RUNTIME_CPLUSPLUS$
#endif

#ifdef _DEBUG
#define $GAME_MODE_DEBUG$
#endif

#ifndef $GAME_MODE_DEBUG$
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")
#endif

#undef NULL
#ifdef $GAME_RUNTIME_CPLUSPLUS$
#define NULL 0
#else
#define NULL (void*)0
#endif

#define $GAME_ARRAY_MAX$ 0xff
#define $GAME_API$ "Game"

namespace Game {
	typedef unsigned int type_uint;
	typedef unsigned char type_ubyte;
	typedef unsigned int type_id;
	typedef bool type_status;
}

#endif // !GAME_CORE_BASE_INCLUDE_H
