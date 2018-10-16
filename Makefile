
all: BlpSecure ReferenceMonitor Instruction Subject Object
	g++ -std=c++11 -o blpsecure BlpSecure ReferenceMonitor Instruction Subject Object

clean:
	rm -f Instruction ReferenceMonitor Subject Object BlpSecure blpsecure

BlpSecure: 
	g++ -std=c++11 -c -o BlpSecure BLPSecure.cpp

ReferenceMonitor: referencemonitor.h
	g++ -std=c++11 -c -o ReferenceMonitor referencemonitor.cpp

Instruction: instruction.h
	g++ -std=c++11 -c -o Instruction instruction.cpp

Subject: subject.h
	g++ -std=c++11 -c -o Subject subject.cpp

Object: object.h
	g++ -std=c++11 -c -o Object object.cpp
