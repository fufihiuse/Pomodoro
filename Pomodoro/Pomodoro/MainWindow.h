#pragma once
#include <wx/wx.h>
#include <vector>
#include <thread>
#include "Task.h"

class MainWindow : public wxFrame
{
private:
	enum State { WORK, BREAK };
	State state;
	std::vector<Task> tasks;
	std::thread timerThread;

	int currentTime;
	bool timerActive;

	wxStaticText* timerText;
	wxTextCtrl* textInput;
	wxButton* button;
	wxFont font;

public:
	MainWindow(const wxString& title, wxPoint point, int sizeX, int sizeY);

private:
	void StartTimer();
	void StopTimer(wxCommandEvent& event);
	void OnTomatoClick(wxCommandEvent& event);
	void OnTimerChange(wxCommandEvent& event);
	void OnAddTask(wxCommandEvent& event);
	void OnWindowClose(wxCloseEvent& event);
};

