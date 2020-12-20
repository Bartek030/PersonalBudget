#ifndef FINANCIALOPERATIONDATA_H
#define FINANCIALOPERATIONDATA_H

#include <iostream>

using namespace std;

class FinancialOperationData {
    string operationDate;
    string operationDescription;
    float amount;
    int userId;
    int operationId;

public:
    FinancialOperationData(){}

    string getOperationDate();
    string getOperationDescription();
    float getAmount();
    int getUserId();
    int getOperationId();
    void setOperationDate(string date);
    void setOperationDescription(string description);
    void setAmount(float amount);
    void setUserId(int userId);
    void setOperationId(int operationId);
};

#endif // FINANCIALOPERATIONDATA_H
