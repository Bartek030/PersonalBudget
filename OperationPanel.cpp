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

void OperationPanel::displayFinancialStatmentFromCurrentMonth() {
    string currentDate = AuxiliaryMethods::getTodayDate();
    vector<OperationData> choosedIncomes = getIncomesFromCurrentMonth(currentDate);
    vector<OperationData> choosedExpenses = getExpensesFromCurrentMonth(currentDate);
    float incomeSummary = 0.0;
    float expenseSummary = 0.0;

    system("cls");
    incomeSummary = displayIncomes(choosedIncomes);
    expenseSummary = displayExpenses(choosedExpenses);

    cout << "BILANS: " << endl;
    if (incomeSummary > expenseSummary){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    } else if (incomeSummary < expenseSummary) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    cout << (incomeSummary - expenseSummary) << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    system("pause");
}

float OperationPanel::displayIncomes(vector<OperationData> choosedIncomes) {
    float incomeSummary = 0.0;

    cout << "    >>> DOCHODY: <<<" << endl << endl;

    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.setf(ios::fixed);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);

    for (int i = 0; i < choosedIncomes.size(); i++) {
        cout << setw(10) << choosedIncomes[i].getOperationDate() << setw(30) << choosedIncomes[i].getOperationDescription() << setw(10) << choosedIncomes[i].getAmount() << endl;
        incomeSummary += choosedIncomes[i].getAmount();
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    cout << "--------------------------------------------------" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "W SUMIE: " << incomeSummary << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

    system("pause");
    cout << endl;
    return incomeSummary;
}

float OperationPanel::displayExpenses(vector<OperationData> choosedExpenses) {
    float expenseSummary = 0.0;

    cout << "    >>> WYDATKI: <<<" << endl << endl;

    cout.setf(ios::showpoint);
    cout.precision(2);
    cout.setf(ios::fixed);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);

    for (int i = 0; i < choosedExpenses.size(); i++) {
        cout << setw(10) << choosedExpenses[i].getOperationDate() << setw(30) << choosedExpenses[i].getOperationDescription() << setw(10) << choosedExpenses[i].getAmount() << endl;
        expenseSummary += choosedExpenses[i].getAmount();
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    cout << "--------------------------------------------------" << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "W SUMIE: " << expenseSummary << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);

    system("pause");
    cout << endl;
    return expenseSummary;
}

vector<OperationData> OperationPanel::getIncomesFromCurrentMonth(string currentDate) {
    vector<OperationData> incomesFromCurrentMonth;
    for (int i = 0; i < incomes.size(); i++) {
        if (getYearAndMonthFromDate(currentDate) == getYearAndMonthFromDate(incomes[i].getOperationDate())) {
            if(incomesFromCurrentMonth.empty() == true) {
                incomesFromCurrentMonth.push_back(incomes[i]);
            } else {
                for (int j = 0; j < incomesFromCurrentMonth.size(); j++) {
                    if(AuxiliaryMethods::changeDateIntoIntegerValue(incomesFromCurrentMonth[j].getOperationDate()) >= AuxiliaryMethods::changeDateIntoIntegerValue(incomes[i].getOperationDate())) {
                        incomesFromCurrentMonth.insert(incomesFromCurrentMonth.begin() + j, incomes[i]);
                        break;
                    } else {
                        incomesFromCurrentMonth.push_back(incomes[i]);
                        break;
                    }
                }
            }
        }
    }
    return incomesFromCurrentMonth;
}

vector<OperationData> OperationPanel::getExpensesFromCurrentMonth(string currentDate) {
    vector<OperationData> expensesFromCurrentMonth;
    for (int i = 0; i < expenses.size(); i++) {
        if (getYearAndMonthFromDate(currentDate) == getYearAndMonthFromDate(expenses[i].getOperationDate())) {
            if(expensesFromCurrentMonth.empty() == true) {
                expensesFromCurrentMonth.push_back(expenses[i]);
            } else {
                for (int j = 0; j < expensesFromCurrentMonth.size(); j++) {
                    if(AuxiliaryMethods::changeDateIntoIntegerValue(expensesFromCurrentMonth[j].getOperationDate()) >= AuxiliaryMethods::changeDateIntoIntegerValue(expenses[i].getOperationDate())) {
                        expensesFromCurrentMonth.insert(expensesFromCurrentMonth.begin() + j, expenses[i]);
                        break;
                    } else {
                        expensesFromCurrentMonth.push_back(expenses[i]);
                        break;
                    }
                }
            }
        }
    }
    return expensesFromCurrentMonth;
}

int OperationPanel::getYearAndMonthFromDate(string date) {
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
