//
// Created by yuan on 5/3/22.
//

#ifndef XENGINEMAIN_TIMESTEP_H
#define XENGINEMAIN_TIMESTEP_H

namespace XEngine {
    class Timestep
    {
    public:
        Timestep(float time = 0.0f) : m_Time(time)
        {
        }
        operator float() const { return m_Time; }

        float GetSeconds() const { return m_Time; }
        float GetMilliseconds() const { return m_Time; }

    private:
        float m_Time;
    };
}

#endif //XENGINEMAIN_TIMESTEP_H
