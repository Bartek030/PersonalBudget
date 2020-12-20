#ifndef OPERATIONPANEL_H
#define OPERATIONPANEL_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <iomanip>
#include "FinancialOperationData.h"
#include "FileOperations.h"
#include "AuxiliaryMethods.h"
#include "CalendarOperations.h"

using namespace std;

class OperationPanel {
    vector<FinancialOperationData> incomes;
    vector<FinancialOperationData> expenses;
    FileOperations fileWithIncomes;
    FileOperations fileWithExpenses;
    int LOGGED_IN_USER_ID;

    FinancialOperationData enterNewOperationData(char operationChar);
    int getNewId(char operationChar);
    char chooseOptionFromIncomeMenu();
    char chooseOptionFromExpenseMenu();
    vector<FinancialOperationData> getIncomesFromMonth(string currentDate);
    vector<FinancialOperationData> getExpensesFromMonth(string currentDate);
    float displayIncomes(vector<FinancialOperationData> choosedIncomes);
    float displayExpenses(vector<FinancialOperationData> choosedExpenses);
    vector<FinancialOperationData> getIncomesFromPeriodOfTime(string startingDate, string endingDate);
    vector<FinancialOperationData> getExpensesFromPeriodOfTime(string startingDate, string endingDate);
    void displayBalance(int incomeSummary, int expenseSummary);

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
    void displayFinancialStatmentFromSelectedPeriodOfTime();
};

#endif // OPERATIONPANEL_H
