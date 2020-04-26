#ifndef DISTANCE_H
#define DISTANCE_H

#include<Arduino.h>

class Distance{
	private:
		int
			trigg,
			echo;
		float
			lastDistance;
		unsigned long
			startTime,
			endTime,
			distanceTime,
			readInterval,
			lastRead;
		bool
			autoTime,
			samePin;
	public:
		Distance(int _echo, int trigg);
		Distance(int _pin);
		void begin();
		float getDistance();
		void setAutoTime(unsigned long _readInterval);
		void setAuto(bool _autoTime);
		void loop();
};

Distance::Distance(int _echo, int trigg){
	this->echo = _echo;
	this->trigg = _trigg;
	if(echo == trigg){
		samePin = true;
	}
	else{
		samePin = false;
	}
	
}

Distance::Distance(int _pin){
	this->echo = _pin;
	this->trigg = _pin;
	samePin = true;
}

void Distance::begin(){
	if(!samePin){
		pinMode(echo, INPUT);
		pinMode(trigg, OUTPUT);
	}
}

float Distance::getDistance(){
	float distance = 0;
	if(samePin){
		pinMode(trigg, OUTPUT);
	}
	digitalWrite(trig, LOW);
	delayMicroseconds(2);
	digitalWrite(trigg, HIGH);
	delayMicroseconds(10);
	digitalWrite(trigg, LOW);
	if(samePin){
		pinMode(echo, INPUT);
	}
	duration = pulseIn(echo, HIGH);
	distance= duration*0.034/2;

	return distance;
}

void Distance::setAutoTime(unsigned long _readInterval){

}

void Distance::setAuto(bool _autoTime){
	autoTime = _autoTime;
}

void Distance::loop(){
	if(autoTime && (millis() - lastRead > readInterval)){
		lastDistance = getDistance();
	}

}
#endif