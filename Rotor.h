#include <iostream>
#include "Enigma.h"

class Rotor{
public:

    const char * forwardShift();
    const char * reverseShift();

private:/*
    _windowPosition;
    forwardOffsetMap;
    reverseOffsetMap;
    turnoverNotchPositions;*/
};

struct RotorMapping{
    std::string rotorName;
    const char *letA;
    const char *letB;
    const char *letC;
    const char *letD;
    const char *letE;
    const char *letF;
    const char *letG;
    const char *letH;
    const char *letI;
    const char *letJ;
    const char *letK;
    const char *letL;
    const char *letM;
    const char *letN;
    const char *letO;
    const char *letP;
    const char *letQ;
    const char *letR;
    const char *letS;
    const char *letT;
    const char *letU;
    const char *letV;
    const char *letW;
    const char *letX;
    const char *letY;
    const char *letZ;
};

const struct RotorMapping RotorMap[] =
{
    {"I",   "E", "K", "M", "F", "L", "G", "D", "Q", "V", "Z", "N", "T", "O", "W", "Y", "H", "X", "U", "S", "P", "A", "I", "B", "R", "C", "J"},
    {"II",  "A", "J", "D", "K", "S", "I", "R", "U", "X", "B", "L", "H", "W", "T", "M", "C", "Q", "G", "Z", "N", "P", "Y", "F", "V", "O", "E"},
    {"III", "B", "D", "F", "H", "J", "L", "C", "P", "R", "T", "X", "V", "Z", "N", "Y", "E", "I", "W", "G", "A", "K", "M", "U", "S", "Q", "O"}
};
