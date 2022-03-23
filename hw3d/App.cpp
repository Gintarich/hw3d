#include "App.h"

App::App()
	:
	m_wnd( 800,600,"The Donkey Fart Box" )
{
}

int App::Go()
{
	while( true )
	{
		// process all messages pending, but to not block for new messages
		// ProcessMessages->std::optional, that overrides bool, if true then optional is not empty
		if( const auto ecode = Window::ProcessMessages() )
		{
			// if return optional has value, means we're quitting so return exit code
			return *ecode;
		}
		DoFrame();
	}
}

void App::DoFrame()
{
	// Test code
	const float c = sin(m_timer.Peek()) / 2.0f + 0.5f;
	m_wnd.Gfx().ClearBuffer(c, c, 1.0f);
	m_wnd.Gfx().DrawTestTriangle(
		-m_timer.Peek(),
		0.0f,
		0.0f
	);
	m_wnd.Gfx().DrawTestTriangle( 
		m_timer.Peek(),
		m_wnd.mouse.GetPosX() / 400.0f - 1.0f,
		-m_wnd.mouse.GetPosY() / 300.0f + 1.0f
	);
	//**********
	m_wnd.Gfx().EndFrame();
}
