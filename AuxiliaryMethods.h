#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include<iostream>
#include<algorithm>

using namespace std;

class AuxiliaryMethods {

public:
    //static string konwerjsaIntNaString(int liczba);
    static int convertStringIntoInt(string number);
    static string loadLineFromUser();
    static char loadCharacter();
    static string changeFirstLetterToUpperAndRestToLower(string text);
    //static int podajIdWybranegoAdresata();
    //static int wczytajLiczbeCalkowita();
};

#endif // AUXILIARYMETHODS_H
