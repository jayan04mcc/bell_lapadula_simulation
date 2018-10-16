/*
    Author: Justin Muskopf
    Instructor: Hoffman
    Course: CSCE 4550, Fall 2018
    Assignment: Project 1
*/
#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include "instruction.h"

// Represents a BLP Object
class Object
{
    public:
        Object();
        Object(std::string _name, SecurityLevel _lvl);
        std::string getName();
        SecurityLevel getSecurityLevel();
        void setValue(int _value);
        int getValue();
        ~Object();
    private:
        std::string name;   // The name of the object
        int value;          // The object's value
        SecurityLevel lvl;  // The object's security level
};

eendif
