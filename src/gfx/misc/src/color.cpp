#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif
#ifndef _COLOR_HPP
#include "../include/color.hpp"
#define _COLOR_HPP
#endif

Color::Color(int r, int g, int b) :
	r{r}, g{g}, b{b}
{};

Color::Color(int r, int g, int b, int a) :
	r{r}, g{g}, b{b}, a{a}
{};

Color* Color::clone(){
	return new Color(r, g, b, a);
}

void Color::shift(int r, int g, int b){
	this->r += r;
	this->g += g;
	this->b += b;
}

void Color::print(){
	std::cout << "(" << r << ", " << g << ", " << b << ")";
}
