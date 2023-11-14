#include "MainWindow.h"
//#include <thread>

wxDEFINE_EVENT(pomoEVT_TIMER_START, wxCommandEvent);
wxDEFINE_EVENT(pomoEVT_TIMER_END, wxCommandEvent);

MainWindow::MainWindow(const wxString& title, wxPoint point, int sizeX, int sizeY)
	: wxFrame(nullptr, wxID_ANY, title, point, wxSize{ sizeX, sizeY })
{
	// Setup initial variables
	tasks = std::vector<Task>();
	state = State::WORK;
	currentTime = 25;
	timerActive = false;

	// Set font
	font = this->GetFont();
	font.SetPointSize(20);
	this->SetFont(font);

	// Setup windows
	wxPanel* panel = new wxPanel(this); // Fixes auto-sizing
	button = new wxButton(panel, wxID_ANY, "Start", wxPoint(sizeX / 2 - 50, 50), wxSize(100, 35));
	timerText = new wxStaticText(panel, wxID_ANY, wxString::Format(wxT("%i"), currentTime), wxPoint(0, 10), wxSize(sizeX, 30), wxTE_CENTER);

	//wxCheckBox* checkBox = new wxCheckBox(panel, wxID_ANY, "Done", wxPoint(sizeX / 2, 100));
	textInput = new wxTextCtrl(	panel, wxID_ANY, wxEmptyString, wxPoint(sizeX / 2 - 175, sizeY - 100), wxSize(350, 25), wxTE_PROCESS_ENTER);

	// Bind events
	button->Bind(wxEVT_BUTTON, &MainWindow::OnTomatoClick, this);
	textInput->Bind(wxEVT_TEXT_ENTER, &MainWindow::OnAddTask, this);
	this->Bind(wxEVT_CLOSE_WINDOW, &MainWindow::OnWindowClose, this);
	//this->Bind(pomoEVT_TIMER_START, &MainWindow::StartTimer, this);
	//this->Bind(pomoEVT_TIMER_END, &MainWindow::StopTimer, this);

	//CreateStatusBar();
}

void MainWindow::StartTimer()
{
	timerActive = true;
	button->SetLabelText("Stop");

	int i = 0;

	// Count down
	while(timerActive && i < INT_MAX)
	{
		timerText->SetLabelText(wxString::Format(wxT("%i"), i++));
	}

	// Check if stopped manually
	if (!timerActive)
	{
		// Ended early
	}
	else
	{
		// Ended normally
		timerActive = false;
	}
}

void MainWindow::StopTimer()
{
	// TODO: kill thread + update text
	timerActive = false;
	button->SetLabelText("Start");
}

void MainWindow::HandleTimer()
{
	
}

void MainWindow::OnTomatoClick(wxCommandEvent& event)
{
	if (timerActive)
		StopTimer();
	else
	{
		timerThread = std::thread(&MainWindow::StartTimer, this);
		timerThread.detach();	// We don't care about the thread returning anything, async is more important
	}

}

void MainWindow::OnTimerChange(wxCommandEvent& event)
{
}

void MainWindow::OnAddTask(wxCommandEvent& event)
{
	if (textInput->IsModified())
	{
		wxString text = textInput->GetValue();
		tasks.push_back(Task(text, Task::Priority::MEDIUM));
		textInput->SetValue("");
		textInput->DiscardEdits();
	}
}

void MainWindow::OnWindowClose(wxCloseEvent& event)
{
	wxMessageDialog* dialog = new wxMessageDialog(NULL, "Would you like to save these tasks for next time?", 
		"You are about to close Pomodoro", wxYES_NO | wxCANCEL | wxICON_INFORMATION);
	
	//TODO: implement saving and loading tasks
	switch (dialog->ShowModal())
	{
	case wxID_NO:
	case wxID_YES:
		break;
	default:
		return;
	}
	event.Skip();
}
