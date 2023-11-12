#pragma once
#include <string>
class Task
{
public:
	enum Priority { LOW, MEDIUM, HIGH };

private:
	bool isComplete;
	const char* name;

public:
	Priority priority = LOW;

	Task(const char* _name, Priority _priority);
};

