#include <iostream>
#include "PersonalBudget.h"

using namespace std;

int main() {
    PersonalBudget userPersonalBudget("users.xml", "incomes.xml");
    char userChoice;

    while (true) {
        if (userPersonalBudget.isUserLoggedIn() == false) {
            userChoice = userPersonalBudget.chooseOptionFromUserMenu();
            switch (userChoice) {
            case '1':
                userPersonalBudget.userRegister();
                break;
            case '2':
                userPersonalBudget.userLogging();
                break;
            case '0':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            userChoice = userPersonalBudget.chooseOptionFromOperationMenu();

            switch (userChoice) {
            case '1':
                userPersonalBudget.addIncome();
                break;
            case '2':
                //userPersonalBudget.addExpense();
                break;
            case '3':
                //userPersonalBudget.displayFinancialStatmentFromCurrentMonth();
                break;
            case '4':
                //userPersonalBudget.displayFinancialStatmentFromLastMonth();
                break;
            case '5':
                //userPersonalBudget.displayFinancialStatmentFromSelectedPeriodOfTime();
                break;
            case '9':
                userPersonalBudget.loggedInUserPasswordChange();
                break;
            case '0':
                userPersonalBudget.userLoggingOut();
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}
