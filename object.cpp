/*
    Author: Justin Muskopf
    Instructor: Hoffman
    Course: CSCE 4550, Fall 2018
    Assignment: Project 1
*/
#include "object.h"

/*
    Brief: Initializes an Object
*/
Object::Object()
{
    value = 0;
}

/*
    Brief: Initializes an Object with its name and lvl
    Parameters: std::string _name - The name, SecurityLevel _lvl - The security level
*/
Object::Object(std::string _name, SecurityLevel _lvl)
{
    name = _name;
    lvl = _lvl;

    Object();
}

/*
    Brief: Get the object's name
*/
std::string Object::getName()
{
    return name;
}

/*
    Brief: Get the object's security level
*/
SecurityLevel Object::getSecurityLevel()
{
    return lvl;
}

/*
    Brief: Set the object's value
    Parameters: int _value - The object's new value
*/
void Object::setValue(int _value)
{
    value = _value;
}

/*
    Brief: Get the object's name
*/
int Object::getValue()
{
    return value;
}

/*
    Brief: Get the object's name
*/
Object::~Object()
{
    
}
