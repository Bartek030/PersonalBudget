#ifndef USERFILEOPERATIONS_H
#define USERFILEOPERATIONS_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"

using namespace std;

class UserFileOperations {

public:
    UserFileOperations() {}

    void appendUserToFile(User user);
    vector<User> loadUsersFromFile();
};

#endif // USERFILEOPERATIONS_H
