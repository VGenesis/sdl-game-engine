/*
 *	keyboard.cpp
 *	A source file containing the implementation of the Keyboard class defined in the
 *	keyboard.hpp file.
 *	Depends solely on the keyboard.hpp file.
 */

#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif
#ifndef _KEYBOARD_HPP
#include "../include/keyboard.hpp"
#define _KEYBOARD_HPP
#endif

/*
 *	Updates whether the key is held or not.
 *	Implicitly invoked during event handling, specifically during updateEvent() method.
 */
void Keyboard::setState(SDL_Scancode scancode, bool state){
	int i = 0;
	Key* k = NULL;
	while((k = keys->get(i++)) != NULL){
		if(k->scancode == scancode){
			k->pressed = !k->pressed && state;
			k->released = !k->released && !state;
			k->state = state;
		}
	}
}

Keyboard::Keyboard(){
	this->keys = new List<Key>();
}

/*
 *	Resolves an SDL_Event if it's a keyboard event.
 *	Called in the event handling loop. For more information on SDL2 event handling visit:
 *		https://wiki.libsdl.org/SDL2/SDL_Event
 */
void Keyboard::updateEvent(SDL_Event event){
	SDL_Scancode scancode;
	switch(event.type){
		case SDL_KEYDOWN:
			scancode = event.key.keysym.scancode;
			setState(scancode, true);
			break;
		case SDL_KEYUP:
			scancode = event.key.keysym.scancode;
			setState(scancode, false);
			break;
	}
}

/*
 *	Updates whether the key has just been pressed or released.
 *	Called after resolving events in the main applicaion loop.
 */
void Keyboard::updateTick(){
	int i = 0;
	Key* k = NULL;
	while((k = keys->get(i++)) != NULL){
		k->pressed = k->state && !k->old_state;
		k->released = !k->state && k->old_state;
		k->old_state = k->state;
	}
}

/*
 *	Adds a new key into the keybind list.
 *	For information on the 'scancode' visit the SDL2 Wiki page:
 *		https://wiki.libsdl.org/SDL2/SDL_Scancode
 */
void Keyboard::addKey(std::string name, SDL_Scancode scancode){
	keys->add(new Key(name, scancode));
	std::cout << keys->size() << std::endl;
}

/*
 *	Searches the keybind list by name and returns whether that key has just been pressed.
 *	Alternatively returns a KEYBOARD_KEY_NOT_FOUND error code.
 */
int Keyboard::pressed(std::string name){
	int i = 0;
	Key* k = NULL;
	while((k = keys->get(i++)) != NULL){
		std::cout << k->name << std::endl;
		if(k->name == name) return k->pressed;
	}
	return KEYBOARD_KEY_NOT_FOUND;
}

/*
 *	Searches the keybind list by name and returns whether that key has just been released.
 *	Alternatively returns a KEYBOARD_KEY_NOT_FOUND error code.
 */
int Keyboard::released(std::string name){
	int i = 0;
	Key* k = NULL;
	while((k = keys->get(i++)) != NULL){
		if(k->name == name) return k->released;
	}
	return KEYBOARD_KEY_NOT_FOUND;
}

/*
 *	Searches the keybind list by name and returns whether that key is being held.
 *	Alternatively returns a KEYBOARD_KEY_NOT_FOUND error code.
 */
int Keyboard::held(std::string name){
	int i = 0;
	Key* k = NULL;
	while((k = keys->get(i++)) != NULL){
		if(k->name == name) return k->state;
	}
	return KEYBOARD_KEY_NOT_FOUND;
}

/*
 *	Searches the keybind list by name and removes it if it exists.
 */
void Keyboard::removeKey(std::string name){
	int i = 0;
	Key* k = NULL;
	while((k = keys->get(i++)) != NULL){
		if(k->name == name) keys->remove(i);
	}
}
/*
 *	Clears all keybinds.
 */
void Keyboard::clear(){
	keys->clear();
}
