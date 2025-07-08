#include "user.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void SignUp() {
    string userName, password, uN, p;
    bool exists = false;

    cout << "\n==============================" << endl;
    cout << "        USER REGISTRATION       " << endl;
    cout << "================================" << endl;
    cout << "Enter username: ";
    cin >> userName;

    ifstream checkFile("usuarios.txt");
    if (checkFile.is_open()) {
        while (checkFile >> uN >> p) {
            if (uN == userName) {
                exists = true;
                break;
            }
        }
        checkFile.close();
    }

    if (exists) {
        cout << "\nThe username already exists" << endl;
        cout << "Please use a different one" << endl;
        return;
    }

    cout << "Enter password: ";
    cin >> password;

    ofstream archive("usuarios.txt", ios::app);
    if (archive.is_open()) {
        archive << userName << " " << password << endl;
        archive.close();
        cout << "\nUser successfully registered" << endl;
    } else {
        cout << "\nError opening file" << endl;
    }
}

bool logIn() {
    string userName, password, uN, p;

    cout << "\n==============================" << endl;
    cout << "              LOGIN             " << endl;
    cout << "================================" << endl;
    cout << "User: ";
    cin >> userName;
    cout << "Password: ";
    cin >> password;

    ifstream archive("usuarios.txt");
    if (archive.is_open()) {
        while (archive >> uN >> p) {
            if (uN == userName && p == password) {
                cout << "\nSuccessful login" << endl;
                cout << "Welcome " << uN << endl;
                archive.close();
                return true;
            }
        }

        archive.close();
        cout << "\nIncorrect username or password" << endl;
    } else {
        cout << "\nError opening file" << endl;
    }

    return false;
}
