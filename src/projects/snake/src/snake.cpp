#ifndef _SNAKE_HPP
#include "../include/snake.hpp"
#define _SNAKE_HPP
#endif
#ifndef _GLOBAL_HPP
#include "../../global.hpp"
#define _GLOBAL_HPP
#endif

Snake::Snake(Point* position, int size, Color* color){
	this->position = position;
	this->direction = new Point(-1, 0);
	positions = new Queue<Point>();
	positions->add(new Point(position->getX(), position->getY()));
	this->size = size;
	this->color = color;
}

Snake::~Snake(){
	delete position;
	delete direction;
	delete positions;
	delete color;
}

int Snake::getSize() {return size;}
bool Snake::isAlive() {return alive;}

void Snake::setDirection(SnakeDirection direction){
	if(alive){
		switch(direction){
			case SNAKE_LEFT:
				this->direction->set(-1, 0);
				break;
			case SNAKE_RIGHT:
				this->direction->set(1, 0);
				break;
			case SNAKE_UP:
				this->direction->set(0, -1);
				break;
			case SNAKE_DOWN:
				this->direction->set(0, 1);
				break;
		}
	}
}

void Snake::move(){
//	if(positions->contains(position) > 1) 
//		alive = false;
//	else{
		position->set(
			(position->getX() + direction->getX() + GLOBAL_GRID_WIDTH()) % GLOBAL_GRID_WIDTH(),
			(position->getY() + direction->getY() + GLOBAL_GRID_HEIGHT()) % GLOBAL_GRID_HEIGHT()
		);
		positions->add(new Point(position->getX(), position->getY()));
	
		while(positions->size() > size)
			positions->remove();
//	}
}

bool Snake::eatApple(Point* apple){
	if(alive){
		if(position->getX() == apple->getX() && position->getY() == apple->getY()){
			size++;
			return true;
		}
	}
	return false;
}

void Snake::render(GridRenderer* renderer){
	if(alive){
		Point* position;
		int i = 0;
		while((position = positions->get(i++)) != NULL){
			renderer->add(position, color);
		}
	}
}
