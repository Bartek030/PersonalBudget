#include "PersonalBudget.h"

bool PersonalBudget::isUserLoggedIn() {
    return userPanel.isUserLoggedIn(userPanel.getLoggedInUserId());
}
