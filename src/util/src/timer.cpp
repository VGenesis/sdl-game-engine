#ifndef _TIMER_HPP
#include "../include/timer.hpp"
#define _TIMER_HPP
#endif

Timer::Timer(double time):
	time{time}, currentTime{time}
{};

void Timer::setTime(double time){
	this->time = time;
	this->currentTime = time;
	this->finished = false;
}

double Timer::getTime() {return currentTime;}

void Timer::repeat(){
	setTime(this->time);
}

void Timer::update(double delta){
	if(!finished){
		currentTime -= delta;
		if(currentTime <= 0.0){
			justFinished = true;
			finished = true;
		}
	}
}

bool Timer::isFinished() {
	bool res = justFinished;
	justFinished = false;
	return res;
}
