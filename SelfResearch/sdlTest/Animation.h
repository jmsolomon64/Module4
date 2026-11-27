#pragma once
#include "Timer.h"

enum Animation_State {
    ANIMATION_STATE_IDLE,
    ANIMATION_STATE_WALK,
    Count //This is not meant to be used as an option, but to get total options
};

class Animation {
    public:
        Animation();
        Animation(int frameCount, float length);
        float GetLength();
        int CurrentFrame();
        void Step(float deltaTime);
    private:
        Timer timer;
        int frameCount;
};