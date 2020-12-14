#ifndef OPERATIONPANEL_H
#define OPERATIONPANEL_H

#include <iostream>
#include <vector>
#include "IncomeOperationData.h"
#include "AuxiliaryMethods.h"

using namespace std;

class OperationPanel {
    vector<IncomeOperationData> incomes;
    int LOGGED_IN_USER_ID;

    IncomeOperationData enterNewIncomeData();
    int getNewIncomeId();
    char chooseOptionFromIncomeMenu();

public:
    OperationPanel(int loggedInUserId) : LOGGED_IN_USER_ID(loggedInUserId) {}

    void addIncome();
};

#endif // OPERATIONPANEL_H
