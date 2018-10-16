/*
    Author: Justin Muskopf
    Instructor: Hoffman
    Course: CSCE 4550, Fall 2018
    Assignment: Project 1
*/
#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include "instruction.h"
#include "object.h"

class Subject
{
    public:
        Subject();
        Subject(std::string _name, SecurityLevel _lvl);
        std::string getName();
        SecurityLevel getSecurityLevel();
        ~Subject();
        void readFromObject(Object *obj);
        void writeToObject(Object **obj, int value);
        int getTemp();
    private:
        std::string name;   // The name of the subject
        int temp;           // The temporary value of the Subject
        SecurityLevel lvl;  // The subject's security level
};

#endif
