#ifndef _SNAKE_HPP
#include "../include/snake.hpp"
#define _SNAKE_HPP
#endif
#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif

Snake::Snake(Point* position, int size){
	this->position = position;
	this->direction = new Point(-1, 0);
	positions = new Queue<Point>();
	this->size = size;

	PaletteBuilder* builder = PaletteBuilder::getInstance();
	this->pal_alive = builder->emptyPalette("pal_alive");;
	this->pal_dead = builder->emptyPalette("pal_dead");;
}

Snake::~Snake(){
	delete position;
	delete direction;
	delete positions;
}

int Snake::getSize() {return size;}
bool Snake::isAlive() {return alive;}

void Snake::setColor(Color* color, int segmentCount){
	int r = color->r;
	int g = color->g;
	int b = color->b;

	int r_min = r / 4;
	int g_min = g / 4;
	int b_min = b / 4;

	Color* c_alive = color;
	Color* c_dead = new Color(r_min, g_min, b_min);
	Color* c_edge = new Color(2*r_min, 2*g_min, 2*b_min);

	PaletteBuilder* pb = PaletteBuilder::getInstance();
	this->pal_alive = pb->fromGradient("pal_alive", c_edge, c_alive, segmentCount);
	this->pal_dead = pb->fromGradient("pal_dead", c_dead, c_edge, segmentCount);

}

void Snake::setDirection(SnakeDirection direction){
	if(alive){
		switch(direction){
			case SNAKE_LEFT:
				if(sdirection == SNAKE_RIGHT) 
					return;
				this->direction->set(-1, 0);
				break;
			case SNAKE_RIGHT:
				if(sdirection == SNAKE_LEFT) 
					return;
				this->direction->set(1, 0);
				break;
			case SNAKE_UP:
				if(sdirection == SNAKE_DOWN) 
					return;
				this->direction->set(0, -1);
				break;
			case SNAKE_DOWN:
				if(sdirection == SNAKE_UP) 
					return;
				this->direction->set(0, 1);
				break;
		}
		sdirection = direction;
	}
}

void Snake::move(){
	if(alive){
		positions->add(new Point(position->getX(), position->getY()));
		position->set(
			(position->getX() + direction->getX() + GLOBAL_GRID_WIDTH()) % GLOBAL_GRID_WIDTH(),
			(position->getY() + direction->getY() + GLOBAL_GRID_HEIGHT()) % GLOBAL_GRID_HEIGHT()
		);
	
		if(positions->contains(position)){
			std::cout << "Snek ded" <<  std::endl;
			alive = false;
		}
	
		while(positions->size() > size)
			positions->remove();
	}
}

bool Snake::eatApple(Point* apple){
	if(alive){
		if(*position == *apple){
			size++;
			return true;
		}
	}
	return false;
}

void Snake::render(GridRenderer* renderer){
	Palette* palette = (alive)? pal_alive : pal_dead;
	Point* segment;
	int i = 0;
	int pal_size = palette->size();
	while((segment = positions->get(i++)) != NULL){
		Color* color = palette->getByIndex(i % pal_size);
		renderer->add(segment, color);
	}
	renderer->add(position, pal_alive->getByIndex(pal_size-1));
}
