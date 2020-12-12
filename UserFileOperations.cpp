#include "UserFileOperations.h"

vector<User> loadUsersFromFile() {
    vector<User> users;
    User user;
    CMarkup xmlFile;

    bool fileExists = xmlFile.Load("users.xml");

    if (fileExists){

    } else {
        return users;
    }
}

void UserFileOperations::appendUserToFile(User user) {
    CMarkup xmlFile;

    bool fileExists = xmlFile.Load("users.xml");

    if(!fileExists) {
        xmlFile.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xmlFile.AddElem("Users");
    }
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem("User");
    xmlFile.IntoElem();
    xmlFile.AddElem("ID_uzytkownika", user.getUserId());
    xmlFile.AddElem("Imie", user.getName());
    xmlFile.AddElem("Nazwisko", user.getSurname());
    xmlFile.AddElem("Login", user.getLogin());
    xmlFile.AddElem("Haslo", user.getPassword());

    xmlFile.Save("users.xml");
}

