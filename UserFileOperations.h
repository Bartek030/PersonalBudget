#ifndef USERFILEOPERATIONS_H
#define USERFILEOPERATIONS_H

#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

class UserFileOperations {

public:
    UserFileOperations() {}

    void appendUserToFile();
    vector<User> loadUsersFromFile();
};

#endif // USERFILEOPERATIONS_H
