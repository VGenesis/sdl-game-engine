#ifndef _GRID_HPP
#include "../include/grid.hpp"
#define _GRID_HPP
#endif
#ifndef _QUEUE_HPP
#include "../../../ds/include/queue.hpp"
#define _QUEUE_HPP
#endif

enum SnakeDirection{
	SNAKE_LEFT,
	SNAKE_RIGHT,
	SNAKE_UP,
	SNAKE_DOWN
};

class Snake{
	private:
		Point* position;
		Point* direction;
		Queue<Point>* positions;

		Color* color;
		int size;
		bool alive {true};
	
	public:
		Snake();
		Snake(Point* position, int size, Color* color);
		~Snake();

		int getSize();
		bool isAlive();

		void setDirection(SnakeDirection direction);
		void move();
		bool eatApple(Point* apple);

		void onFruitCollect();
		void render(GridRenderer* renderer);
};
