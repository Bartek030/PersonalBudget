#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include<iostream>
#include<algorithm>
#include<sstream>
#include <time.h>
#include <cstdlib>

using namespace std;

class AuxiliaryMethods {
    static string replaceCommaWithDot(string number);
    static bool isFloatNumberCorrect(string number);

public:
    static string convertIntIntoString(int number);
    static string convertFloatIntoString(float number);
    static int convertStringIntoInt(string number);
    static float convertStringIntoFloat(string number);
    static string loadLineFromUser();
    static char loadCharacter();
    static string changeFirstLetterToUpperAndRestToLower(string text);
    static float loadAmountFromUser();
};

#endif // AUXILIARYMETHODS_H
