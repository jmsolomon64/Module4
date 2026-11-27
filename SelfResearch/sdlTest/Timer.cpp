#include "Timer.h"

Timer::Timer(float length) : length(length), time(0), timeout(false) {}

void Timer::Step(float deltaTime) {
    this->time += deltaTime;
    if(this->time >= this->length) {
        this->time -= length;
    } 
}

bool Timer::IsTimedOut() { return this->timeout; }

float Timer::GetTime() { return this->time; }

float Timer::GetLength() { return this->length;}

void Timer::Reset() { this->time = 0; }