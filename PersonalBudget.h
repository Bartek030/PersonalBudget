#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserPanel.h"
#include "OperationPanel.h"

using namespace std;

class PersonalBudget {
    UserPanel userPanel;
    OperationPanel *operationPanel;
    const string NAME_OF_INCOMES_FILE;
    const string NAME_OF_EXPENSES_FILE;

public:
    PersonalBudget(string nameOfUsersFile, string nameOfIncomesFile, string nameOfExpensesFile) : userPanel(nameOfUsersFile),
                                        NAME_OF_INCOMES_FILE(nameOfIncomesFile), NAME_OF_EXPENSES_FILE(nameOfExpensesFile) {
        operationPanel = NULL;
    }
    ~PersonalBudget() {
        delete operationPanel;
        operationPanel = NULL;
    }

    void userRegister();
    bool isUserLoggedIn();
    void userLogging();
    void loggedInUserPasswordChange();
    void userLoggingOut();
    void addIncome();
    void addExpense();
    void displayFinancialStatmentFromCurrentMonth();
    void displayFinancialStatmentFromPreviousMonth();
    void displayFinancialStatmentFromSelectedPeriodOfTime();
    char chooseOptionFromUserMenu();
    char chooseOptionFromOperationMenu();
};

#endif // PERSONALBUDGET_H
