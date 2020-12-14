#ifndef SZABLON_H
#define SZABLON_H

#include <iostream>
#include "BudgetOperationData.h"

using namespace std;

class IncomeOperationData : public BudgetOperationData {
    int incomeId;

public:
    int getIncomeId();
    void setIncomeId(int incomeId);
};

#endif // SZABLON_H
