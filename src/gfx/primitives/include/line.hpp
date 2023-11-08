#ifndef _SDL_H
#include <SDL2/SDL.h>
#define _SDL_H
#endif
#ifndef _COLOR_H
#include "color.hpp"
#define _COLOR_H
#endif

class Line{
	private:
		Point p1, p2;
		Color color {Color.white};
	
	public:
		Line(int x1, int y1, int x2, int y2) : p1 {new Point(x1, y1)}, p2 {new Point(x2, y2)}
		{}

		Line(Point p1, Point p2) : p1{p1}, p2{p2} 
		{}

		void render(SDL_Renderer* renderer){
			SDL_RenderDrawLine(renderer
		}
}
