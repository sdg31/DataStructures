// Tyler Harbert, Feb 2016
// this class can be used to easily keep track of execution times

#ifndef STOPWATCH_HPP
#define STOPWATCH_HPP

#include <chrono>

typedef std::chrono::high_resolution_clock Time;
typedef std::chrono::nanoseconds ns;

class StopWatch {
private:
    Time::time_point _last;
    Time::duration _duration;
    
public:
    void start();
    int pause();
    int duration();
    
};

inline void StopWatch::start() {
    _last = Time::now();
}

inline int StopWatch::pause() {
    _duration += Time::now() - _last;
    return this->duration();
}

inline int StopWatch::duration() {
    return std::chrono::duration_cast<ns>(_duration).count();
}

#endif
