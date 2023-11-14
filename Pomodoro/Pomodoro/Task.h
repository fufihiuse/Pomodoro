#pragma once
#include <string>
#include "wx/defs.h"
class Task
{
public:
	enum Priority { LOW, MEDIUM, HIGH };
	wxWindowID id;

private:
	bool isComplete;
	const char* name;
	static int currentID;

public:
	Priority priority;

	Task(const char* _name, Priority _priority);
};

