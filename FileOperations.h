#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#include <iostream>
#include <vector>
#include "FinancialOperationData.h"
#include "Markup.h"
#include "File.h"
#include "AuxiliaryMethods.h"

using namespace std;

class FileOperations : public File {
    const string PARENT_NAME;
    const string CHILD_OPERATION_ID;
    const string CHILD_USER_ID;
    const string CHILD_DATE;
    const string CHILD_DESCRIPTION;
    const string CHILD_AMOUNT;
    const string XML_FILE_VERSION;
    int lastOperationId;

public:
    FileOperations(string nameOfOperationFile) : File(nameOfOperationFile),
        PARENT_NAME("Operacja"), CHILD_OPERATION_ID("ID_operacji"), CHILD_USER_ID("ID_uzytkownika"),
        CHILD_DATE("Data_operacji"), CHILD_DESCRIPTION("Opis_operacji"), CHILD_AMOUNT("Kwota_operacji"),
        XML_FILE_VERSION("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"){
            lastOperationId = 0;
        }

    vector<FinancialOperationData> loadOperationsFromFile(int loggedInUserId);
    void appendOperationToFile(FinancialOperationData newOperation);

    int getLastOperationId();
};

#endif // FILEOPERATIONS_H
