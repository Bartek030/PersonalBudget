#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include <iostream>
#include "UserPanel.h"

using namespace std;

class PersonalBudget {
    UserPanel userPanel;

public:
    PersonalBudget() {}
    ~PersonalBudget() {}

    void userRegister();
    bool isUserLoggedIn();
    void userLogging();
    void loggedInUserPasswordChange();
    void userLoggingOut();
    char chooseOptionFromUserMenu();
    char chooseOptionFromOperationMenu();
};

#endif // PERSONALBUDGET_H
