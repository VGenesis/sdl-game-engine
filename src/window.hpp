#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif
#ifndef _SDL_H
#include <SDL2/SDL.h>
#define _SDL_H
#endif
#ifndef _MOUSE_HPP
#include "ui/input/include/mouse.hpp"
#define _MOUSE_HPP
#endif
#ifndef _KEYBOARD_HPP
#include "ui/input/include/keyboard.hpp"
#define _SDL_H
#endif
#ifndef _EXLIST_HPP
#include "ds/include/exlist.hpp"
#define _EXLIST_HPP
#endif
#ifndef _COLOR_HPP
#include "gfx/misc/include/color.hpp"
#define _COLOR_HPP
#endif
#ifndef _RECT_HPP
#include "gfx/primitives/include/rect.hpp"
#define _RECT_HPP
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

		Mouse* mouse {NULL};
		Rect* mouseRect {NULL};
		int mouseSize {0};

		Keyboard* keyboard {NULL};

		EXList<Rect>* rects {NULL};

		List<Color>* baseColors {NULL};
		int colorIndex {0};
		Color* currentColor {NULL};
		
	public:
		Window(const char* title, int width, int height);
		~Window();
		void initMouse(int mouseSize);
		void initKeyboard();
		void alterKeyboard(KEYBOARD_OP operation, void* operand);
		void update(bool* running);
		void processInput();
		void render();
};
