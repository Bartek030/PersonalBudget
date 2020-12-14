#include "OperationPanel.h"

void OperationPanel::addIncome() {
    /*IncomeOperationData income = enterNewIncomeData();

    incomes.push_back(user);
    fileWithUsers.appendUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");*/
}
/*
IncomeOperationData OperationPanel::enterNewIncomeData() {
    IncomeOperationData newIncome;
    string incomeDescription = "";
    string incomeAmount = "";
    char userChoice;

    system("cls");
    newIncome.setIncomeId(getNewIncomeId());
    do {
        userChoice = chooseOptionFromIncomeMenu();
        switch(userChoice) {
        case 1:
            newIncome.setOperationDate(AuxiliaryMethods::getTodayDate());
            break;
        case 2:
            newIncome.setOperationDate(AuxiliaryMethods::getDateFromUser());
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    } while();

    cout << "Podaj zrodlo przychodu: ";
    incomeDescription = AuxiliaryMethods::loadLineFromUser();
    newIncome.setOperationDescription(incomeDescription);

    do {
        cout << "Podaj kwote przychodu: ";
        incomeAmount = AuxiliaryMethods::loadLineFromUser();
        newIncome.setAmount();
    } while ();

    return newIncome;
}

int OperationPanel::getNewIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

char OperationPanel::chooseOptionFromIncomeMenu() {
    char choice;

    system("cls");
    cout << "    >>> DODAJ PRZYCHOD <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Wybierz dzien, w ktorym chcesz dodac przychod:" << endl;
    cout << "1. Dzisiaj." << endl;
    cout << "2. Inna data." << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
*/
