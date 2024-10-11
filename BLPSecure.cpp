/*
    Author: Justin Muskopf
    Instructor: Hoffman
    Course: CSCE 4550, Fall 2018
    Assignment: Project 1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include "instruction.h"
#include "referencemonitor.h"

int main(int argc, char *argv[])
{
    // Improper usage, no file provided
    if (argc != 2)
    {
        std::cout << "USAGE: ./" << argv[0] << "FILENAME\n";
        exit(0);
    }

    // Create reference monitor
    ReferenceMonitor refMon;

    // Get filename and attempt to open file
    char *filename = argv[1];
    std::ifstream inputFile(filename);
    if (!inputFile.good())
    {
        std::cout << "No se pudo abrir el archivo: " << filename << ". terminando.\n";
        exit(1);
    }

    // Loop through input file and run instructions
    int instructionCount = 0;
    for (std::string line; std::getline(inputFile, line); )
    {
        if (instructionCount && instructionCount % 10 == 0)
        {
            refMon.printState();
        }

        // Create an instruction and check for validity / execute
        Instruction instruction(line);
        if (instruction.isInvalid() || !refMon.executeInstruction(instruction))
        {
            std::cout << std::left << std::setw(16) << "Instruccion Incorrecta";
            std::cout << ": " << line << std::endl;
        }

        instructionCount++;
    }

    // Final state print
    refMon.printState();
    
    return 0;
}
