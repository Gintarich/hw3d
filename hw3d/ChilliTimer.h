#pragma once
#include <chrono>

class ChilliTimer
{
public :
	ChilliTimer();
	float Mark();
	float Peek() const;
private:
	std::chrono::steady_clock::time_point m_last;
};

