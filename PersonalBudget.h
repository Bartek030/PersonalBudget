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

public:
    PersonalBudget(string nameOfUsersFile, string nameOfIncomesFile) : userPanel(nameOfUsersFile), NAME_OF_INCOMES_FILE(nameOfIncomesFile) {
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
    char chooseOptionFromUserMenu();
    char chooseOptionFromOperationMenu();
};

#endif // PERSONALBUDGET_H
