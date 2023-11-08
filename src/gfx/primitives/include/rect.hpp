#ifndef _IOSTREAM
#include <iostream>
#define _IOSTREAM
#endif
#ifndef _POINT_HPP
#include "point.hpp"
#define _POINT_HPP
#endif
#ifndef _COLOR_HPP
#include "../../misc/include/color.hpp"
#define _COLOR_HPP
#endif

class Rect{
	private:
		Point* position;	
		Point* size;
		Color* color {c_white};

	public:
		Rect(int x, int y, int w, int h);
		Rect(Point* position, Point* size);

		Point* getPosition();
		Point* getSize();
		Color* getColor();

		bool operator==(Rect& other);

		// Doesn't work
		std::ostream& operator<<(std::ostream& outs);

		void setPosition(Point* position);
		void setSize(Point* size);
		void setColor(Color* color);

		void move(int x, int y);
		void move(Point* v);
		void scale(double scale);

		bool inside(int x, int y);
		bool inside(Point* p);

		void render(SDL_Renderer* renderer);
		void renderFill(SDL_Renderer* renderer);
};

