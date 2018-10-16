/*
    Author: Justin Muskopf
    Instructor: Hoffman
    Course: CSCE 4550, Fall 2018
    Assignment: Project 1
*/
#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <string>
#include <vector>

// Data types for Instruction and SecurityLevel Enums
typedef enum {ADD_SUB, ADD_OBJ, READ, WRITE, CMD_ERROR} CmdType;
typedef enum {LOW, MEDIUM, HIGH, LVL_ERROR} SecurityLevel;

// Represents Instructions to ReferenceMonitor
class Instruction
{
    public:
        Instruction(std::string command);
        
        // The number of command types and security levels
        static const int NUM_CMD_TYPES = 4;
        static const int NUM_SEC_LVLS = 3;
        
        bool isValid();
        bool isInvalid();
        std::string getSubjectName();
        std::string getObjectName();
        std::string getInstruction();
        SecurityLevel getSecurityLevel();
        int getValue();
        CmdType getType();
        
        ~Instruction();


    private:
        // The strings representing SecurityLevels and Instruction types in instruction strings
        const std::vector<std::string> LevelStrings = {"low", "medium", "high"};
        const std::vector<std::string> TypeStrings  = {"addsub", "addobj", "read", "write"};

        std::string subName;     // The subject name
        std::string objName;     // The object name
        std::string instruction; // The instruction string
        CmdType type;            // The type of command
        SecurityLevel lvl;       // The Security Level
        bool valid;              // Valid instruction?
        int value;               // The value (if provided)

        void parseInstruction(std::string);
        SecurityLevel getLevelFromString(std::string str);
};

#endif
