#ifndef _PALETTE_HPP
#include "../include/palette.hpp"
#define _PALETTE_HPP
#endif

class PaletteBuilder{
	protected:
		int global_id = 0;

		/*
		 *	Protected constructor and singleton instance to ensure design properties 
		 */
		PaletteBuilder(): global_id{0} {}
		static PaletteBuilder* __builder;

	public:
		/*
		 *	Singleton instance must not be cloneable or reassignable
		 */
		PaletteBuilder(PaletteBuilder& other) = delete;
		void operator=(const PaletteBuilder&) = delete;

		static PaletteBuilder* getInstance();

		Palette* emptyPalette(const char* name);
		Palette* fromGradient(const char* name, Color* from, Color* to, int count);
		Palette* fromArray(const char* name, int n, Color** colors);
		Palette* fromList(const char* name, List<Color>* list);
};

