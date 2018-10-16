/*
	Author: Justin Muskopf
	Instructor: Hoffman
	Course: CSCE 4550, Fall 2018
	Assignment: Project 1
*/
#ifndef REFERENCEMONITOR_H
#define REFERENCEMONITOR_H

#include <vector>
#include <string>
#include "instruction.h"
#include "subject.h"
#include "object.h"
#include <map>

class ReferenceMonitor
{
	public:
		ReferenceMonitor();
		~ReferenceMonitor();

		bool executeInstruction(Instruction instruction);
		void printState();
	private:
        // The Subject map of Subject Name -> Subject*, and its iterators
		std::map<std::string, Subject *> subjects;
		typedef std::map<std::string, Subject *>::iterator SubjectIterator;
		typedef std::pair<std::string, Subject *> SubjectPair;

        // The Object map of Object Name -> Object*, and its iterators
		std::map<std::string, Object *>  objects;
		typedef std::map<std::string, Object *>::iterator ObjectIterator;
		typedef std::pair<std::string, Object *> ObjectPair;

		bool addSubject(Instruction instruction);
		bool addObject(Instruction instruction);
		bool executeWrite(Instruction instruction);
		bool executeRead(Instruction instruction);
};

#endif
