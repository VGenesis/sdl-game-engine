class MouseController{
	private:
		bool lclick_pressed{false}, lclick_released{false}, lclick_hold{false};
		bool rclick_pressed{false}, rclick_released{false}, rclick_hold{false};
		bool mclick_pressed{false}, mclick_released{false}, mclick_hold{false};

		bool lclick_prev{false}, rclick_prev{false}, mclick_prev{false};

		int mwheel_up{0}, mwheel_down{0};

	public:
		void updateEvent(SDL_Event event);
		void updateTick();

		bool getLClick()			{return lclick_hold;}
		bool getLClickPressed()		{return lclick_pressed;}
		bool getLClickReleased()	{return lclick_released;}

		bool getRClick()			{return rclick_hold;}
		bool getRClickPressed()		{return rclick_pressed;}
		bool getRClickReleased()	{return rclick_released;}

		bool getMClick()			{return mclick_hold;}
		bool getMClickPressed()		{return mclick_pressed;}
		bool getMClickReleased()	{return mclick_released;}

		int getMWheelUp()			{return mwheel_up;}	
		int getMWheelDown()			{return mwheel_down;}	
};
