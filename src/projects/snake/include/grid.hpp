#ifndef _SDL_H
#include <SDL2/SDL.h>
#define _SDL_H
#endif
#ifndef _LIST_HPP
#include "../../../ds/include/list.hpp"
#define _LIST_HPP
#endif
#ifndef _POINT_HPP
#include "../../../gfx/primitives/include/point.hpp"
#define _POINT_HPP
#endif
#ifndef _RECT_HPP
#include "../../../gfx/primitives/include/rect.hpp"
#define _RECT_HPP
#endif

class GridRenderer{
	private:
		Point* origin;
		Point* size;

		List<Rect>* elements;

	public:
		GridRenderer(int originX, int originY,int sizeX, int sizeY);
		void add(Point* p, Color* c);
		void render(SDL_Renderer* renderer);
};
