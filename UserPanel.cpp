#include "UserPanel.h"

bool UserPanel::isUserLoggedIn(int userId) {
    if (userId > 0) {
        return true;
    } else {
        return false;
    }
}

int UserPanel::getLoggedInUserId() {
    return loggedInUserId;
}
