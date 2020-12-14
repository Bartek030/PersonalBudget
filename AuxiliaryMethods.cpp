#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntIntoString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringIntoInt(string number) {
    return atoi(number.c_str());
}

string AuxiliaryMethods::loadLineFromUser() {
    string inputFromUser = "";
    cin.clear();
    cin.sync();
    getline(cin, inputFromUser);
    return inputFromUser;
}

char AuxiliaryMethods::loadCharacter() {
    string inputFromUser = "";
    char singleCharacter  = {0};

    while (true) {
        cin.clear();
        cin.sync();
        getline(cin, inputFromUser);

        if (inputFromUser.length() == 1) {
            singleCharacter = inputFromUser[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return singleCharacter;
}

string AuxiliaryMethods::changeFirstLetterToUpperAndRestToLower(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

struct tm *AuxiliaryMethods::getCurrentDate() {
    time_t currentTime;
    struct tm *date;

    time(&currentTime);
    date = localtime(&currentTime);

    return date;
};

string AuxiliaryMethods::getTodayDate() {
    struct tm *currentDate = getCurrentDate();
    string date = "";

    date = convertIntIntoString(currentDate -> tm_year + 1900) + "-" + convertIntIntoString(currentDate -> tm_mon + 1) + "-" + convertIntIntoString(currentDate -> tm_mday);

    return date;
};

string AuxiliaryMethods::getDateFromUser() {
    struct tm *currentDate = getCurrentDate();
    string userDate = "";

    do {
        cout << "Podaj date operacji (RRRR-MM-DD): ";
        userDate = loadLineFromUser();
    } while (!isDateRangeCorrect(userDate));
    cout << userDate;
    system("pause");
    return userDate;
}

bool AuxiliaryMethods::isDateRangeCorrect(string date) {
    struct tm *currentTime = getCurrentDate();
    string years = "", months = "", days = "";

    for (int i = 0; i < 4; i++) {
        years += date[i];
    }
    for (int i = 5; i < 7; i++) {
        months += date[i];
    }
    for (int i = 8; i < 10; i++) {
        days += date[i];
    }

    if (isDateFormatCorrect(date)) {
        if (convertStringIntoInt(years) == (currentTime -> tm_year + 1900)) {
            if (convertStringIntoInt(months) >= 1 && convertStringIntoInt(months) <= (currentTime -> tm_mon + 1)) {
                if(isNumberOfDaysCorrect(convertStringIntoInt(years), convertStringIntoInt(months), convertStringIntoInt(days))) {
                    return true;
                } else {
                    return showInfoAboutBadDateRange();
                }
            } else {
                return showInfoAboutBadDateRange();
            }
        } else if (convertStringIntoInt(years) < (currentTime -> tm_year + 1900)) {
            if (convertStringIntoInt(months) >= 1 && convertStringIntoInt(months) <= 12) {
                if(isNumberOfDaysCorrect(convertStringIntoInt(years), convertStringIntoInt(months), convertStringIntoInt(days))) {
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
    } else {
        return showInfoAboutBadDateFormat();
    }
}

bool AuxiliaryMethods::isNumberOfDaysCorrect(int year, int month, int numberOfDays) {
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

bool AuxiliaryMethods::isDateFormatCorrect(string date) {
    string userDate = getOnlyDigitsFromDate(date);

    if (date.length() != 10 || userDate.length() != 8 || date[4] != '-' || date[7] != '-') {
        return false;
    } else {
        return true;
    }
}

bool AuxiliaryMethods::showInfoAboutBadDateRange() {
    cout << "Podano nieprawidlowy zakres daty!" << endl;
    cout << "Podana data musi miescic sie w przedziale od 2000-01-01 do ostatniego dnia biezacego miesiaca!" << endl << endl;
    system("pause");
    return false;
}

bool AuxiliaryMethods::showInfoAboutBadDateFormat() {
    cout << "Podano nieprawidlowy format daty!" << endl;
    cout << "Date nalezy wpisac w formacie: RRRR-MM-DD" << endl;
    cout << "Data musi skladac sie z samych cyfr" << endl << endl;
    system("pause");
    return false;
}

string AuxiliaryMethods::getOnlyDigitsFromDate(string date) {
    string onlyDigitsDate;

    for (int i = 0; i < date.length(); i++) {
        if (date[i] >= '0' && date[i] <= '9') {
            onlyDigitsDate += date[i];
        }
    }
    return onlyDigitsDate;
}

float AuxiliaryMethods::loadAmountFromUser() {
    string inputFromUser = loadLineFromUser();
    float amount;

    if(isFloatNumberCorrect(inputFromUser)) {
        inputFromUser = replaceCommaWithDot(inputFromUser);
        amount = atof(inputFromUser.c_str());
        return amount;
    } else {
        cout << "To nie jest prawidlowa liczba! Wprowadz liczbe jeszcze raz: ";
    }
}

bool AuxiliaryMethods::isFloatNumberCorrect(string number) {
    int numberOfCommasAndDots = 0;

    for (int i = 0; i < number.length(); i++) {
        if (number[i] <= '0' && number[i] >= '9') {
            if (number[i] == '.' || number[i] == ',') {
                numberOfCommasAndDots++;
                if (numberOfCommasAndDots > 1) {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    return true;
}

string AuxiliaryMethods::replaceCommaWithDot(string number) {
    for(int i = 0; i < number.length(); i++) {
        if(number[i] = ',') {
            number[i] = '.';
        }
    }
    return number;
}
