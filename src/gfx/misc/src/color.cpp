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

