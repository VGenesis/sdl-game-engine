#ifndef _PALETTE_HPP
#include "../include/palette.hpp"
#define _PALETTE_HPP
#endif
#ifndef _CMATH
#include <cmath>
#define _CMATH
#endif

Palette::Palette(int id, const char* name){
	this->id = id;
	this->name = name;
	this->colors = new List<Color>();
}

Palette::~Palette(){
		free(colors);
}

void Palette::addColor(Color* color){
	colors->add(color);
}

void Palette::removeColor(int index){
	colors->remove(index);
}

void Palette::updateColor(int index, Color* color){
	Color* target = colors->get(index);
	if(target != NULL){
		target->r = color->r;
		target->g = color->g;
		target->b = color->b;
	}
}

int Palette::size(){
	return colors->size();
}

Color* Palette::getByIndex(int index){
	return colors->get(index);
}

Color* Palette::getClosest(Color* color){
	Color* target = NULL;
	int i = 0;
	int mindiff = 3*256;
	Color* iter = NULL;
	while((iter = colors->get(i++)) != NULL){
		int diff = 0;
		diff += abs(color->r - iter->r);
		diff += abs(color->g - iter->g);
		diff += abs(color->b - iter->b);
		if(diff < mindiff){
			target = iter;
			mindiff = diff;
		}
	}
	return target;
}

