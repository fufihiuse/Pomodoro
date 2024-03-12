#include "Task.h"
#include <wx/defs.h>

int Task::currentID = 2;

Task::Task(const char* _name, Priority _priority)
{
	// Ensure ID does not override predefined IDs
	if (currentID >= wxID_LOWEST && currentID <= wxID_HIGHEST)
		currentID = wxID_HIGHEST + 1;
	id = currentID++;
	name = _name;
	priority = _priority;
	isComplete = false;
}
