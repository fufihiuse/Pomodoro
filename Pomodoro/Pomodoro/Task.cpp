#include "Task.h"

Task::Task(const char* _name, Priority _priority)
{
	name = _name;
	priority = _priority;
	isComplete = false;
}
