#ifndef _SDL_H
#include <SDL2/SDL.h>
#define _SDL_H
#endif
#ifndef _MOUSE_HPP
#include "../include/mouse.hpp"
#define _MOUSE_HPP
#endif

void Mouse::updateEvent(SDL_Event event) {
	int button, move;
	switch(event.type){
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&mouse_x, &mouse_y);
			break;
		case SDL_MOUSEBUTTONDOWN:
			button = event.button.button;
			switch(button){
				case SDL_BUTTON_LEFT:	lclick_hold = true; break;
				case SDL_BUTTON_RIGHT:	rclick_hold = true; break;
				case SDL_BUTTON_MIDDLE:	mclick_hold = true; break;
			}
			break;
		case SDL_MOUSEBUTTONUP:
			button = event.button.button;
			switch(button){
				case SDL_BUTTON_LEFT:	lclick_hold = false; break;
				case SDL_BUTTON_RIGHT:	rclick_hold = false; break;
				case SDL_BUTTON_MIDDLE: mclick_hold = false; break;
			}
			break;
		case SDL_MOUSEWHEEL:
			move = event.wheel.y;
			mwheel_up =		(move > 0)? move : 0;
			mwheel_down =	(move < 0)? move : 0;
			break;
	}
}
void Mouse::updateTick(){
	lclick_pressed = (!lclick_prev && lclick_hold);
	rclick_pressed = (!rclick_prev && rclick_hold);
	mclick_pressed = (!mclick_prev && mclick_hold);

	lclick_released = (lclick_prev && !lclick_hold);
	rclick_released = (rclick_prev && !rclick_hold);
	mclick_released = (mclick_prev && !mclick_hold);

	lclick_prev = lclick_hold;
	rclick_prev = rclick_hold;
	mclick_prev = mclick_hold;
}
