#pragma once

#include "Animation.h"

Animation::Animation() : timer(0), frameCount(0) {}
    
Animation::Animation(int frameCount, float length) : timer(length), frameCount(frameCount) {}

float Animation::GetLength() { return this->timer.GetLength(); }

int Animation::CurrentFrame() {
    return static_cast<int>(timer.GetTime() / timer.GetLength() * this->frameCount);
}

void Animation::Step(float deltaTime) { this->timer.Step(deltaTime); }