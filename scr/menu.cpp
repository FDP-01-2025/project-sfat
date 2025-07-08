#include <iostream>
#include <limits>
#include "menu.h"
#include "gameplay.h"
#include "levels.h"
#include "user.h"
using namespace std;

void userMenu() {
    int option;
    bool logged_In = false;

    do {

        cout << endl;
        cout << "============================" << endl;
        cout << "           USER MENU        " << endl;
        cout << "============================" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";

        while (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid entry. Please enter a number: ";
        }

        switch (option) {
            case 1:
                SignUp();
                break;
            case 2:
                logged_In = logIn();
                if (logged_In) mainMenu();
                break;
            case 3:
                cout << "Leaving..." << endl;
                break;
            default:
                cout << "Invalid option" << endl;
        }

    } while (option != 3);

}

void mainMenu() {
    int option;
    do {
        
        system("cls");
        gameTitle();

        cout << "\n==========================================" << endl;
        cout << "              MAIN MENU  " << endl;
        cout << "==========================================" << endl;
        cout << "  1.  Start Game" << endl;
        cout << "  2.  Return to the User Menu" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Select an option: ";

        while (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid entry. Please enter a number: ";
        }

        switch (option)
        {
        case 1:
            cout << "\n Loading game...\n" << endl;
            gameplay();
            break;

        case 2:
            cout << "\n Returning to the User Menu...\n" << endl;
            break;
        
        default:
            cout << "\n Invalid option. Please try again.\n" << endl;
            break;
        }
    } while (option != 2);
    
}

