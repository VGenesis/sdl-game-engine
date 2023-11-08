#ifndef _WINDOW_HPP
#include "window.hpp"
#define _WINDOW_HPP
#endif

Window::Window(const char* title, int width, int height){
	window = SDL_CreateWindow(
		title,
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		width,
		height,
		SDL_WINDOW_SHOWN
	);

	renderer = SDL_CreateRenderer(
		window,
		-1,
		SDL_RENDERER_ACCELERATED
	);

	rects = new EXList<Rect>();

	baseColors = new List<Color>();
	baseColors->add(c_white);
	baseColors->add(c_gray);
	baseColors->add(c_black);
	baseColors->add(c_red);
	baseColors->add(c_green);
	baseColors->add(c_blue);

	currentColor = c_red;
	int colorIndex = 0;
}

Window::~Window(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
}

void Window::initMouse(int mouseSize){
	mouse = new Mouse();
	mouseRect = new Rect(0, 0, mouseSize, mouseSize);
	mouseRect->setColor(currentColor);
	this->mouseSize = mouseSize;
}

void Window::initKeyboard(){
	keyboard = new Keyboard();
}

void Window::alterKeyboard(KEYBOARD_OP operation, void* operand){
	Key* newKey;
	char* keyname;

	switch(operation){
		case KB_ADD:
			newKey = static_cast<Key*>(operand);
			keyboard->addKey(newKey->name, newKey->scancode);
			break;

		case KB_REMOVE:
			keyname = (char*) operand;
			keyboard->removeKey(keyname);
			break;

		case KB_CLEAR:	
			keyboard->clear();
			break;
	}
}

void Window::update(bool* running){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				*running = false;
				break;
		}
		mouse->updateEvent(event);
		keyboard->updateEvent(event);
	}

	mouse->updateTick();
	keyboard->updateTick();
}

void Window::processInput(){
	int mx = mouse->getX();
	int my = mouse->getY();
	if(mouse->getLClickPressed()){
		int xblock = mx - mx % mouseSize;
		int yblock = my - my % mouseSize;

		Rect* rect = new Rect(
			xblock,
			yblock,
			mouseSize,
			mouseSize
		);
		rect->setColor(currentColor);
		rects->add(rect);
		std::cout << rects->size() << std::endl;
	}

	if(mouse->getRClickPressed()){
		for(int i = 0; i < rects->size(); i++){
			if(rects->get(i)->inside(mx, my)){
				rects->remove(i);
				i--;
			}
		}
	}

	if(keyboard->pressed("vk_left") > 0){
		colorIndex = (++colorIndex >= baseColors->size())? 0 : colorIndex;
		currentColor = baseColors->get(colorIndex);
		std::cout << currentColor->r << std::endl;
	}

	if(keyboard->pressed("vk_right") > 0){
		colorIndex = (--colorIndex < 0)? baseColors->size()-1 : colorIndex;
		currentColor = baseColors->get(colorIndex);
		std::cout << currentColor->r << std::endl;
	}
}

void Window::render(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	for(int i = 0; i < rects->size(); i++){
		Rect* r = rects->get(i);
		if(r != NULL) r->renderFill(renderer);
	}

	mouseRect->setPosition(new Point(
			mouse->getX() - mouseSize/2,
			mouse->getY() - mouseSize/2
		)
	);
	mouseRect->setColor(currentColor);
	mouseRect->render(renderer);

	SDL_RenderPresent(renderer);
}
