#ifndef _SNAKE_HPP
#include "../include/snake.hpp"
#define _SNAKE_HPP
#endif
#ifndef _GLOBAL_HPP
#include "../../global.hpp"
#define _GLOBAL_HPP
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
}

Snake::~Snake(){
	delete position;
	delete direction;
	delete positions;
}

int Snake::getSize() {return size;}
bool Snake::isAlive() {return alive;}

void Snake::setColor(Color* alive, Color* dead){
	this->c_alive = alive;
	this->c_dead = dead;
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
	Color* color = (alive)? c_alive : c_dead;
	Point* segment;
	int i = 0;
	while((segment = positions->get(i++)) != NULL){
		renderer->add(segment, color);
	}
	renderer->add(position, color);
}
