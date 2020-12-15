#ifndef OPERATIONPANEL_H
#define OPERATIONPANEL_H

#include <iostream>
#include <vector>
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

public:
    OperationPanel(int loggedInUserId, string nameOfIncomesFile, string nameOfExpensesFile) : LOGGED_IN_USER_ID(loggedInUserId),
        fileWithIncomes(nameOfIncomesFile), fileWithExpenses(nameOfExpensesFile) {
        incomes = fileWithIncomes.loadOperationsFromFile(LOGGED_IN_USER_ID);
        expenses = fileWithExpenses.loadOperationsFromFile(LOGGED_IN_USER_ID);
    }

    void addIncome();
    void addExpense();
};

#endif // OPERATIONPANEL_H
