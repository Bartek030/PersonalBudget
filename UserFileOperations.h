#ifndef USERFILEOPERATIONS_H
#define USERFILEOPERATIONS_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserFileOperations {
    const string parentName;
    const string childId;
    const string childName;
    const string childSurname;
    const string childLogin;
    const string childPassword;

public:
    UserFileOperations() : parentName("User"), childId("ID_uzytkownika"), childName("Imie"), childSurname("Nazwisko"), childLogin("Login"), childPassword("Haslo"){}

    vector<User> loadUsersFromFile();
    void appendUserToFile(User user);
};

#endif // USERFILEOPERATIONS_H
