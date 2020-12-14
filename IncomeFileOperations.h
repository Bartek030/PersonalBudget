#ifndef INCOMEFILEOPERATION_H
#define INCOMEFILEOPERATION_H

#include <iostream>
#include "IncomeOperationData.h"
#include "Markup.h"
#include "File.h"
#include "AuxiliaryMethods.h"

using namespace std;

class IncomeFileOperations : public File {
    const string PARENT_NAME;
    const string CHILD_INCOME_ID;
    const string CHILD_USER_ID;
    const string CHILD_DATE;
    const string CHILD_DESCRIPTION;
    const string CHILD_AMOUNT;
    const string XML_FILE_VERSION;

public:
    IncomeFileOperations(string nameOfIncomesFile) : File(nameOfIncomesFile), PARENT_NAME("Przychod"), CHILD_INCOME_ID("ID_operacji_przychodu"), CHILD_USER_ID("ID_uzytkownika"),
        CHILD_DATE("Data_operacji"), CHILD_DESCRIPTION("Opis_przychodu"), CHILD_AMOUNT("Kwota_przychodu"), XML_FILE_VERSION("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"){}

    void appendIncomeToFile(IncomeOperationData newIncome);
};

#endif // INCOMEFILEOPERATION_H
