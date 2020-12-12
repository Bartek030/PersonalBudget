#include "PersonalBudget.h"

void PersonalBudget::userRegister() {
    userPanel.userRegister();
}

bool PersonalBudget::isUserLoggedIn() {
    return userPanel.isUserLoggedIn(userPanel.getLoggedInUserId());
}

void PersonalBudget::userLogging() {
    userPanel.userLogging();
}

char PersonalBudget::chooseOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "0. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
