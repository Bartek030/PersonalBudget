#ifndef USERPANEL_H
#define USERPANEL_H

#include <iostream>

using namespace std;

class UserPanel {
    int loggedInUserId;
public:
    UserPanel() {
        loggedInUserId = 0;
    }

    bool isUserLoggedIn(int userId);

    int getLoggedInUserId();
};

#endif // USERPANEL_H
