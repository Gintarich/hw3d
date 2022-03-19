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
	const float t = m_timer.Peek();
	std::ostringstream oss;
	oss << "Time elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	m_wnd.SetTitle(oss.str());
}
