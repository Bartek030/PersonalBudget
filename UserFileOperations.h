#ifndef USERFILEOPERATIONS_H
#define USERFILEOPERATIONS_H

#include <iostream>
#include <vector>
#include "User.h"
#include "Markup.h"
#include "AuxiliaryMethods.h"

using namespace std;

class UserFileOperations {
    const string PARENT_NAME;
    const string CHILD_ID;
    const string CHILD_NAME;
    const string CHILD_SURNAME;
    const string CHILD_LOGIN;
    const string CHILD_PASSWORD;
    const string XML_FILE_VERSION;

public:
    UserFileOperations() :  PARENT_NAME("User"), CHILD_ID("ID_uzytkownika"), CHILD_NAME("Imie"), CHILD_SURNAME("Nazwisko"),
                            CHILD_LOGIN("Login"), CHILD_PASSWORD("Haslo"), XML_FILE_VERSION("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n"){}

    vector<User> loadUsersFromFile();
    void appendUserToFile(User user);
    void changeLoggedInUserPasswordInFile(string newPassword, int loggedInUserId);
};

#endif // USERFILEOPERATIONS_H
