#ifndef BUDGETOPERATIONDATA_H
#define BUDGETOPERATIONDATA_H

#include <iostream>

using namespace std;

class BudgetOperationData {
    string operationDate;
    string operationDescription;
    float amount;

public:
    BudgetOperationData(){}

    string getOperationDate();
    string getOperationDescription();
    float getAmount();
    void setOperationDate(string date);
    void setOperationDescription(string description);
    void setAmount(float amount);
};

#endif // BUDGETOPERATIONDATA_H
