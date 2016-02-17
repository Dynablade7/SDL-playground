#include <SDL.h>
#include "Timer.h"

Timer::Timer() {
    //ctor
}

void Timer::start() {
    _started = true;
    _paused = false;

    _startTicks = SDL_GetTicks();
    _pausedTicks = 0;
}

void Timer::stop() {
    _started = false;
    _paused = false;
    _startTicks = 0;
    _pausedTicks = 0;
}

void Timer::pause() {
    if (_started && !_paused) {
        _paused = true;
        // Calculate the paused ticks
        _pausedTicks = SDL_GetTicks() - _startTicks;
        _startTicks = 0;
    }
}

void Timer::unpause() {
    if (_started && _paused) {
        _paused = false;
        // Reset the starting ticks
        _startTicks = SDL_GetTicks() - _pausedTicks;
        // Reset the paused ticks
        _pausedTicks = 0;
    }
}

Uint32 Timer::getTicks() {
    // The actual timer time - returns 0 if the timer is not started
    Uint32 time = 0;

    if(_started) {
        if(_paused) {
            // Return the number of ticks when the timer was paused
            time = _pausedTicks;
        } else {
            // Return the current time minus the start time
            time = SDL_GetTicks() - _startTicks;
        }
    }
    return time;
}

bool Timer::isStarted() {
    return _started;
}

bool Timer::isPaused() {
    // For safety, check that the timer is not stopped
    return _paused && _started;
}
