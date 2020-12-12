#include "UserFileOperations.h"

vector<User> UserFileOperations::loadUsersFromFile() {
    vector<User> users;
    User user;
    CMarkup xmlFile;

    bool fileExists = xmlFile.Load("users.xml");

    if (fileExists) {
        xmlFile.FindElem();
        xmlFile.IntoElem();
        while(xmlFile.FindElem("User")) {
            xmlFile.FindChildElem("ID_uzytkownika");
            user.setUserId(AuxiliaryMethods::convertStringIntoInt(xmlFile.GetChildData()));
            xmlFile.FindChildElem("Imie");
            user.setName(xmlFile.GetChildData());
            xmlFile.FindChildElem("Nazwisko");
            user.setSurname(xmlFile.GetChildData());
            xmlFile.FindChildElem("Login");
            user.setLogin(xmlFile.GetChildData());
            xmlFile.FindChildElem("Haslo");
            user.setPassword(xmlFile.GetChildData());
            users.push_back(user);
        }
    } else {
        return users;
    }
    return users;
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

