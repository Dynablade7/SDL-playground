#ifndef TIMER_H
#define TIMER_H

/**
 * This class contains a timer that can be started, stopped, paused and unpaused.
 * It is a direct copy of the Timer class in the Lazy Foo SDL tutorial.
 * Web site: http://www.lazyfoo.net/tutorials/SDL/index.php
 */
class Timer {
    public:
        Timer();
        void start();
        void stop();
        void pause();
        void unpause();

        Uint32 getTicks();

        bool isStarted();
        bool isPaused();

    private:

        /**
         * The clock time when the timer was started.
         */
        Uint32 _startTicks;

        /**
         * The ticks stored when the timer was paused.
         */
        Uint32 _pausedTicks;

        /**
         * Timer status.
         */
        bool _started = false, _paused = false;
};

#endif // TIMER_H
