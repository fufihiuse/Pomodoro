#include "Pomodoro.h"
#include "MainWindow.h"
#include <wx/wx.h>

wxIMPLEMENT_APP(Pomodoro);


bool Pomodoro::OnInit()
{
	// Create window
	MainWindow* window = new MainWindow("Pomodoro", wxDefaultPosition, 400, 600);

	window->Show();
	return true;
}