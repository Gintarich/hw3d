#pragma once
#include<utility>
#include <queue>

class Mouse
{
	friend class Window;
public:
	class Event
	{
	public:
		enum class Type
		{
			LPress,
			LRelease,
			RPress,
			RRelease,
			WheelUp,
			WheelDown,
			WheelPressed,
			WheelUnpressed,
			Move,
			Enter,
			Leave,
			Invalid
		};
	private:
		Type m_type;
		bool m_leftIsPressed;
		bool m_rightIsPressed;
		bool m_wheelIsPressed;
		int m_x;
		int m_y;
	public:
		Event() noexcept
			:
			m_type(Type::Invalid),
			m_leftIsPressed(false),
			m_rightIsPressed(false),
			m_wheelIsPressed(false),
			m_x(0),
			m_y(0)
		{ }
		Event(Type type , const Mouse& parent) noexcept
			:
			m_type(type),
			m_leftIsPressed(parent.m_leftIsPressed),
			m_rightIsPressed(parent.m_rightIsPressed),
			m_wheelIsPressed(parent.m_wheelIsPressed),
			m_x(parent.m_x),
			m_y(parent.m_y)
		{ }
			
		bool IsValid() const noexcept
		{
			return m_type != Type::Invalid;
		}
		Type GetType() const noexcept
		{
			return m_type;
		}
		std::pair<int, int> GetPos() const noexcept
		{
			return { m_x,m_y };
		}
		int GetPosX() const noexcept
		{
			return m_x;
		}
		int GetPosY() const noexcept
		{
			return m_y;
		}
		bool LeftIsPressed() const noexcept
		{
			return m_leftIsPressed;
		}
		bool RightIsPressed() const noexcept
		{
			return m_rightIsPressed;
		}
		bool WheelIsPressed() const noexcept
		{
			return m_wheelIsPressed;
		}
	};
public:
	Mouse() = default;
	Mouse(const Mouse&) = delete;
	Mouse& operator=(const Mouse&) = delete;
	std::pair<int, int> GetPos() const noexcept;
	int GetPosX() const noexcept;
	int GetPosY() const noexcept;
	bool IsInWindow() const noexcept;
	bool LeftIsPressed() const noexcept;
	bool RightIsPressed() const noexcept;
	Mouse::Event Read() noexcept;
	bool IsEmpty() const noexcept
	{
		return m_buffer.empty();
	}
	void Flush() noexcept;
private:
	void OnMouseMove(int x, int y)noexcept;
	void OnMouseLeave() noexcept;
	void OnMouseEnter() noexcept;
	void OnLeftPressed(int x, int y)noexcept;
	void OnLeftReleased(int x, int y)noexcept;
	void OnRightPressed(int x, int y)noexcept;
	void OnRightReleased(int x, int y)noexcept;
	void OnWheelPressed(int x, int y)noexcept;
	void OnWheelReleased(int x, int y)noexcept;
	void OnWheelUp(int x, int y)noexcept;
	void OnWheelDown(int x, int y)noexcept;
	void TrimBuffer() noexcept;
	void OnWheelDelta(int x, int y, int delta);
private:
	static constexpr unsigned int m_bufferSize = 16u;
	int m_x;
	int m_y;
	int m_dx;
	int m_dy;
	bool m_leftIsPressed = false;
	bool m_rightIsPressed = false;
	bool m_wheelIsPressed = false;
	bool m_isInWindow = false;
	int m_wheelDeltaCarry = 0;
	std::queue<Event> m_buffer;
};

