#ifndef BUDGETOPERATIONDATA_H
#define BUDGETOPERATIONDATA_H

#include <iostream>

using namespace std;

class BudgetOperationData {
    string operationDate;
    string operationDescription;
    float amount;
    int userId;

public:
    BudgetOperationData(){}

    string getOperationDate();
    string getOperationDescription();
    float getAmount();
    int getUserId();
    void setOperationDate(string date);
    void setOperationDescription(string description);
    void setAmount(float amount);
    void setUserId(int userId);
};

#endif // BUDGETOPERATIONDATA_H
