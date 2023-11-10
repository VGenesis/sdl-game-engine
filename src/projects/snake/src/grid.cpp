#ifndef _GRID_HPP
#include "../include/grid.hpp"
#define _GRID_HPP
#endif

GridRenderer::GridRenderer(int originX, int originY, int sizeX, int sizeY){
	this->origin = new Point(originX, originY);
	this->size = new Point(sizeX, sizeY);
	this->elements = new List<Rect>();
}

void GridRenderer::add(Point* p, Color* c){
	Rect* rect = new Rect(
		p->getX() * size->getX(),
		p->getY() * size->getY(),
		size->getX(),
		size->getX()
	);
	rect->setColor(c);
	elements->add(rect);
}

//void GridRenderer::addAll(List<Point>* list, Color c){
//	Point* iter = list;
//	while(*iter++){
//		this->add(*iter, c);
//	}
//}

void GridRenderer::render(SDL_Renderer* renderer){
	Rect* element;
	for(int i = 0; (element = elements->get(i)) != NULL; i++){
		element->renderFill(renderer);
	}
	elements->clear();
}


