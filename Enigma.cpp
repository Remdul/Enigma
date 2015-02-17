#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstring>
#include <sstream>
#include <stdint.h>
#include "utils.h"
#include "Enigma.h"

// Enigma German M3
// royal flags wave kings above
#define ASSERT_EQUAL(EXPRESSION, EXPECTED) \
std::cout << "Testing that " << #EXPRESSION << " equals " << EXPECTED << ": "; \
if (EXPRESSION != EXPECTED) \
{ \
	failcount++; \
	std::cout << "FAIL Got: " << EXPRESSION << "\n"; \
} \
else \
{ \
	passcount++; \
	std::cout << "PASS\n"; \
}

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
}
void Machine::rotateSingle(char *rotator)
{
	char tmpRotator = rotator[0];
	memmove(rotator, rotator + 1, 25);
	rotator[25] = tmpRotator;
}
void Machine::rotateMachine(int offset)
{
	const int rot2Trigger = 26;		// 26^1
	const int rot3Trigger = 676;	// 26^2
	const int rotReset = 17576;		// 26^3
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
char Machine::encrypt(char letter)
{
	int r1, r3;
	rotateMachine(1); // Rotate Machine every encryption

	for (int i = 0; i < sizeof(rotator1); i++){
		if (rotator1[i] == letter)
		{
			r1 = i;
		}
	}
	for (int i = 0; i < sizeof(rotator3); i++){
		if (rotator3[i] == rotator2[r1])
		{
			r3 = i;
		}
	}
	return rotator3[r3];
}
int main(){
	char *R1 = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char *R2 = "QWERTYUIOPASDFGHJKLZXCVBNM";
	char *R3 = "MNBVCXZLKJHGFDSAPOIUYTREWQ";

	Machine enigma = Machine(R1, R2, R3);


	int failcount = 0;
	int passcount = 0;
	std::string ROTOR_I_WIRING = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
	ASSERT_EQUAL(alphaord('A'), 0);
	ASSERT_EQUAL(alphaord('B'), 1);
	ASSERT_EQUAL(alphaord('Z'), 25);

	ASSERT_EQUAL(ordalpha(0), 'A');
	ASSERT_EQUAL(ordalpha(1), 'B');
	ASSERT_EQUAL(ordalpha(25), 'Z');

	std::vector<int> test_shifts = construct_shifts(ROTOR_I_WIRING);
	ASSERT_EQUAL(test_shifts[0], 4);
	ASSERT_EQUAL(test_shifts[1], 9);
	ASSERT_EQUAL(test_shifts[6], -3);

	std::vector<int> test_shifts2 = reverse_shifts(ROTOR_I_WIRING);
	ASSERT_EQUAL(test_shifts2[4], 22);
	ASSERT_EQUAL(test_shifts2[10], 17);
	ASSERT_EQUAL(test_shifts2[3], 3);

	ASSERT_EQUAL(shift_char('A', 26), 'A');
	ASSERT_EQUAL(shift_char('A', -26), 'A');
	ASSERT_EQUAL(shift_char('A', 1), 'B');
	ASSERT_EQUAL(shift_char('B', -1), 'A');
	ASSERT_EQUAL(shift_char('A', -1), 'Z');
	ASSERT_EQUAL(shift_char('Z', 1), 'A');
	ASSERT_EQUAL(shift_char('A', 27), 'B');


}
