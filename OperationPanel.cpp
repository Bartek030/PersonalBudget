#include "OperationPanel.h"

void OperationPanel::addIncome() {
    const char operationChar = '+';
    FinancialOperationData income = enterNewOperationData(operationChar);

    incomes.push_back(income);
    fileWithIncomes.appendOperationToFile(income);

    cout << endl << "Przychod zostal dodany pomyslnie" << endl << endl;
    system("pause");
}

void OperationPanel::addExpense() {
    const char operationChar = '-';
    FinancialOperationData expense = enterNewOperationData(operationChar);

    expenses.push_back(expense);
    fileWithExpenses.appendOperationToFile(expense);

    cout << endl << "Wydatek zostal dodany pomyslnie" << endl << endl;
    system("pause");
}

FinancialOperationData OperationPanel::enterNewOperationData(char operationChar) {
    FinancialOperationData newOperation;
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
            newOperation.setOperationDate(CalendarOperations::getTodayDate());
            isChooseCorrect = true;
            break;
        case '2':
            newOperation.setOperationDate(CalendarOperations::getDateFromUser());
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
    cout << endl;

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
    cout << endl;

    return choice;
}

void OperationPanel::displayBalance(int incomeSummary, int expenseSummary) {
    if (incomeSummary > expenseSummary){
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    } else if (incomeSummary < expenseSummary) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    }
    cout << (incomeSummary - expenseSummary) << endl << endl;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
    system("pause");
}

void OperationPanel::displayFinancialStatmentFromCurrentMonth() {
    string currentDate = CalendarOperations::getTodayDate();
    vector<FinancialOperationData> choosedIncomes = getIncomesFromMonth(currentDate);
    vector<FinancialOperationData> choosedExpenses = getExpensesFromMonth(currentDate);
    float incomeSummary = 0.0;
    float expenseSummary = 0.0;

    system("cls");
    incomeSummary = displayIncomes(choosedIncomes);
    expenseSummary = displayExpenses(choosedExpenses);
    cout << "BILANS: " << endl;
    displayBalance(incomeSummary, expenseSummary);
}

void OperationPanel::displayFinancialStatmentFromPreviousMonth() {
    string previousMonthDate = CalendarOperations::getPreviousMonthDate();
    vector<FinancialOperationData> choosedIncomes = getIncomesFromMonth(previousMonthDate);
    vector<FinancialOperationData> choosedExpenses = getExpensesFromMonth(previousMonthDate);
    float incomeSummary = 0.0;
    float expenseSummary = 0.0;

    system("cls");
    incomeSummary = displayIncomes(choosedIncomes);
    expenseSummary = displayExpenses(choosedExpenses);
    cout << "BILANS: " << endl;
    displayBalance(incomeSummary, expenseSummary);
}

void OperationPanel::displayFinancialStatmentFromSelectedPeriodOfTime() {
    string startingDate = "";
    string endingDate = "";
    vector<FinancialOperationData> choosedIncomes;
    vector<FinancialOperationData> choosedExpenses;
    float incomeSummary = 0.0;
    float expenseSummary = 0.0;

    system("cls");
    cout << "PODAJ POCZATKOWA DATE" << endl;
    startingDate = CalendarOperations::getDateFromUser();
    cout << endl;
    cout << "PODAJ KONCOWA DATE" << endl;
    endingDate = CalendarOperations::getDateFromUser();
    cout << endl;

    choosedIncomes = getIncomesFromPeriodOfTime(startingDate, endingDate);
    choosedExpenses = getExpensesFromPeriodOfTime(startingDate, endingDate);
    incomeSummary = displayIncomes(choosedIncomes);
    expenseSummary = displayExpenses(choosedExpenses);

    cout << "BILANS OD " << startingDate << " DO " << endingDate << ":" << endl;
    displayBalance(incomeSummary, expenseSummary);
}

float OperationPanel::displayIncomes(vector<FinancialOperationData> choosedIncomes) {
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

float OperationPanel::displayExpenses(vector<FinancialOperationData> choosedExpenses) {
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

vector<FinancialOperationData> OperationPanel::getIncomesFromMonth(string currentDate) {
    vector<FinancialOperationData> incomesFromCurrentMonth;
    for (int i = 0; i < incomes.size(); i++) {
        if (CalendarOperations::getYearAndMonthFromDate(currentDate) == CalendarOperations::getYearAndMonthFromDate(incomes[i].getOperationDate())) {
            if(incomesFromCurrentMonth.empty() == true) {
                incomesFromCurrentMonth.push_back(incomes[i]);
            } else {
                for (int j = 0; j < incomesFromCurrentMonth.size(); j++) {
                    if(CalendarOperations::changeDateIntoIntegerValue(incomesFromCurrentMonth[j].getOperationDate()) >= CalendarOperations::changeDateIntoIntegerValue(incomes[i].getOperationDate())) {
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

vector<FinancialOperationData> OperationPanel::getExpensesFromMonth(string currentDate) {
    vector<FinancialOperationData> expensesFromCurrentMonth;
    for (int i = 0; i < expenses.size(); i++) {
        if (CalendarOperations::getYearAndMonthFromDate(currentDate) == CalendarOperations::getYearAndMonthFromDate(expenses[i].getOperationDate())) {
            if(expensesFromCurrentMonth.empty() == true) {
                expensesFromCurrentMonth.push_back(expenses[i]);
            } else {
                for (int j = 0; j < expensesFromCurrentMonth.size(); j++) {
                    if(CalendarOperations::changeDateIntoIntegerValue(expensesFromCurrentMonth[j].getOperationDate()) >= CalendarOperations::changeDateIntoIntegerValue(expenses[i].getOperationDate())) {
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

vector<FinancialOperationData> OperationPanel::getIncomesFromPeriodOfTime(string startingDate, string endingDate) {
    vector<FinancialOperationData> incomesFromPeriodOfTime;
    for (int i = 0; i < incomes.size(); i++) {
        if (CalendarOperations::changeDateIntoIntegerValue(startingDate) <= CalendarOperations::changeDateIntoIntegerValue(incomes[i].getOperationDate()) && CalendarOperations::changeDateIntoIntegerValue(endingDate) >= CalendarOperations::changeDateIntoIntegerValue(incomes[i].getOperationDate())) {
            if(incomesFromPeriodOfTime.empty() == true) {
                incomesFromPeriodOfTime.push_back(incomes[i]);
            } else {
                for (int j = 0; j < incomesFromPeriodOfTime.size(); j++) {
                    if(CalendarOperations::changeDateIntoIntegerValue(incomesFromPeriodOfTime[j].getOperationDate()) >= CalendarOperations::changeDateIntoIntegerValue(incomes[i].getOperationDate())) {
                        incomesFromPeriodOfTime.insert(incomesFromPeriodOfTime.begin() + j, incomes[i]);
                        break;
                    } else {
                        incomesFromPeriodOfTime.push_back(incomes[i]);
                        break;
                    }
                }
            }
        }
    }
    return incomesFromPeriodOfTime;
}

vector<FinancialOperationData> OperationPanel::getExpensesFromPeriodOfTime(string startingDate, string endingDate) {
    vector<FinancialOperationData> expensesFromPeriodOfTime;
    for (int i = 0; i < expenses.size(); i++) {
        if (CalendarOperations::changeDateIntoIntegerValue(startingDate) <= CalendarOperations::changeDateIntoIntegerValue(expenses[i].getOperationDate()) && CalendarOperations::changeDateIntoIntegerValue(endingDate) >= CalendarOperations::changeDateIntoIntegerValue(expenses[i].getOperationDate())) {
            if(expensesFromPeriodOfTime.empty() == true) {
                expensesFromPeriodOfTime.push_back(expenses[i]);
            } else {
                for (int j = 0; j < expensesFromPeriodOfTime.size(); j++) {
                    if(CalendarOperations::changeDateIntoIntegerValue(expensesFromPeriodOfTime[j].getOperationDate()) >= CalendarOperations::changeDateIntoIntegerValue(expenses[i].getOperationDate())) {
                        expensesFromPeriodOfTime.insert(expensesFromPeriodOfTime.begin() + j, expenses[i]);
                        break;
                    } else {
                        expensesFromPeriodOfTime.push_back(expenses[i]);
                        break;
                    }
                }
            }
        }
    }
    return expensesFromPeriodOfTime;
}
