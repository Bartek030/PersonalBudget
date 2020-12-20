#include "CalendarOperations.h"

struct tm *CalendarOperations::getCurrentDate() {
    time_t currentTime;
    struct tm *date;

    time(&currentTime);
    date = localtime(&currentTime);

    return date;
};

string CalendarOperations::getTodayDate() {
    struct tm *currentDate = getCurrentDate();
    string date = "";

    date = AuxiliaryMethods::convertIntIntoString(currentDate -> tm_year + 1900) + "-" + AuxiliaryMethods::convertIntIntoString(currentDate -> tm_mon + 1) + "-" + AuxiliaryMethods::convertIntIntoString(currentDate -> tm_mday);

    return date;
};

string CalendarOperations::getPreviousMonthDate() {
    struct tm *currentDate = getCurrentDate();
    string date = "";

    if ((currentDate -> tm_mon + 1) != 1) {
        date = AuxiliaryMethods::convertIntIntoString(currentDate -> tm_year + 1900) + "-" + AuxiliaryMethods::convertIntIntoString(currentDate -> tm_mon + 1 - 1) + "-" + AuxiliaryMethods::convertIntIntoString(currentDate -> tm_mday);
    } else {
        date = AuxiliaryMethods::convertIntIntoString(currentDate -> tm_year + 1900 - 1) + "-" + AuxiliaryMethods::convertIntIntoString(currentDate -> tm_mon + 1 + 11) + "-" + AuxiliaryMethods::convertIntIntoString(currentDate -> tm_mday);
    }

    return date;
}

string CalendarOperations::getDateFromUser() {
    struct tm *currentDate = getCurrentDate();
    string userDate = "";

    do {
        cout << "Podaj date operacji (RRRR-MM-DD): ";
        userDate = AuxiliaryMethods::loadLineFromUser();
    } while (!isDateFormatCorrect(userDate) || !isDateRangeCorrect(userDate));
    return userDate;
}

int CalendarOperations::getYearAndMonthFromDate(string date) {
    string yearAndMonth = "";
    int separateChar = 0;

    for (int i = 0; i < date.length(); i++) {
        if (date[i] == '-') {
            separateChar++;
            if (separateChar > 1) {
                break;
            }
            continue;
        }
        yearAndMonth += date[i];
    }

    return AuxiliaryMethods::convertStringIntoInt(yearAndMonth);
}

bool CalendarOperations::isDateRangeCorrect(string date) {
    struct tm *currentTime = getCurrentDate();
    string years = "", months = "", days = "";
    int numberOfYears = 0, numberOfMonths = 0, numberOfDays = 0;

    for (int i = 0; i < 4; i++) {
        years += date[i];
    }
    for (int i = 5; i < 7; i++) {
        months += date[i];
    }
    for (int i = 8; i < 10; i++) {
        days += date[i];
    }

    numberOfYears = AuxiliaryMethods::convertStringIntoInt(years);
    numberOfMonths = AuxiliaryMethods::convertStringIntoInt(months);
    numberOfDays = AuxiliaryMethods::convertStringIntoInt(days);

    if (numberOfYears == (currentTime -> tm_year + 1900)) {
        if (numberOfMonths >= 1 && numberOfMonths <= (currentTime -> tm_mon + 1)) {
            if(isNumberOfDaysCorrect(numberOfYears, numberOfMonths, numberOfDays)) {
                return true;
            } else {
                return showInfoAboutBadDateRange();
            }
        } else {
            return showInfoAboutBadDateRange();
        }
    } else if (numberOfYears < (currentTime -> tm_year + 1900) && numberOfYears >= 2000) {
        if (numberOfMonths >= 1 && numberOfMonths <= 12) {
            if(isNumberOfDaysCorrect(numberOfYears, numberOfMonths, numberOfDays)) {
                return true;
            } else {
                return showInfoAboutBadDateRange();
            }
        } else {
            return showInfoAboutBadDateRange();
        }
    } else {
        return showInfoAboutBadDateRange();
    }
}

bool CalendarOperations::isNumberOfDaysCorrect(int year, int month, int numberOfDays) {
    int daysInMonth;

    switch(month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        daysInMonth = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        daysInMonth = 30;
        break;
    case 2:
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            daysInMonth = 29;
            break;
        } else {
            daysInMonth = 28;
            break;
        }
    }
    if (numberOfDays <= daysInMonth) {
        return true;
    } else {
        return false;
    }
}

bool CalendarOperations::isDateFormatCorrect(string date) {
    string userDate = getOnlyDigitsFromDate(date);

    if (date.length() != 10 || userDate.length() != 8 || date[4] != '-' || date[7] != '-') {
        return showInfoAboutBadDateFormat();
    } else {
        return true;
    }
}

bool CalendarOperations::showInfoAboutBadDateRange() {
    cout << endl << "Podano nieprawidlowy zakres daty!" << endl;
    cout << "Podana data musi miescic sie w przedziale od 2000-01-01 do ostatniego dnia biezacego miesiaca!" << endl << endl;
    system("pause");
    return false;
}

bool CalendarOperations::showInfoAboutBadDateFormat() {
    cout << endl << "Podano nieprawidlowy format daty!" << endl;
    cout << "Date nalezy wpisac w formacie: RRRR-MM-DD" << endl;
    cout << "Data musi skladac sie z samych cyfr" << endl << endl;
    system("pause");
    return false;
}

string CalendarOperations::getOnlyDigitsFromDate(string date) {
    string onlyDigitsDate;

    for (int i = 0; i < date.length(); i++) {
        if (date[i] >= '0' && date[i] <= '9') {
            onlyDigitsDate += date[i];
        }
    }
    return onlyDigitsDate;
}

int CalendarOperations::changeDateIntoIntegerValue(string date) {
    string intDate = "";

    for (int i = 0; i < date.length(); i++) {
        if (date[i] != '-') {
            intDate += date[i];
        }
    }
    return AuxiliaryMethods::convertStringIntoInt(intDate);
}
