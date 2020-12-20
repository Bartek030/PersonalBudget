#include "AuxiliaryMethods.h"

string AuxiliaryMethods::convertIntIntoString(int number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::convertFloatIntoString(float number) {
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

int AuxiliaryMethods::convertStringIntoInt(string number) {
    return atoi(number.c_str());
}

float AuxiliaryMethods::convertStringIntoFloat(string number) {
    return atof(number.c_str());
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

float AuxiliaryMethods::loadAmountFromUser() {
    string inputFromUser = "";
    float amount;
    bool isInputCorrect = false;
    do {
        inputFromUser = loadLineFromUser();
        if(isFloatNumberCorrect(inputFromUser)) {
            isInputCorrect = true;
            inputFromUser = replaceCommaWithDot(inputFromUser);
            amount = convertStringIntoFloat(inputFromUser);
            return amount;
        } else {
            cout << "To nie jest prawidlowa liczba! Wprowadz liczbe jeszcze raz: ";
        }
    } while (!isInputCorrect);
}

bool AuxiliaryMethods::isFloatNumberCorrect(string number) {
    int numberOfCommasAndDots = 0;

    for (int i = 0; i < number.length(); i++) {
        if (number[i] < '0' || number[i] > '9') {
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
        if(number[i] == ',') {
            number[i] = '.';
        }
    }
    return number;
}
