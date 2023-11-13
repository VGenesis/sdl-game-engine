#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif
#ifndef _SDL_H
#include <SDL2/SDL.h>
#define _SDL_H
#endif
#ifndef _COLOR_HPP
#include "../../misc/include/color.hpp"
#define _COLOR_HPP
#endif

class Point{
	private:
		int x, y;
		Color* color {c_white};
	
	public:
		Point(int x, int y);

		int getX();
		int getY();

		void setX(int x);
		void setY(int y);
		void set(int x, int y);
		void set(Point* p);

		bool operator==(Point& other);

		void move(int x, int y);
		void move(Point* p);
		void scale(double scale);

		void render(SDL_Renderer* renderer);

		void print();
};
