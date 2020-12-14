#include "BudgetOperationData.h"

string BudgetOperationData::getOperationDate() {
    return operationDate;
};

string BudgetOperationData::getOperationDescription() {
    return operationDescription;
}

float BudgetOperationData::getAmount() {
    return amount;
}

int BudgetOperationData::getUserId() {
    return userId;
}

void BudgetOperationData::setOperationDate(string date) {
    this -> operationDate = date;
}

void BudgetOperationData::setOperationDescription(string description) {
    this -> operationDescription = description;
}

void BudgetOperationData::setAmount(float amount) {
    this -> amount = amount;
}

void BudgetOperationData::setUserId(int userId) {
    this -> userId = userId;
}
