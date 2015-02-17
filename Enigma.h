#ifndef ENIGMA_H
#define ENIGMA_H

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "utils.h"

class Machine{
public:
	Machine(){}
	Machine(char *R1, char *R2, char *R3);
	void rotateMachine(int count);
	std::string printRotator(char *rotator);
	std::string findIntPath(int number);
	std::string findChar(char letter);
	char rotator1[26];
	char rotator2[26];
	char rotator3[26];
	uint32_t rotCount;
	void rotateSingle(char *rotator);
	std::string encryptLetter(char letter);
	char encrypt(char letter);
	char decrypt(char letter);
private:
};

class Rotor{
public:

	char forwardShift();
	char reverseShift();

private:/*
	_windowPosition;
	forwardOffsetMap;
	reverseOffsetMap;
	turnoverNotchPositions;*/
};


#endif