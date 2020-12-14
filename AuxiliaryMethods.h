#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include<iostream>
#include<algorithm>
#include<sstream>
#include <time.h>

using namespace std;

class AuxiliaryMethods {
    static struct tm *getCurrentDate();
    static bool isDateRangeCorrect(string date);
    static bool isNumberOfDaysCorrect(int year, int month, int numberOfDays);
    static bool isDateFormatCorrect(string date);
    static bool showInfoAboutBadDateRange();
    static bool showInfoAboutBadDateFormat();
    static string getOnlyDigitsFromDate(string date);

public:
    static string convertIntIntoString(int number);
    static int convertStringIntoInt(string number);
    static string loadLineFromUser();
    static char loadCharacter();
    static string changeFirstLetterToUpperAndRestToLower(string text);
    static string getTodayDate();
    static string getDateFromUser();
};

#endif // AUXILIARYMETHODS_H
