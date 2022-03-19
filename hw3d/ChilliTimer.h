#pragma once
#include <chrono>

class ChilliTimer
{
public :
	ChilliTimer() noexcept ;
	float Mark() noexcept ;
	float Peek() const noexcept;
private:
	std::chrono::steady_clock::time_point m_last;
};

