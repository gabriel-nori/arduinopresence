#ifndef TIMER_H
#define TIMER_H

#include<Arduino.h>

class Timer{
	private:
		unsigned long
			time,
			startTime,
			endTime;
		int output;
	public:
		Timer(int _output, unsigned long _time);
		void begin();
		void on();
		void off();
		void reset();
		void loop();
};

Timer::Timer(int _output, unsigned long _time){

}

void Timer::begin(){
	pinMode(output, OUTPUT);
}

void Timer::on(){
	digitalWrite(output, HIGH);

}

void Timer::off(){

}

void Timer::reset(){

}

void Timer::loop(){

}
#endif