#ifndef OPERATIONPANEL_H
#define OPERATIONPANEL_H

#include <iostream>
#include <vector>
#include "IncomeOperationData.h"
#include "IncomeFileOperations.h"
#include "AuxiliaryMethods.h"

using namespace std;

class OperationPanel {
    vector<IncomeOperationData> incomes;
    IncomeFileOperations fileWithIncomes;
    int LOGGED_IN_USER_ID;

    IncomeOperationData enterNewIncomeData();
    int getNewIncomeId();
    char chooseOptionFromIncomeMenu();

public:
    OperationPanel(int loggedInUserId, string nameOfIncomesFile) : LOGGED_IN_USER_ID(loggedInUserId), fileWithIncomes(nameOfIncomesFile) {}

    void addIncome();
};

#endif // OPERATIONPANEL_H
