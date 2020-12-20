#include "FinancialOperationData.h"

string FinancialOperationData::getOperationDate() {
    return operationDate;
};

string FinancialOperationData::getOperationDescription() {
    return operationDescription;
}

float FinancialOperationData::getAmount() {
    return amount;
}

int FinancialOperationData::getUserId() {
    return userId;
}

int FinancialOperationData::getOperationId() {
    return operationId;
}

void FinancialOperationData::setOperationDate(string date) {
    this -> operationDate = date;
}

void FinancialOperationData::setOperationDescription(string description) {
    this -> operationDescription = description;
}

void FinancialOperationData::setAmount(float amount) {
    this -> amount = amount;
}

void FinancialOperationData::setUserId(int userId) {
    this -> userId = userId;
}

void FinancialOperationData::setOperationId(int operationId) {
    this -> operationId = operationId;
}
