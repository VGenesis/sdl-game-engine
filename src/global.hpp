// C++ Standard Library
#ifndef _CSTDLIB
#include <cstdlib>
#define _CSTDLI B
#endif
#ifndef _CMATH
#include <cmath>
#define _CMATH
#endif

// Graphics Libraries
#ifndef _SDL_H
#include <SDL2/SDL.h>
#define _SDL_H
#endif
#ifndef _COLOR_HPP
#include "gfx/misc/include/color.hpp"
#define _COLOR_HPP
#endif

// Window Settings
#define WINDOW_TITLE "Game Window"
#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 400

// GridRenderer Settings
#define GRID_SIZE_X 16
#define GRID_SIZE_Y 16

// Mouse settings
#define MOUSE_RECT_SIZE 16

// Game Settings
#define FPS 60

// Snake Settings
#define SNAKE_SPEED(size) (0.3 - 0.25 * (1 - pow(0.95, size)))

// User defined macros
#define GLOBAL_GRID_WIDTH() (WINDOW_WIDTH / GRID_SIZE_X)
#define GLOBAL_GRID_HEIGHT() (WINDOW_HEIGHT / GRID_SIZE_Y)
#define GRID_RAND_X() (rand() % GLOBAL_GRID_WIDTH())
#define GRID_RAND_Y() (rand() % GLOBAL_GRID_HEIGHT())

