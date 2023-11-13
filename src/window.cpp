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

	grid = new GridRenderer(0, 0, 16, 16);
	snake = new Snake(new Point(16, 16), 3);
	snakeTimer = new Timer(SNAKE_SPEED(snake->getSize()));

	randomizeColors();
	createApple();
}

Window::~Window(){
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	free(keyboard);
	free(grid);
	free(snake);
	free(snakeTimer);
}

void Window::setTitle(const char* title){
	SDL_SetWindowTitle(window, title);
}

void Window::randomizeColors(){
	srand(time(NULL));
	int i_snake = rand() % 12;
	int i_apple = -1;
	do{
		i_apple = rand() % 12;
	}while(i_apple == i_snake);

	Color* colors[] = {
		c_red,
		c_orange,
		c_yellow,
		c_lime,
		c_green,
		c_teal,
		c_cyan,
		c_sky,
		c_blue,
		c_purple,
		c_magenta,
		c_pink
	};

	snake->setColor(colors[i_snake], 8);
	c_apple = colors[i_apple];
}

void Window::createApple(){
	apple = new Point(
		GRID_RAND_X(),
		GRID_RAND_Y()
	);
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

void Window::updateRealTime(double delta){
	if(snake->isAlive()){
		snakeTimer->update(delta);
		if(snakeTimer->isFinished()){
			snake->move();
			if(snake->eatApple(apple))
			createApple();
			snakeTimer->setTime(SNAKE_SPEED(snake->getSize()));
		}
	}
}

void Window::updateFrame(bool* running){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		switch(event.type){
			case SDL_QUIT:
				*running = false;
				break;
		}
		keyboard->updateEvent(event);
	}
	keyboard->updateTick();
}

void Window::processInput(){
	if(snake->isAlive()){
		if(keyboard->pressed("vk_left") > 0)
			snake->setDirection(SNAKE_LEFT);

		if(keyboard->pressed("vk_right") > 0)
			snake->setDirection(SNAKE_RIGHT);

		if(keyboard->pressed("vk_up") > 0)
			snake->setDirection(SNAKE_UP);

		if(keyboard->pressed("vk_down") > 0)
			snake->setDirection(SNAKE_DOWN);
	}else if(keyboard->pressed("vk_enter") > 0){
		std::cout << "Restart" << std::endl;
		snake = new Snake(new Point(16, 16), 3);
		randomizeColors();
		createApple();
	}
}

void Window::render(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	if(snake) snake->render(grid);
	if(apple) grid->add(apple, c_apple);
	grid->render(renderer);

	SDL_RenderPresent(renderer);
}
