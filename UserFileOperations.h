#ifndef USERFILEOPERATIONS_H
#define USERFILEOPERATIONS_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserFileOperations {

public:
    UserFileOperations() {}

    vector<User> loadUsersFromFile();
    void appendUserToFile(User user);
};

#endif // USERFILEOPERATIONS_H
