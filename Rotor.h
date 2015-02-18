#ifndef ROTOR_H
#define ROTOR_H

#include <iostream>
#include <vector>
#include "Enigma.h"


// BASE CLASS
class Wheel{
public:
    Wheel(const std::string &wiring);
    char translateForward(char letter);
private:
    std::vector<int> forwardShifts;

};

// DERIVED CLASS
class Rotor : public Wheel{
public:
    Rotor(const std::string &wiring, const std::vector<int> &turnoverPositions, const int ringSetting);
    void stepRotor();
    int getWindowPosition();
    int setWindowPosition(int newWindowPosition);
    char translateForward(char letter);
    char translateReverse(char letter);
private:
    std::vector<int> forwardShifts;  // Return of construct_shift
    std::vector<int> reverseShifts;  // Return of reverse_shift
    std::vector<int> turnoverNotchPositions; // Typically 1 number; Naval Rings used by M4 have 2
    int ringSetting;
    int windowPosition;
};


#endif
