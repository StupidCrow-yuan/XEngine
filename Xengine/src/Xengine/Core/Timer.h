//
// Created by yuan on 11/21/22.
//

#ifndef XENGINEMAIN_TIMER_H
#define XENGINEMAIN_TIMER_H

#include <chrono>

namespace XEngine {
    class Timer
    {
    public:
        Timer()
        {
            Reset();
        }

        void Reset()
        {
            m_Start = std::chrono::high_resolution_clock::now();//high_resolution_clock的精度是1纳秒，用户系统的当前时间，以秒为单位
        }

        float Elapsed()
        {
            //小时: 1 hours = 60 minutes; 分钟: 1 minutes = 60 seconds;  秒：1 seconds = 1000 milliseconds; 毫秒: 1 milliseconds = 1000 microseconds; 微秒：1 microseconds = 1000 nanoseconds 纳秒
            return std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now() - m_Start).count() * 0.001f * 0.001f * 0.001f;//返回纳秒
        }

        float ElapsedMillis()
        {
            return Elapsed() * 1000.0f;//返回微秒
        }

    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> m_Start;
    };
}

#endif //XENGINEMAIN_TIMER_H
