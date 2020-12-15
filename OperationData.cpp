#include "OperationData.h"

string OperationData::getOperationDate() {
    return operationDate;
};

string OperationData::getOperationDescription() {
    return operationDescription;
}

float OperationData::getAmount() {
    return amount;
}

int OperationData::getUserId() {
    return userId;
}

int OperationData::getOperationId() {
    return operationId;
}

void OperationData::setOperationDate(string date) {
    this -> operationDate = date;
}

void OperationData::setOperationDescription(string description) {
    this -> operationDescription = description;
}

void OperationData::setAmount(float amount) {
    this -> amount = amount;
}

void OperationData::setUserId(int userId) {
    this -> userId = userId;
}

void OperationData::setOperationId(int operationId) {
    this -> operationId = operationId;
}
