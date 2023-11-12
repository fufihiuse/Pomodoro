#pragma once
#include <wx/wx.h>

class MainWindow : public wxFrame
{
	wxSize winSize;
public:
	MainWindow(const wxString& title, wxPoint point, int sizeX, int sizeY);
};

