#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include<iostream>
#include<algorithm>
#include<sstream>
#include <time.h>
#include <cstdlib>

using namespace std;

class AuxiliaryMethods {
    static struct tm *getCurrentDate();
    static bool isDateRangeCorrect(string date);
    static bool isNumberOfDaysCorrect(int year, int month, int numberOfDays);
    static bool isDateFormatCorrect(string date);
    static bool showInfoAboutBadDateRange();
    static bool showInfoAboutBadDateFormat();
    static string getOnlyDigitsFromDate(string date);
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
    static string getTodayDate();
    static string getPreviousMonthDate();
    static string getDateFromUser();
    static float loadAmountFromUser();
    static int changeDateIntoIntegerValue(string date);
};

#endif // AUXILIARYMETHODS_H
