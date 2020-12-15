#include "FileOperations.h"

int FileOperations::getLastOperationId() {
    return lastOperationId;
}

vector<OperationData> FileOperations::loadOperationsFromFile(int loggedInUserId) {
    vector<OperationData> operations;
    OperationData operation;
    CMarkup xmlFile;

    bool fileExists = xmlFile.Load(getFileName());

    if (fileExists) {
        xmlFile.FindElem();
        xmlFile.IntoElem();
        while(xmlFile.FindElem(PARENT_NAME)) {
            xmlFile.FindChildElem(CHILD_OPERATION_ID);
            operation.setOperationId(AuxiliaryMethods::convertStringIntoInt(xmlFile.GetChildData()));
            lastOperationId = operation.getOperationId();
            xmlFile.FindChildElem(CHILD_USER_ID);
            operation.setUserId(AuxiliaryMethods::convertStringIntoInt(xmlFile.GetChildData()));
            if(operation.getUserId() != loggedInUserId) {
                continue;
            }
            xmlFile.FindChildElem(CHILD_DATE);
            operation.setOperationDate(xmlFile.GetChildData());
            xmlFile.FindChildElem(CHILD_DESCRIPTION);
            operation.setOperationDescription(xmlFile.GetChildData());
            xmlFile.FindChildElem(CHILD_AMOUNT);
            operation.setAmount(AuxiliaryMethods::convertStringIntoFloat(xmlFile.GetChildData()));
            operations.push_back(operation);
        }
    } else {
        return operations;
    }
    return operations;
}

void FileOperations::appendOperationToFile(OperationData newOperation) {
    CMarkup xmlFile;

    bool fileExists = xmlFile.Load(getFileName());

    if(!fileExists) {
        xmlFile.SetDoc(XML_FILE_VERSION);
        xmlFile.AddElem(getFileName());
    }
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem(PARENT_NAME);
    xmlFile.IntoElem();
    xmlFile.AddElem(CHILD_OPERATION_ID, newOperation.getOperationId());
    xmlFile.AddElem(CHILD_USER_ID, newOperation.getUserId());
    xmlFile.AddElem(CHILD_DATE, newOperation.getOperationDate());
    xmlFile.AddElem(CHILD_DESCRIPTION, newOperation.getOperationDescription());
    xmlFile.AddElem(CHILD_AMOUNT, AuxiliaryMethods::convertFloatIntoString(newOperation.getAmount()));

    lastOperationId++;
    xmlFile.Save(getFileName());
}
