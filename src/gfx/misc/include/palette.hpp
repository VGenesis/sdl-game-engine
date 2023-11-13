#ifndef _COLOR_HPP
#include "color.hpp"
#define _COLOR_HPP
#endif
#ifndef _LIST_HPP
#include "../../../ds/include/list.hpp"
#define _LIST_HPP
#endif

class Palette{
	private:
		int id;
		const char* name;
		List<Color>* colors;
	
	public:
		Palette(int id, const char* name);
		~Palette();

		void addColor(Color* color);
		void removeColor(int index);
		void updateColor(int index, Color* color);

		int size();

		Color* getByIndex(int index);
		Color* getClosest(Color* color);
};
