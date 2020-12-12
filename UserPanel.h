#ifndef USERPANEL_H
#define USERPANEL_H

#include <iostream>
#include <vector>
#include "User.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserPanel {
    vector<User> users;
    int loggedInUserId;

    User enterNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);

public:
    UserPanel() {
        loggedInUserId = 0;
    }

    void userRegister();
    bool isUserLoggedIn(int userId);

    int getLoggedInUserId();
};

#endif // USERPANEL_H
