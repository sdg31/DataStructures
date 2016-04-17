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
    void reset();
    int pause();
    int duration();
    
};

//begin counting time
inline void StopWatch::start() {
    _last = Time::now();
}

//stop recording and return the elapsed time
inline int StopWatch::pause() {
    Time::duration temp = Time::now() - _last;
    _duration += temp;
    return std::chrono::duration_cast<ns>(temp).count();
}

inline int StopWatch::duration() {
    return std::chrono::duration_cast<ns>(_duration).count();
}

inline void StopWatch::reset() {
    _duration = Time::duration::zero();
}

#endif
