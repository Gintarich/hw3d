#pragma once
#include "Graphics.h"
#include "Mouse.h"
#include "Keyboard.h"

class Camera
{
public: 
	Camera(Graphics& gfx, const Mouse& mouse, const Keyboard& kbd) 
		: m_gfx(gfx),m_mouse(mouse),m_kbd(kbd)
	{ }
	void ProcesCamera()
	{
		
	}
	

private:
	Graphics& m_gfx;
	const Mouse& m_mouse;
	const Keyboard& m_kbd;
};
