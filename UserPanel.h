#ifndef USERPANEL_H
#define USERPANEL_H

#include <iostream>
#include <vector>
#include "User.h"
#include "UserFileOperations.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserPanel {
    vector<User> users;
    UserFileOperations fileWithUsers;
    int loggedInUserId;

    User enterNewUserData();
    int getNewUserId();
    bool isLoginExist(string login);
    bool isPasswordStrongEnough(string password);

public:
    UserPanel() {
        users = fileWithUsers.loadUsersFromFile();
        loggedInUserId = 0;
    }

    void userRegister();
    bool isUserLoggedIn(int userId);
    void userLogging();
    void userLoggingOut();
    void loggedInUserPasswordChange(int loggedInUserId);

    int getLoggedInUserId();
};

#endif // USERPANEL_H
