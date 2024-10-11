/*
    Author: Justin Muskopf
    Instructor: Hoffman
    Course: CSCE 4550, Fall 2018
    Assignment: Project 1
*/
#include "referencemonitor.h"
#include <map>
#include <iostream>
#include <iomanip>

#define DEFAULT_NAME_LEN 16

/*
    Brief: Default constructor
*/
ReferenceMonitor::ReferenceMonitor()
{

}

/*
    Brief: Sends an instruction to the right place for execution
    Parameters: Instruction - The instruction object
    Return: boolean value of success/failure (true/false)
*/
bool ReferenceMonitor::executeInstruction(Instruction instruction)
{
    bool ret;

    // Send the instruction to the right place for parsing
    switch(instruction.getType())
    {
        case ADD_SUB:
            ret = addSubject(instruction);
            break;
        case ADD_OBJ:
            ret = addObject(instruction);
            break;
        case READ:
            ret = executeRead(instruction);
            break;
        case WRITE:
            ret = executeWrite(instruction);
            break;
        default:
            ret = false;
    }

    return ret;
}

/*
    Brief: Adds a subject to the subject map
    Parameters: Instruction - The instruction object
    Return: boolean value of success/failure (true/false)
*/
bool ReferenceMonitor::addSubject(Instruction instruction)
{
    // The subject's name and security level
    std::string subName  = instruction.getSubjectName();
    SecurityLevel secLvl = instruction.getSecurityLevel();

    // The created Subject
    Subject *sub = new Subject(subName, secLvl);

    // Insert the new Subject and check for error
    std::pair<SubjectIterator, bool> result;
    result = subjects.insert(SubjectPair(subName, sub));
    if (result.second == false)
    {
        std::cout << "El usuario: '" << subName << "' ya existe!\n";
        return false;
    }

    // Output info string
    std::cout << std::left << std::setw(DEFAULT_NAME_LEN) << "Usuario Agregado";
    std::cout << ": " << instruction.getInstruction() << "\n";

    return true;
}

/*
    Brief: Adds an Object to the object map
    Parameters: Instruction - The instruction object
    Return: boolean value of success/failure (true/false)
*/
bool ReferenceMonitor::addObject(Instruction instruction)
{
    // The object's name and security level
    std::string objName = instruction.getObjectName();
    SecurityLevel secLvl = instruction.getSecurityLevel();

    // Create the new Object
    Object *obj = new Object(objName, secLvl);
    
    // Insert the new Object and check for error
    std::pair<ObjectIterator, bool> result;
    result = objects.insert(ObjectPair(objName, obj));
    if (result.second == false)
    {
        std::cout << "El objeto: '" << objName << "'ya existe!\n";
        return false;
    }

    // Output info string
    std::cout << std::left << std::setw(DEFAULT_NAME_LEN) << "Objeto Agregado";
    std::cout << ": " << instruction.getInstruction() << "\n";

    return true;
}

/*
    Brief: Adds an Object to the object map
    Parameters: Instruction - The instruction object
*/
bool ReferenceMonitor::executeWrite(Instruction instruction)
{
    // Get the subject and object names
    std::string subName = instruction.getSubjectName();
    std::string objName = instruction.getObjectName();

    // Either subject or object not found in map
    if (subjects.count(subName) == 0 || objects.count(objName) == 0)
    {
        return false;
    }

    // Get the subject and object objects
    Subject *sub = subjects.at(subName);
    Object  *obj = objects.at(objName);

    // Get value from instruction
    int value = instruction.getValue();

    // Get subject and object security levels
    SecurityLevel subLvl = sub -> getSecurityLevel();
    SecurityLevel objLvl = obj -> getSecurityLevel();

    // Access Granted
    if (subLvl <= objLvl)
    {
        sub -> writeToObject(&obj, value);
        std::cout << std::left << std::setw(DEFAULT_NAME_LEN) << "Acceso concedido";
        std::cout << ": " << sub -> getName() << " writes value " << value << " to " << obj -> getName() << ".\n";
    }
    // Access Denied
    else
    {
        std::cout << std::left << std::setw(DEFAULT_NAME_LEN) << "Aceso denegado";
        std::cout << ": " << instruction.getInstruction() << "\n";
    }

    return true;
}

/*
    Brief: Adds an Object to the object map
    Parameters: Instruction - The instruction object
    Return: boolean value of success/failure (true/false)
*/
bool ReferenceMonitor::executeRead(Instruction instruction)
{
    // Get the Subject and Object names
    std::string subName = instruction.getSubjectName();
    std::string objName = instruction.getObjectName();

    // Either the Subject or Object doesn't exist
    if (subjects.count(subName) == 0 || objects.count(objName) == 0)
    {
        return false;
    }

    // Get the Subject/Object objects
    Subject *sub = subjects.at(subName);
    Object  *obj = objects.at(objName);

    // Get the Subject/Object security levels
    SecurityLevel subLvl = sub -> getSecurityLevel();
    SecurityLevel objLvl = obj -> getSecurityLevel();

    // Access Granted
    if (subLvl >= objLvl)
    {
        sub -> readFromObject(obj);
        std::cout << std::left << std::setw(DEFAULT_NAME_LEN) << "Acceso concedido";
        std::cout << ": " << sub -> getName() << " reads " << obj -> getName() << ".\n";
    }
    // Access denied
    else
    {
        std::cout << std::left << std::setw(DEFAULT_NAME_LEN) << "Acceso denegado";
        std::cout << ": " << instruction.getInstruction() << "\n";
    }

    return true;
}


void ReferenceMonitor::printState()
{
    std::cout << "-------------------------\n";
    std::cout << std::left << std::setw(DEFAULT_NAME_LEN) << "Usuario:";
    std::cout << "Temp:\n";
    std::cout << "-------------------------\n";
    for (SubjectIterator it = subjects.begin(); it != subjects.end(); it++)
    {
        Subject *sub = it -> second;
        std::cout << std::left << std::setw(DEFAULT_NAME_LEN) << sub -> getName();
        std::cout << sub -> getTemp() << "\n";
    }
    std::cout << "\n";
    std::cout << std::left << std::setw(DEFAULT_NAME_LEN) << "Objeto:";
    std::cout << "Valor:\n";
    std::cout << "-------------------------\n";
    for (ObjectIterator it = objects.begin(); it != objects.end(); it++)
    {
        Object *obj = it -> second;
        std::cout << std::left << std::setw(DEFAULT_NAME_LEN) << obj -> getName();
        std::cout << obj -> getValue() << "\n";
    }
    std::cout << "-------------------------\n";
}

// Destructor
ReferenceMonitor::~ReferenceMonitor()
{
    // Delete all subjects
    for (SubjectIterator it = subjects.begin(); it != subjects.end(); it++)
    {
        delete it -> second;
    }

    // Delete all objects
    for (ObjectIterator it = objects.begin(); it != objects.end(); it++)
    {
        delete it -> second;
    }
}
