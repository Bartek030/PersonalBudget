#ifndef CALENDAROPERATIONS_H
#define CALENDAROPERATIONS_H

#include<iostream>
#include<algorithm>
#include<sstream>
#include <time.h>
#include <cstdlib>
#include "AuxiliaryMethods.h"

using namespace std;

class CalendarOperations {
    static struct tm *getCurrentDate();
    static bool isDateRangeCorrect(string date);
    static bool isNumberOfDaysMonths(int year, int month, int numberOfDays);
    static bool isNumberOfDaysCorrect(int year, int month, int numberOfDays);
    static bool isDateFormatCorrect(string date);
    static bool showInfoAboutBadDateRange();
    static bool showInfoAboutBadDateFormat();
    static string getOnlyDigitsFromDate(string date);

public:
    static string getTodayDate();
    static string getPreviousMonthDate();
    static string getDateFromUser();
    static int getYearAndMonthFromDate(string date);
    static int changeDateIntoIntegerValue(string date);
};

#endif // CALENDAROPERATIONS_H
