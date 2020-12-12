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
    } while (isLoginExist(user.getLogin()) == true);

    do {
        cout << "Podaj haslo: ";
        password = AuxiliaryMethods::loadLineFromUser();
        user.setPassword(password);
    } while (!isPasswordStrongEnough(user.getPassword()) == true);
    return user;
}

int UserPanel::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
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
        cout << endl << "Podane haslo nie jest wystarczajaco silne." << endl;
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

int UserPanel::getLoggedInUserId() {
    return loggedInUserId;
}
