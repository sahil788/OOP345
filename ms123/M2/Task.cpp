// Task.cpp

#include "Task.h"
#include "Utilities.h"
#include <iomanip>
#define MAX_WIDTH size_t(20)

char Task::delimiter = '|';
size_t Task::field_width = 1;

Task::Task(const std::string& record) : name(""), slots("1")
{
	size_t position = 0;
    bool ok = true;
    nextTask[passed] = "";
    nextTask[redirect] = "";
    pNextTask[passed] = nullptr;
    pNextTask[redirect] = nullptr;
    Utilities u(field_width);
    name = u.nextToken(record, position, ok);

    if (!name.empty())
	{
        if (ok) slots = u.nextToken(record, position, ok);
        if (ok) nextTask[passed] = u.nextToken(record, position, ok);
        if (ok) nextTask[redirect] = u.nextToken(record, position, ok);
        if (u.getFieldWidth() < MAX_WIDTH) 
		{
            field_width = u.getFieldWidth();
        }
    }
}

const std::string& Task::getName() const 
{
    return name;
}

unsigned int Task::getSlots() const 
{
    return std::stoi(slots);
}

bool Task::validate(const Task& task)
{
    if (!pNextTask[passed] && !nextTask[passed].compare(task.name))
	{
        pNextTask[passed] = &task;
    }

    if (!pNextTask[redirect] && !nextTask[redirect].compare(task.name))
	{
        pNextTask[redirect] = &task;
    }

    return (nextTask[passed].empty() || pNextTask[passed]) &&
           (nextTask[redirect].empty() || pNextTask[redirect]);
}

const Task* Task::getNextTask(Quality quality) const 
{
    if (!pNextTask[quality])
	{
        throw std::string("*** Validate  [") + nextTask[quality] + std::string("] @ [") + name + std::string("] ***");
    }

    return pNextTask[quality];
}

void Task::display(std::ostream& os) const 
{
    size_t fw = field_width + 2;

    os << "Task Name    : " << std::left;
    os << std::setw(fw) << (std::string("[") + name + std::string("]"));
    os << " [" << slots << "]";
    os << std::endl;

    if (!nextTask[passed].empty()) 
	{
        os << " Continue to : ";
        os << std::setw(fw) << (std::string("[") + nextTask[passed] + std::string("]"));
        if (!pNextTask[passed]) 
		{
            os << " *** to be validated ***";
        }
        os << std::endl;
    }

    if (!nextTask[redirect].empty()) 
	{
        os << " Redirect to : ";
        os << std::setw(fw) << (std::string("[") + nextTask[redirect] + std::string("]"));
        if (!pNextTask[redirect]) 
		{
            os << " *** to be validated ***";
        }

        os << std::endl;
    }
}

void Task::setDelimiter(const char d) 
{
    delimiter = d;
}

size_t Task::getFieldWidth()
 {
    return field_width;
}

bool operator==(const Task& lhs, const Task& rhs) 
{
    return !lhs.getName().compare(rhs.getName());
}