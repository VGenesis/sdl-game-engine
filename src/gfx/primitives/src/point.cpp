#ifndef _SDL_H
#include <SDL2/SDL.h>
#define _SDL_H
#endif
#ifndef _POINT_HPP
#include "../include/point.hpp"
#define _POINT_HPP
#endif
#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif

Point::Point(int x, int y) :
	x{x}, y{y}
{};

int Point::getX(){
	return x;
}

int Point::getY(){
	return y;
}

void Point::setX(int x){
	this->x = x;
}

void Point::setY(int y){
	this->y = y;
}

void Point::set(int x, int y){
	this->x = x;
	this->y = y;
}

bool Point::operator==(Point& other){
	return(x == other.getX() && y == other.getY());
}

std::ostream& Point::operator<<(std::ostream& outs){
	return outs << "(" << x << ", " << y << ")";
}

void Point::set(Point* p){
	this->x = p->getX();
	this->y = p->getY();
}

void Point::move(int x, int y){
	this->x += x;
	this->y += y;
}

void Point::move(Point* p){
	this->x += p->getX();
	this->y += p->getY();
}

void Point::scale(double scale){
	double intensity = sqrt(pow(x, 2) + pow(y, 2));
	double ratio = atan(y/x);
	this->x = (int)(intensity * scale * cos(ratio));
	this->y = (int)(intensity * scale * sin(ratio));
}

void Point::render(SDL_Renderer* renderer){
	SDL_SetRenderDrawColor(
			renderer,
			this->color->r,
			this->color->g,
			this->color->b,
			SDL_ALPHA_OPAQUE
	);
	SDL_RenderDrawPoint(renderer, x, y);
}

