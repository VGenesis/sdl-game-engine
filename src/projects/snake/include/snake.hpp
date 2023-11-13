#ifndef _GRID_HPP
#include "../include/grid.hpp"
#define _GRID_HPP
#endif
#ifndef _QUEUE_HPP
#include "../../../ds/include/queue.hpp"
#define _QUEUE_HPP
#endif
#ifndef _GLOBAL_HPP
#include "../../global.hpp"
#define _GLOBAL_HPP
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
		SnakeDirection sdirection;
		Queue<Point>* positions;

		Palette* pal_alive {NULL};
		Palette* pal_dead {NULL};

		int size;
		bool alive {true};
	
	public:
		Snake();
		Snake(Point* position, int size);
		~Snake();

		int getSize();
		bool isAlive();

		void setColor(Color* color, int segmentCount);

		void setDirection(SnakeDirection direction);
		void move();
		bool eatApple(Point* apple);

		void onFruitCollect();
		void render(GridRenderer* renderer);
};
