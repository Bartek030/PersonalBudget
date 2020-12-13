#include "UserFileOperations.h"

vector<User> UserFileOperations::loadUsersFromFile() {
    vector<User> users;
    User user;
    CMarkup xmlFile;

    bool fileExists = xmlFile.Load(getFileName());

    if (fileExists) {
        xmlFile.FindElem();
        xmlFile.IntoElem();
        while(xmlFile.FindElem(PARENT_NAME)) {
            xmlFile.FindChildElem(CHILD_ID);
            user.setUserId(AuxiliaryMethods::convertStringIntoInt(xmlFile.GetChildData()));
            xmlFile.FindChildElem(CHILD_NAME);
            user.setName(xmlFile.GetChildData());
            xmlFile.FindChildElem(CHILD_SURNAME);
            user.setSurname(xmlFile.GetChildData());
            xmlFile.FindChildElem(CHILD_LOGIN);
            user.setLogin(xmlFile.GetChildData());
            xmlFile.FindChildElem(CHILD_PASSWORD);
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

    bool fileExists = xmlFile.Load(getFileName());

    if(!fileExists) {
        xmlFile.SetDoc(XML_FILE_VERSION);
        xmlFile.AddElem("Users");
    }
    xmlFile.FindElem();
    xmlFile.IntoElem();
    xmlFile.AddElem(PARENT_NAME);
    xmlFile.IntoElem();
    xmlFile.AddElem(CHILD_ID, user.getUserId());
    xmlFile.AddElem(CHILD_NAME, user.getName());
    xmlFile.AddElem(CHILD_SURNAME, user.getSurname());
    xmlFile.AddElem(CHILD_LOGIN, user.getLogin());
    xmlFile.AddElem(CHILD_PASSWORD, user.getPassword());

    xmlFile.Save(getFileName());
}

void UserFileOperations::changeLoggedInUserPasswordInFile(string newPassword, int loggedInUserId) {
    CMarkup xmlFile;

    bool fileExists = xmlFile.Load(getFileName());

    if(fileExists) {
        xmlFile.FindElem();
        xmlFile.IntoElem();
        while(xmlFile.FindElem(PARENT_NAME)) {
            xmlFile.FindChildElem(CHILD_ID);
            if(AuxiliaryMethods::convertStringIntoInt(xmlFile.GetChildData()) == loggedInUserId) {
                xmlFile.FindChildElem(CHILD_PASSWORD);
                xmlFile.SetChildData(newPassword);
            }
        }
    } else {
        cout << "Nie udalo sie zmienic hasla w pliku. Plik nie istnieje!" << endl;
        system("pause");
    }
    xmlFile.Save(getFileName());
}
