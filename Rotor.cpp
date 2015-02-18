#include <iostream>
#include <vector>
#include "Enigma.h"
#include "Rotor.h"
#include "utils.h"

Wheel::Wheel(const std::string &wiring){
    forwardShifts = construct_shifts(wiring);
}

char Wheel::translateForward(char letter)
{
    int cumulativeRotorRotation = 0;
    int shift_index = shift_num(alphaord(letter), cumulativeRotorRotation);
    return shift_char(letter, shift_index);
}

Rotor::Rotor(const std::string &wiring, const std::vector<int> &turnoverPositions, const int newRingSetting)
{
    Wheel(wiring);
    windowPosition          = 0;
    ringSetting             = newRingSetting - 1;
    turnoverNotchPositions  = turnoverPositions;
    forwardShifts           = construct_shifts(wiring);
    reverseShifts           = reverse_shifts(wiring);
}

void Rotor::stepRotor(){
    windowPosition = shift_num(windowPosition, 1);
}

int Rotor::getWindowPosition(){
    return windowPosition;
}

int Rotor::setWindowPosition(int newWindowPosition){
    return shift_num(newWindowPosition, 1);
}

char Rotor::translateForward(char letter){
    int cumulativeRotorRotation = windowPosition + ringSetting;
    int shiftIndex = shift_num(alphaord(letter), cumulativeRotorRotation);
    return shift_char(letter, forwardShifts[shiftIndex]);
}

char Rotor::translateReverse(char letter){
    int cumulativeRotorRotation = windowPosition + ringSetting;
    int shiftIndex = shift_num(alphaord(letter), cumulativeRotorRotation);
    return shift_char(letter, reverseShifts[shiftIndex]);
}
