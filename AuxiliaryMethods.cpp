#include "AuxiliaryMethods.h"
#include <sstream>

/*string MetodyPomocnicze::konwerjsaIntNaString(int liczba) {
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}*/

int AuxiliaryMethods::convertStringIntoInt(string number) {
    return atoi(number.c_str());
}

string AuxiliaryMethods::loadLineFromUser() {
    string inputFromUser = "";
    cin.clear();
    cin.sync();
    getline(cin, inputFromUser);
    return inputFromUser;
}

char AuxiliaryMethods::loadCharacter() {
    string inputFromUser = "";
    char singleCharacter  = {0};

    while (true) {
        cin.clear();
        cin.sync();
        getline(cin, inputFromUser);

        if (inputFromUser.length() == 1) {
            singleCharacter = inputFromUser[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return singleCharacter;
}

string AuxiliaryMethods::changeFirstLetterToUpperAndRestToLower(string text) {
    if (!text.empty()) {
        transform(text.begin(), text.end(), text.begin(), ::tolower);
        text[0] = toupper(text[0]);
    }
    return text;
}

/*int MetodyPomocnicze::podajIdWybranegoAdresata() {
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}*/

/*int MetodyPomocnicze::wczytajLiczbeCalkowita() {
    string wejscie = "";
    int liczba = 0;

    while (true) {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}*/
