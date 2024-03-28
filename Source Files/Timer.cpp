#include "../Header Files/Timer.h"

Timer* Timer::sTimer = NULL;

// Create Timer instance if it doesn't exist, otherwise return existing instance of Timer
Timer* Timer::Instance() {

    if(sTimer == NULL)
        sTimer = new Timer();

    return sTimer;
}

// Delete Timer and set sTimer (pointer, type - Singleton) to NULL
void Timer::Release() {

    delete sTimer;
    sTimer = NULL;
}

// Constructor
Timer::Timer() {

    Reset();
    mTimeScale = 1.0f;
}

// Deconstructor
Timer::~Timer() {

}

void Timer::Reset() {

    mStartTicks = SDL_GetTicks();
    mElapsedTicks = 0;
    mDeltaTime = 0.0f;
}

float Timer::DeltaTime() {

    return mDeltaTime;
}

void Timer::TimeScale(float t) {

    mTimeScale = t;
}

float Timer::TimeScale() {

    return mTimeScale;
}

void Timer::Update() {

    mElapsedTicks = SDL_GetTicks() - mStartTicks;
    mDeltaTime = mElapsedTicks * 0.001f;
}