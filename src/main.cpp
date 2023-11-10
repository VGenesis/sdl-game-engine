#ifndef _MAIN_H
#include "main.h"
#define _MAIN_H
#endif

int main(int argc, char* argv[]){
	Window* window = new Window(
			WINDOW_TITLE,
			WINDOW_WIDTH,
			WINDOW_HEIGHT
			);

	window->initMouse(MOUSE_RECT_SIZE);
	window->initKeyboard();

	Key vk_left = *(new Key("vk_left", SDL_SCANCODE_LEFT));
	Key vk_right = *(new Key("vk_right", SDL_SCANCODE_RIGHT));
	Key vk_up = *(new Key("vk_up", SDL_SCANCODE_UP));
	Key vk_down = *(new Key("vk_down", SDL_SCANCODE_DOWN));

	window->alterKeyboard(KB_ADD, static_cast<void*>(&vk_left));
	window->alterKeyboard(KB_ADD, static_cast<void*>(&vk_right));
	window->alterKeyboard(KB_ADD, static_cast<void*>(&vk_up));
	window->alterKeyboard(KB_ADD, static_cast<void*>(&vk_down));

	long ticks = SDL_GetTicks();
	long ticks_1s = ticks;
	double delta = 0.0;
	int frames = 0;

	double frameTime = 1.0 / FPS;
	bool running = true;
	while(running){
		long newTicks = SDL_GetTicks();
		double realTime = double(newTicks - ticks) / 1000.0;
		window->updateRealTime(realTime);
		
		delta += realTime * FPS;
		while(delta > frameTime){
			window->updateFrame(&running);
			window->processInput();
			window->render();
	
			delta--;
			frames++;
		}
	
		if(newTicks - ticks_1s > 1000){
			char newTitle[50];
			sprintf(newTitle, "%s | %dfps", WINDOW_TITLE, frames);
			window->setTitle(newTitle);
			frames = 0;
			ticks_1s += 1000;
		}

		ticks = newTicks;
	}
	
	free(window);

	return 0;
}
