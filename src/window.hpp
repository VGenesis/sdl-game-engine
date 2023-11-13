// CC Standard Libraries
#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif

// SDL Libraries
#ifndef _SDL_H
#include <SDL2/SDL.h>
#define _SDL_H
#endif

// Global Variables
#ifndef _GLOBAL_HPP
#include "global.hpp"
#define _GLOBAL_HPP
#endif

// UI Libraries
#ifndef _MOUSE_HPP
#include "ui/input/include/mouse.hpp"
#define _MOUSE_HPP
#endif
#ifndef _KEYBOARD_HPP
#include "ui/input/include/keyboard.hpp"
#define _SDL_H
#endif

// Data Structure Libraries
#ifndef _EXLIST_HPP
#include "ds/include/exlist.hpp"
#define _EXLIST_HPP
#endif

// Graphics Libraries
#ifndef _COLOR_HPP
#include "gfx/misc/include/color.hpp"
#define _COLOR_HPP
#endif
#ifndef _RECT_HPP
#include "gfx/primitives/include/rect.hpp"
#define _RECT_HPP
#endif

// Utility Libraries
#ifndef _TIMER_HPP
#include "util/include/timer.hpp"
#define _TIMER_HPP
#endif

// Snake game dependencies
#ifndef _SNAKE_HPP
#include "projects/snake/include/snake.hpp"
#define _SNAKE_HPP
#endif
#ifndef _GRID_HPP
#include "projects/snake/include/grid.hpp"
#define _GRID_HPP
#endif

enum KEYBOARD_OP{
	KB_ADD,
	KB_REMOVE,
	KB_CLEAR
};

class Window{
	private:
		SDL_Window* window {NULL};
		SDL_Renderer* renderer {NULL};

		Keyboard* keyboard {NULL};

		GridRenderer* grid {NULL};
		Snake* snake {NULL};
		Timer* snakeTimer {NULL};
		Point* apple {NULL};

		Color* c_snake_alive {c_green};
		Color* c_snake_dead {c_yellow};
		Color* c_apple {c_red};

		void randomizeColors();
		void createApple();
		
	public:
		Window(const char* title, int width, int height);
		~Window();

		void setTitle(const char* title);

		void initMouse(int mouseSize);
		void initKeyboard();
		void alterKeyboard(KEYBOARD_OP operation, void* operand);

		void updateRealTime(double delta);
		void updateFrame(bool* running);
		void processInput();
		void render();
};
