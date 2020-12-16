#include "PersonalBudget.h"

void PersonalBudget::userRegister() {
    userPanel.userRegister();
}

bool PersonalBudget::isUserLoggedIn() {
    return userPanel.isUserLoggedIn(userPanel.getLoggedInUserId());
}

void PersonalBudget::userLogging() {
    userPanel.userLogging();
    operationPanel = new OperationPanel(userPanel.getLoggedInUserId(), NAME_OF_INCOMES_FILE, NAME_OF_EXPENSES_FILE);
}

void PersonalBudget::loggedInUserPasswordChange() {
    userPanel.loggedInUserPasswordChange(userPanel.getLoggedInUserId());
}

void PersonalBudget::userLoggingOut() {
    userPanel.userLoggingOut();
    delete operationPanel;
    operationPanel = NULL;
}

void PersonalBudget::addIncome() {
    operationPanel -> addIncome();
}

void PersonalBudget::addExpense() {
    operationPanel -> addExpense();
}

void PersonalBudget::displayFinancialStatmentFromCurrentMonth() {
    operationPanel -> displayFinancialStatmentFromCurrentMonth();
}

void PersonalBudget::displayFinancialStatmentFromPreviousMonth() {
    operationPanel -> displayFinancialStatmentFromPreviousMonth();
}

char PersonalBudget::chooseOptionFromUserMenu() {
    char choice;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja." << endl;
    cout << "2. Logowanie." << endl;
    cout << "0. Koniec programu." << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}

char PersonalBudget::chooseOptionFromOperationMenu() {
    char choice;

    system("cls");
    cout << "    >>> BUDZET OSOBISTY <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod." << endl;
    cout << "2. Dodaj wydatek." << endl;
    cout << "3. Bilans z biezacego miesiaca." << endl;
    cout << "4. Bilans z poprzedniego miesiaca." << endl;
    cout << "5. Bilans z wybranego okresu." << endl;
    cout << "9. Zmien haslo." << endl;
    cout << "0. Wyloguj sie." << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
