#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <sstream>
#include <stdint.h>

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
private:

};
std::string Machine::findIntPath(int number){
	std::ostringstream rot;
	if (number > 25)
	{
		return NULL;
	}
	rot << rotator1[number] << " -> " << rotator2[number] << " -> " << rotator3[number] << " \n";
	return rot.str();
}

std::string Machine::findChar(char letter){
	std::ostringstream rot;
	for (int i = 0; i < 26; i++)
	{
		if (rotator1[i] == letter)
		{
			rot << i << " -> ";
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (rotator2[i] == letter)
		{
			rot << i << " -> ";
		}
	}
	for (int i = 0; i < 26; i++)
	{
		if (rotator3[i] == letter)
		{
			rot << i << " \n ";
		}
	}


	return rot.str();
}
Machine::Machine(char *R1, char *R2, char *R3)
{
	rotCount = 0;
	strcpy(rotator1, R1);
	strcpy(rotator2, R2);
	strcpy(rotator3, R3);
}

void Machine::rotateSingle(char *rotator)
{
	char tmpRotator = rotator[0];
	memmove(rotator, rotator + 1, 25);
	rotator[25] = tmpRotator;
}

void Machine::rotateMachine(int offset)
{
	const int rot2Trigger = 26;      // 26^1
	const int rot3Trigger = 676;     // 26^2
	const int rotReset = 17576;   // 26^3
	for (int i = 0; i < offset; i++)
	{
		rotCount++;
		rotateSingle(rotator1);
		if (rotCount % rot2Trigger == 0)
		{
			rotateSingle(rotator2);
			if (rotCount % rot3Trigger == 0)
			{
				rotateSingle(rotator3);
			}
		}

		if (rotCount % rotReset == 0)
		{
			rotCount = 0;
		}
	}
}

std::string Machine::printRotator(char *rotator){
	std::ostringstream rot;

	for (int i = 0; i < 26; i++)
	{
		rot << "Letter: " << rotator[i] << " = " << i << "\n";
	}
	return rot.str();
}


int main(){
	char *R1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *R2 = "QWERTYUIOPASDFGHJKLZXCVBNM";
	char *R3 = "MNBVCXZLKJHGFDSAPOIUYTREWQ";

	Machine enigma = Machine(R1, R2, R3);

	std::cout << enigma.printRotator(enigma.rotator1) << std::endl;
	enigma.rotateMachine(15);
	std::cout << enigma.printRotator(enigma.rotator1) << std::endl;
	std::cout << enigma.findIntPath(5) << std::endl;
	std::cout << enigma.findChar('A') << std::endl;
	//std::cout << enigma.printRotator(enigma.rotator2) << std::endl;


}
