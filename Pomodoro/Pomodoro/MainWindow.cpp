#include "MainWindow.h"

MainWindow::MainWindow(const wxString& title, wxPoint point, int sizeX, int sizeY) 
	: wxFrame(nullptr, wxID_ANY, title, point, wxSize{sizeX, sizeY})
{
	winSize = { sizeX, sizeY };

	wxPanel* panel = new wxPanel(this); // Fixes auto-sizing
	wxButton* button = new wxButton(panel, wxID_ANY, "Start", wxPoint(sizeX / 2 - 50, 50), wxSize(100, 35));
	wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "Done", wxPoint(sizeX / 2, 100));

}
