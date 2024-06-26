#ifndef _TIMER_H
#define _TIMER_H
#include <SDL.h>

class Timer {

private:

    static Timer* sTimer;

    unsigned int mStartTicks;
    unsigned int mElapsedTicks;
    float mDeltaTime;
    float mTimeScale;

public:

    static Timer* Instance();
    static void Release();

    void Reset();
    float DeltaTime();

    void TimeScale(float t);
    float TimeScale();

    void Update();

private:

    // Constructor
    Timer();
    // Deconstructor
    ~Timer();
};

#endif