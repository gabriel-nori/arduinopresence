#include "./Libraries/Distance/Distance.h"
#include "./Libraries/Timer/Timer.h"

//Pin association:
#define pir 4
#define echo 5
#define trigg 6
#define door 7
#define light 8
#define fan 9

//Timers intervals:
#define lightInterval 150000
#define fanInterval 300000

Timer lightTimer(light, lightInterval);
Timer fanTimer(fan, fanInterval);

void setup(){

}

void loop(){

}