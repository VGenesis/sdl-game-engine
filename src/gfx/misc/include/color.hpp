class Color{
	public:
		int r{0};
		int g{0};
		int b{0};
		int a{255};

		Color(int r, int g, int b);
		Color(int r, int g, int b, int a);
};

Color* const c_white =	new Color(255, 255, 255);
Color* const c_gray =	new Color(127, 127, 127);
Color* const c_black =	new Color(0, 0, 0);
Color* const c_red =	new Color(255, 0, 0);
Color* const c_green =	new Color(0, 255, 0);
Color* const c_blue =	new Color(0, 0, 255);
