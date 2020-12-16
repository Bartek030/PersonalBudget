#ifndef OPERATIONPANEL_H
#define OPERATIONPANEL_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include "OperationData.h"
#include "FileOperations.h"
#include "AuxiliaryMethods.h"

using namespace std;

class OperationPanel {
    vector<OperationData> incomes;
    vector<OperationData> expenses;
    FileOperations fileWithIncomes;
    FileOperations fileWithExpenses;
    int LOGGED_IN_USER_ID;

    OperationData enterNewOperationData(char operationChar);
    int getNewId(char operationChar);
    char chooseOptionFromIncomeMenu();
    char chooseOptionFromExpenseMenu();
    int getYearAndMonthFromDate(string date);
    vector<OperationData> getIncomesFromMonth(string currentDate);
    vector<OperationData> getExpensesFromMonth(string currentDate);
    float displayIncomes(vector<OperationData> choosedIncomes);
    float displayExpenses(vector<OperationData> choosedExpenses);

public:
    OperationPanel(int loggedInUserId, string nameOfIncomesFile, string nameOfExpensesFile) : LOGGED_IN_USER_ID(loggedInUserId),
        fileWithIncomes(nameOfIncomesFile), fileWithExpenses(nameOfExpensesFile) {
        incomes = fileWithIncomes.loadOperationsFromFile(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadOperationsFromFile(LOGGED_IN_USER_ID);
    }

    void addIncome();
    void addExpense();
    void displayFinancialStatmentFromCurrentMonth();
    void displayFinancialStatmentFromPreviousMonth();
};

#endif // OPERATIONPANEL_H
