#pragma once
#include "Window.h"
#include "ChilliTimer.h"

class App
{
public:
	App();
	// master frame / message loop
	int Go();
private:
	void DoFrame();
private:
	Window m_wnd;
	ChilliTimer m_timer;
};

