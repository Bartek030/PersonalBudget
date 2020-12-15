#include "OperationPanel.h"

void OperationPanel::addIncome() {
    const char operationChar = '+';
    OperationData income = enterNewOperationData(operationChar);

    incomes.push_back(income);
    fileWithIncomes.appendOperationToFile(income);

    cout << endl << "Przychod zostal dodany pomyslnie" << endl << endl;
    system("pause");
}

void OperationPanel::addExpense() {
    const char operationChar = '-';
    OperationData expense = enterNewOperationData(operationChar);

    expenses.push_back(expense);
    fileWithExpenses.appendOperationToFile(expense);

    cout << endl << "Wydatek zostal dodany pomyslnie" << endl << endl;
    system("pause");
}

OperationData OperationPanel::enterNewOperationData(char operationChar) {
    OperationData newOperation;
    string operationDescription = "";
    float operationAmount;
    char userChoice;
    bool isChooseCorrect = false;

    system("cls");
    newOperation.setOperationId(getNewId(operationChar));
    newOperation.setUserId(LOGGED_IN_USER_ID);
    do {
        if(operationChar == '+') {
            userChoice = chooseOptionFromIncomeMenu();
        } else {
            userChoice = chooseOptionFromExpenseMenu();
        }
        switch(userChoice) {
        case '1':
            newOperation.setOperationDate(AuxiliaryMethods::getTodayDate());
            isChooseCorrect = true;
            break;
        case '2':
            newOperation.setOperationDate(AuxiliaryMethods::getDateFromUser());
            isChooseCorrect = true;
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    } while(!isChooseCorrect);

    cout << "Podaj opis operacji: ";
    operationDescription = AuxiliaryMethods::loadLineFromUser();
    newOperation.setOperationDescription(operationDescription);

    cout << "Podaj kwote operacji: ";
    operationAmount = AuxiliaryMethods::loadAmountFromUser();
    newOperation.setAmount(operationAmount);

    return newOperation;
}

int OperationPanel::getNewId(char operationChar) {
    if (operationChar == '+') {
        return fileWithIncomes.getLastOperationId() + 1;
    } else if(operationChar == '-') {
        return fileWithExpenses.getLastOperationId() + 1;
    }
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

char OperationPanel::chooseOptionFromExpenseMenu() {
    char choice;

    system("cls");
    cout << "    >>> DODAJ WYDATEK <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Wybierz dzien, w ktorym chcesz dodac wydatek:" << endl;
    cout << "1. Dzisiaj." << endl;
    cout << "2. Inna data." << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choice = AuxiliaryMethods::loadCharacter();

    return choice;
}
