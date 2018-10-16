/*
    Author: Justin Muskopf
    Instructor: Hoffman
    Course: CSCE 4550, Fall 2018
    Assignment: Project 1
*/
#include <algorithm>
#include <iostream>
#include <vector>
#include <sstream>
#include "instruction.h"
#include <stdexcept>

/*
    Brief: Initializes an Instruction with its string value
    Parameters: std::string command pulled from file
    Return: N/A
*/
Instruction::Instruction(std::string command)
{
    valid = false;      // Only true if passes all checks
    type  = CMD_ERROR;  // Set to ERROR_TYPE for final checks
    value = 0;          // Initial value of an instruction

    // Copy string to this instruction var
    instruction = command;

    // Lower the command string
    std::string lowerCmd;
    lowerCmd.resize(command.size());
    std::transform(command.begin(), command.end(), lowerCmd.begin(), ::tolower);

    // Get first word out of command
    std::string cmd = lowerCmd.substr(0, lowerCmd.find(' '));
    for (int i = 0; i < Instruction::NUM_CMD_TYPES; i++)
    {
        if (cmd == TypeStrings[i])
        {
            type = static_cast<CmdType>(i);
        } 
    }

    // Type is still ERROR, invalid instruction
    if (type == CMD_ERROR)
    {
        return;
    }

    // Parse instruction
    parseInstruction(lowerCmd);
}

/*
    Brief: Parses a file's string into an instruction object
    Parameters: std::string cmd - the string that came from the file
    Return: N/A
*/
void Instruction::parseInstruction(std::string cmd)
{
    std::vector<std::string> words; // Holds words from the cmd string
    std::string buffer;             // The copy buffer for stream ops
    std::stringstream stream(cmd);  // Will allow easy separation by spaces
    while (stream >> buffer)
    {
        // Add this word to words
        words.push_back(buffer);
    }

    // Get number of words
    int numWords = words.size();

    // Logic based on type of instruction
    switch (type)
    {
        case ADD_SUB:
            // Bad syntax
            if (numWords != 3)
            {
                return;
            }
            
            // Get name and lvl, error check
            subName = words[1];
            lvl = getLevelFromString(words[2]);
            if (lvl == LVL_ERROR)
            {
                return;
            }
            break;
        case ADD_OBJ:
            // Bad syntax
            if (numWords != 3)
            {
                return;
            }

            // Get object name and level, error check
            objName = words[1];
            lvl = getLevelFromString(words[2]);
            if (lvl == LVL_ERROR)
            {
                return;
            }
            break;
        case READ:
            // Bad syntax
            if (numWords != 3)
            {
                return;
            }
            // Get subject/object names
            subName = words[1];
            objName = words[2];
            break;
        case WRITE:
            // Bad syntax
            if (numWords != 4)
            {
                return;
            }
            // Get subject and object names
            subName = words[1];
            objName = words[2];
            try
            {
                // Get value from string
                value = stoi(words[3]);
            }
            // No number found, invalid value
            catch (const std::invalid_argument& err)
            {
                return;
            }
            break;
        default:
            return;
    };

    // Valid instruction!
    valid = true;
}


/*
    Brief: Gets the security level from a string
    Parameters: std::str - String to get lvl from
    Return: The security level contained in the string, LVL_ERROR if none
*/
SecurityLevel Instruction::getLevelFromString(std::string str)
{
    SecurityLevel secLvl = LVL_ERROR;

    // Compare the known LevelStrings to the provided string
    for (int i = 0; i < NUM_SEC_LVLS; i++)
    {
        // Match
        if (LevelStrings[i] == str)
        {
            secLvl = static_cast<SecurityLevel>(i);
            break;
        }
    }

    return secLvl;
}

/*
    Brief: Returns whether or not the instruction is valid
*/
bool Instruction::isValid()
{
    return valid;
}

/*
    Brief: Returns whether or not the instruction is invalid
*/
bool Instruction::isInvalid()
{
    return !valid;
}


/*
    Brief: Get the subject's name
*/
std::string Instruction::getSubjectName()
{
    return subName;
}

/*
    Brief: Get the object's name
*/
std::string Instruction::getObjectName()
{
    return objName;
}


/*
    Brief: Get the security level
*/
SecurityLevel Instruction::getSecurityLevel()
{
    return lvl;
}

/*
    Brief: Get the value
*/
int Instruction::getValue()
{
    return value;
}

/*
    Brief: Get the instruction type
*/
CmdType Instruction::getType()
{
    return type;
}

/*
    Brief: Get the full instruction string
*/
std::string Instruction::getInstruction()
{
    return instruction;
}

// Default destructor
Instruction::~Instruction()
{

}
