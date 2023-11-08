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

	window->alterKeyboard(
			KB_ADD,
			static_cast<void*>(&vk_left)
	);
	window->alterKeyboard(
			KB_ADD,
			static_cast<void*>(&vk_right)
	);

	bool running = true;
	while(running){
		window->update(&running);
		window->processInput();
		window->render();
	}
	
	free(window);

	return 0;
}
