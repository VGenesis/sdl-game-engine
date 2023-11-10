class Timer{
	private:
		double time {0.0};
		double currentTime {0.0};
		bool finished {false};
		bool finishedPrev {false};
		bool justFinished {false};
		
	public:
		Timer(double time);
		void setTime(double time);
		double getTime();
		void repeat();
		void update(double delta);
		bool isFinished();
};
