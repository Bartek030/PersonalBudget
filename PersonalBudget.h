#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserPanel.h"
#include "OperationPanel.h"

using namespace std;

class PersonalBudget {
    UserPanel userPanel;
    OperationPanel *operationPanel;

public:
    PersonalBudget(string nameOfUsersFile) : userPanel(nameOfUsersFile) {
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
