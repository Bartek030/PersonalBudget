#ifndef OPERATIONDATA_H
#define OPERATIONDATA_H

#include <iostream>

using namespace std;

class OperationData {
    string operationDate;
    string operationDescription;
    float amount;
    int userId;
    int operationId;

public:
    OperationData(){}

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

#endif // OPERATIONDATA_H
