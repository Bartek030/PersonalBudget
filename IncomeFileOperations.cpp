#include "IncomeFileOperations.h"

void IncomeFileOperations::appendIncomeToFile(IncomeOperationData newIncome) {
    CMarkup xmlFile;

    bool fileExists = xmlFile.Load(getFileName());

    if(!fileExists) {
        xmlFile.SetDoc(XML_FILE_VERSION);
        xmlFile.AddElem("Incomes");
    }
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem(PARENT_NAME);
    xmlFile.IntoElem();
    xmlFile.AddElem(CHILD_INCOME_ID, newIncome.getIncomeId());
    xmlFile.AddElem(CHILD_USER_ID, newIncome.getUserId());
    xmlFile.AddElem(CHILD_DATE, newIncome.getOperationDate());
    xmlFile.AddElem(CHILD_DESCRIPTION, newIncome.getOperationDescription());
    xmlFile.AddElem(CHILD_AMOUNT, AuxiliaryMethods::convertFloatIntoString(newIncome.getAmount()));

    xmlFile.Save(getFileName());
}
