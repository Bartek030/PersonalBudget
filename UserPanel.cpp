#include "UserPanel.h"

void UserPanel::userRegister() {
    User user = enterNewUserData();

    users.push_back(user);
    fileWithUsers.appendUserToFile(user);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserPanel::enterNewUserData() {
    User user;
    string name, surname, login, password;

    user.setUserId(getNewUserId());
    cout << "Podaj imie: ";
    name = AuxiliaryMethods::changeFirstLetterToUpperAndRestToLower(AuxiliaryMethods::loadLineFromUser());
    user.setName(name);
    cout << "Podaj nazwisko: ";
    surname = AuxiliaryMethods::changeFirstLetterToUpperAndRestToLower(AuxiliaryMethods::loadLineFromUser());
    user.setSurname(surname);

    do {
        cout << "Podaj login: ";
        login = AuxiliaryMethods::loadLineFromUser();
        user.setLogin(login);
    } while (isLoginExist(user.getLogin()));

    do {
        cout << "Podaj haslo: ";
        password = AuxiliaryMethods::loadLineFromUser();
        user.setPassword(password);
    } while (!isPasswordStrongEnough(user.getPassword()));
    return user;
}

int UserPanel::getNewUserId() {
    return (users.empty()) ? 1 : users.back().getUserId() + 1;
}

bool UserPanel::isLoginExist(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

bool UserPanel::isPasswordStrongEnough(string password) {
    bool isAtleastOneUpperLetter = false;
    bool isAtleastOneDigit = false;
    bool isAtleastEightCharacters = false;

    if (password.length() >= 8) {
        isAtleastEightCharacters = true;
    }
    for (int i = 0; i < password.length(); i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            isAtleastOneUpperLetter = true;
        }
        if (password[i] >= '0' && password[i] <= '9') {
            isAtleastOneDigit = true;
        }
    }
    if (isAtleastOneUpperLetter && isAtleastOneDigit && isAtleastEightCharacters) {
        return true;
    } else {
        cout << endl << "Podane haslo nie jest wystarczajaco silne. Haslo musi zawierac min. 8 znakow, 1 cyfre i jedna duza litere." << endl;
        return false;
    }
}

bool UserPanel::isUserLoggedIn(int userId) {
    if (userId > 0) {
        return true;
    } else {
        return false;
    }
}

void UserPanel::userLogging() {
    string login = "", password = "";

    cout << endl << "Podaj login: ";
    login = AuxiliaryMethods::loadLineFromUser();

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--) {
                cout << "Podaj haslo. Pozostalo prob: " << numberOfAttempts << ": ";
                password = AuxiliaryMethods::loadLineFromUser();

                if (users[i].getPassword() == password) {
                    cout << endl << "Zalogowales sie. Witaj " << users[i].getName() << "! Milo Cie widziec! :-)" << endl << endl;
                    system("pause");
                    loggedInUserId = users[i].getUserId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;

}

void UserPanel::loggedInUserPasswordChange(int loggedInUserId) {
    string newPassword = "";

    do {
    cout << "Podaj nowe haslo: ";
    newPassword = AuxiliaryMethods::loadLineFromUser();
    } while(!isPasswordStrongEnough(newPassword));

    for (int i = 0; i < users.size(); i++)
    {
        if (users[i].getUserId() == loggedInUserId)
        {
            users[i].setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.changeLoggedInUserPasswordInFile(newPassword, loggedInUserId);
}

void UserPanel::userLoggingOut() {
    loggedInUserId = 0;
    cout << endl << "Wylogowales sie." << endl;
    system("pause");
}

int UserPanel::getLoggedInUserId() {
    return loggedInUserId;
}
