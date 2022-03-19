#include "ChilliTimer.h"

using namespace std::chrono;

ChilliTimer::ChilliTimer()
{
    m_last = steady_clock::now();
}

float ChilliTimer::Mark()
{
    const auto old = m_last;
    m_last = steady_clock::now();
    const duration<float> frameTime = m_last - old;
    return frameTime.count();
}

float ChilliTimer::Peek() const
{
    return duration<float>(steady_clock::now() - m_last).count();
}
