#pragma once

class Timer {
    public:
        Timer(float length);
        void Step(float deltaTime);
        bool IsTimedOut();
        float GetTime();
        float GetLength();
        void Reset();
    private:
        float length, time;
        bool timeout;
};