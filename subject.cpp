/*
	Author: Justin Muskopf
	Instructor: Hoffman
	Course: CSCE 4550, Fall 2018
	Assignment: Project 1
*/
#include "subject.h"

/*
    Brief: Initializes a Subject
*/
Subject::Subject()
{
	temp = 0;
}

/*
    Brief: Initializes an Subject with its name and level
    Parameters: std::string name, and std::string security level
*/
Subject::Subject(std::string _name, SecurityLevel _lvl)
{
    // Set name and level
	name = _name;
	lvl = _lvl;

    // Call default ctor
	Subject();
}

/*
    Brief: Get the subject's name
    Return: std::string name
*/
std::string Subject::getName()
{
	return name;
}

/*
    Brief: Get the subject's security level
    Return: std::string level
*/
SecurityLevel Subject::getSecurityLevel()
{
	return lvl;
}

/*
    Brief: Sets temp to the object's value
    Parameters: obj - The object to read from
*/
void Subject::readFromObject(Object *obj)
{
	temp = obj -> getValue();
}

/*
    Brief: Writes to the value of an object
    Parameters: obj - The object to write to, value - The value to write
*/
void Subject::writeToObject(Object **obj, int value)
{
    // De-ref obj and set value
	Object *ret = *obj;
	ret -> setValue(value);

    // Re-ref obj
	obj = &ret;
}

/*
    Brief: Gets the temp value of the Subject
    Return: int temp value
*/
int Subject::getTemp()
{
	return temp;
}

// Default destructor
Subject::~Subject()
{
	
}
