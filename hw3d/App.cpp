#include "App.h"

App::App()
	:
	m_wnd( 800,600,"The Donkey Fart Box")
{
}

int App::Go()
{
	MSG msg;
	BOOL gResult;
	while( ( gResult = GetMessage(&msg, nullptr, 0, 0) ) > 0 )
	{
		// TranslateMessage will post auxilliary WM_CHAR messages from key msgs
		TranslateMessage(&msg);
		DispatchMessage(&msg);

		DoFrame();
	}
	// check if GetMessage call itself worked
	if( gResult == -1 )
	{
		throw CHWND_LAST_EXCEPT();
	}

	// wParam here is the value passed to PostQuitMessage
	return msg.wParam;
}

void App::DoFrame()
{
	const float t = m_timer.Peek();
	std::ostringstream oss;
	oss << "Time elapsed: " << std::setprecision(1) << std::fixed << t << "s";
	m_wnd.SetTitle(oss.str());
}
