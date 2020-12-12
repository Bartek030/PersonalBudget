#include "UserPanel.h"

void UserPanel::userRegister() {
    User user = enterNewUserData();

    users.push_back(user);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserPanel::enterNewUserData() {
    User user;
    string name, surname, login, password;

    user.setUserId(getNewUserId());
    cout << "Podaj imie: ";
    name = AuxiliaryMethods::loadLineFromUser();
    user.setName(name);
    cout << "Podaj nazwisko: ";
    surname = AuxiliaryMethods::loadLineFromUser();
    user.setName(surname);

    do {
        cout << "Podaj login: ";
        login = AuxiliaryMethods::loadLineFromUser();
        user.setLogin(login);
    } while (isLoginExist(user.getLogin()) == true);

    cout << "Podaj haslo: ";
    password = AuxiliaryMethods::loadLineFromUser();
    user.setPassword(password);

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
