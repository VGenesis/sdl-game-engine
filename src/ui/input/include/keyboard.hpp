#ifndef _SDL_H
#include <SDL2/SDL.h>
#define _SDL_H
#endif
#ifndef _STRING
#include <string>
#define _STRING
#endif
#ifndef _LIST_HPP
#include "../../../ds/include/list.hpp"
#define _LIST_HPP
#endif

#define KEYBOARD_KEY_NOT_FOUND -1

/*
 *	A keybind container containing a named action and it's corresponding keyboard scancode.
 *	Used in Keyboard class to facilitate a virtual keyboard.
 *	Depends on the SDL2 library and the list.hpp header file.
 *	For more information on the 'scancode' field, visit the SDL2 wiki page:
 *		https://wiki.libsdl.org/SDL2/SDL_Scancode
 */
class Key{
	public:
		std::string name;
		SDL_Scancode scancode;
		bool pressed {false};
		bool released {false};
		bool state {false};
		bool old_state {false};

		Key(std::string name, SDL_Scancode scancode): name{name}, scancode{scancode}
		{};
};

/*
 *	A keyboard event handling interface.
 *	Contains a non-exclusive list of keybind containers and methods for handling keyboard events.
 */
class Keyboard{
	private:
		void setState(SDL_Scancode scancode, bool state);
	public:
		List<Key>* keys;
		Keyboard();
		void updateEvent(SDL_Event event);
		void updateTick();

		void addKey(std::string name, SDL_Scancode scancode);
		int pressed(std::string name);
		int released(std::string name);
		int held(std::string name);
		void removeKey(std::string name);

		void clear();
};
