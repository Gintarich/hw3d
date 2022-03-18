#include "Mouse.h"

std::pair<int, int> Mouse::GetPos() const noexcept
{
	return{ m_x,m_y };
}

int Mouse::GetPosX() const noexcept
{
	return m_x;
}

int Mouse::GetPosY() const noexcept
{
	return m_y;
}

bool Mouse::IsInWindow() const noexcept
{
	return m_isInWindow;
}

bool Mouse::LeftIsPressed() const noexcept
{
	return m_leftIsPressed;
}

bool Mouse::RightIsPressed() const noexcept
{
	return m_rightIsPressed;
}

Mouse::Event Mouse::Read() noexcept
{
	if( m_buffer.size() > 0u )
	{
		auto e = m_buffer.front();
		m_buffer.pop();
		return e;
	}
	else
	{
		return { };
	}
}

void Mouse::Flush() noexcept
{
	m_buffer = std::queue<Event>();
}

void Mouse::OnMouseMove(int x, int y) noexcept
{
	m_x = x;
	m_y = y;
	m_buffer.push({ Mouse::Event::Type::Move, *this });
	TrimBuffer();
}

void Mouse::OnMouseLeave() noexcept
{
	m_isInWindow = false;
	m_buffer.push({ Mouse::Event::Type::Leave, *this });
	TrimBuffer();
}

void Mouse::OnMouseEnter() noexcept
{
	m_isInWindow = true;
	m_buffer.push({ Mouse::Event::Type::Enter, *this });
	TrimBuffer();
}

void Mouse::OnLeftPressed(int x, int y) noexcept
{
	m_leftIsPressed = true;

	m_buffer.push({ Mouse::Event::Type::LPress, *this });
	TrimBuffer();
}

void Mouse::OnLeftReleased(int x, int y) noexcept
{
	m_leftIsPressed = false;

	m_buffer.push({ Mouse::Event::Type::LRelease, *this });
	TrimBuffer();
}

void Mouse::OnRightPressed(int x, int y) noexcept
{
	m_rightIsPressed = true;

	m_buffer.push({ Mouse::Event::Type::RPress, *this });
	TrimBuffer();
}

void Mouse::OnRightReleased(int x, int y) noexcept
{
	m_rightIsPressed = false;

	m_buffer.push({ Mouse::Event::Type::RRelease, *this });
	TrimBuffer();
}

void Mouse::OnWheelUp(int x, int y) noexcept
{
	m_buffer.push({ Mouse::Event::Type::WheelUp, *this });
	TrimBuffer();
}

void Mouse::OnWheelDown(int x, int y) noexcept
{
	m_buffer.push({ Mouse::Event::Type::WheelDown, *this });
	TrimBuffer();
}

void Mouse::TrimBuffer() noexcept
{
	while( m_buffer.size() > m_bufferSize )
	{
		m_buffer.pop();
	}
}


