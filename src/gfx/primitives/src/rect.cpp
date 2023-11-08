#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif
#ifndef _CMATH
#include <cmath>
#define _CMATH
#endif
#ifndef _SDL_H
#include <SDL2/SDL.h>
#define _SDL_H
#endif
#ifndef _RECT_HPP
#include "../include/rect.hpp"
#define _RECT_HPP
#endif

Rect::Rect(int x, int y, int w, int h){
	this->position = new Point(x, y);
	this->size = new Point(w, h);
}

Rect::Rect(Point* position, Point* size){
	this->position = position;
	this->size = size;
}

Point* Rect::getPosition(){
	return this->position;
}

Point* Rect::getSize(){
	return this->size;
}

Color* Rect::getColor(){
	return this->color;
}

void Rect::setPosition(Point* position){
	this->position->set(position);
}

void Rect::setSize(Point* size){
	this->size->set(size);
}

void Rect::setColor(Color* color){
	this->color = color;
}

bool Rect::operator==(Rect& other){
	return(position == other.getPosition() && size == other.getSize());
}

std::ostream& Rect::operator<<(std::ostream& outs){
	return outs << "[" << position << ", " << size << "]";
}

void Rect::move(int x, int y){
	this->position->move(x, y);
}

void Rect::move(Point* p){
	this->position->move(p);
}

void Rect::scale(double scale){
	this->size->scale(scale);
}

bool Rect::inside(int x, int y){
	int rx = this->position->getX();
	int ry = this->position->getY();
	
	return( 
			x > rx &&
			y > ry &&
			x < rx + this->size->getX() &&
			y < ry + this->size->getY()
		  );
}

bool Rect::inside(Point* p){
	return inside(p->getX(), p->getY());
}

void Rect::render(SDL_Renderer* renderer){
	SDL_SetRenderDrawColor(
			renderer,
			this->color->r,
			this->color->g,
			this->color->b,
			SDL_ALPHA_OPAQUE
			);

	SDL_Rect rect = {
		this->position->getX(),
		this->position->getY(),
		this->size->getX(),
		this->size->getY()
	};

	SDL_RenderDrawRect(renderer, &rect);
}

void Rect::renderFill(SDL_Renderer* renderer){
	SDL_SetRenderDrawColor(
			renderer,
			this->color->r,
			this->color->g,
			this->color->b,
			SDL_ALPHA_OPAQUE
			);

	SDL_Rect rect = {
		this->position->getX(),
		this->position->getY(),
		this->size->getX(),
		this->size->getY()
	};

	SDL_RenderFillRect(renderer, &rect);
}

