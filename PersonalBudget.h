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
    char chooseOptionFromUserMenu();
};

#endif // PERSONALBUDGET_H
