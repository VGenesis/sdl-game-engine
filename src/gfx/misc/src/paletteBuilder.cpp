#ifndef _PALETTEBUILDER_HPP
#include "../include/paletteBuilder.hpp"
#define _PALETTEBUILDER_HPP
#endif

PaletteBuilder* PaletteBuilder::__builder = nullptr;

PaletteBuilder* PaletteBuilder::getInstance(){
	if(__builder == nullptr){
		__builder = new PaletteBuilder();
	}
	return __builder;
}

Palette* PaletteBuilder::emptyPalette(const char* name){
	return new Palette(global_id++, name);
}

Palette* PaletteBuilder::fromGradient(const char* name, Color* from, Color* to, int count){
	int rdiff = to->r - from->r;
	int gdiff = to->g - from->g;
	int bdiff = to->b - from->b;


	int n = count - 1;
	float r_inc = static_cast<float>(rdiff) / (count - 1);
	float g_inc = static_cast<float>(gdiff) / (count - 1);
	float b_inc = static_cast<float>(bdiff) / (count - 1);

	std::cout << r_inc << " " << g_inc << " " << b_inc << std::endl;

	Palette* palette = new Palette(global_id, name);
	Color* color = from->clone();
	for(int i = 0; i < count; i++){
		color->print();
		palette->addColor(color->clone());
		color->shift(r_inc, g_inc, b_inc);	
	}

	this->global_id++;
	return palette;
}

Palette* PaletteBuilder::fromArray(const char* name, int count, Color** colors){
	Palette* palette = new Palette(this->global_id, name);

	for(int i = 0; i < count; i++)
		palette->addColor(colors[i]);

	this->global_id++;
	return palette;
}

Palette* PaletteBuilder::fromList(const char* name, List<Color>* list){
	Palette* palette = new Palette(global_id, name);
	Color* c;
	int i = 0;
	while((c = list->get(i++)) != NULL)
		palette->addColor(c);

	this->global_id++;
	return palette;
}
