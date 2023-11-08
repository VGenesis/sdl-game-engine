// C++ Standard Libraries
#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif

// Simple Directmedia Library
#ifndef _SDL_H
#include <SDL2/SDL.h>
#define _SDL_H
#endif

// OpenGL GLAD Libraries
#ifndef _GLAD_H
#include <glad/glad.h>
#define _GLAD_H
#endif

// Custom libraries
// Data structures
#ifndef _LIST_HPP
#include "ds/include/list.hpp"
#define _LIST_HPP
#endif
#ifndef _EXLIST_HPP
#include "ds/include/exlist.hpp"
#define _EXLIST_HPP
#endif

// Graphics
#ifndef _COLOR_HPP
#include "gfx/misc/include/color.hpp"
#define _COLOR_HPP
#endif
#ifndef _RECT_HPP
#include "gfx/primitives/include/rect.hpp"
#define _RECT_HPP
#endif

//UI
#ifndef _MOUSE_HPP
#include "ui/input/include/mouse.hpp"
#define _MOUSE_HPP
#endif
#ifndef _KEYBOARD_HPP
#include "ui/input/include/keyboard.hpp"
#define _KEYBOARD_HPP
#endif

// Window
#ifndef _WINDOW_HPP
#include "window.hpp"
#define _WINDOW_HPP
#endif

// Template definitions
#ifndef _TEMPLATES_HPP
#include "templates.hpp"
#define _TEMPLATES_HPP
#endif
	
// Window Constants
#define WINDOW_TITLE	"Game Window"
#define WINDOW_WIDTH	640
#define WINDOW_HEIGHT	480
#define MOUSE_RECT_SIZE 20

