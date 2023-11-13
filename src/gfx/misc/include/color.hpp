class Color{
	public:
		int r{0};
		int g{0};
		int b{0};
		int a{255};

		Color(int r, int g, int b);
		Color(int r, int g, int b, int a);

		Color* clone();
		void shift(int r, int g, int b);

		void print();
};

Color* const c_white =	new Color(255,	255,	255);
Color* const c_gray =	new Color(127,	127,	127);
Color* const c_black =	new Color(0, 0,	0);

Color* const c_red =		new Color(255, 0, 0);
Color* const c_orange =		new Color(192, 64, 0);
Color* const c_yellow =		new Color(128, 128, 0);
Color* const c_lime =		new Color(64, 192, 0);
Color* const c_green =		new Color(0, 255, 0);
Color* const c_teal =		new Color(0, 192, 64);
Color* const c_cyan =		new Color(0, 128, 128);
Color* const c_sky =		new Color(0, 64, 192);
Color* const c_blue =		new Color(0, 0, 255);
Color* const c_purple =		new Color(64, 0, 192);
Color* const c_magenta =	new Color(128, 0, 128);
Color* const c_pink =		new Color(192, 0, 64);
