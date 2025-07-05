#include "user.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void SignUp() {
    string userName, password, uN, p;
    bool exists = false;

    cout << "\n==============================" << endl;
    cout << "      REGISTRO DE USUARIO     " << endl;
    cout << "==============================" << endl;
    cout << "Ingrese nombre de usuario: ";
    cin >> userName;

    // Check if there is a user with an existing UserName
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
        cout << "\nEl nombre de usuario ya existe" << endl;
        cout << "Por favor use otro diferente" << endl;
        return;
    }

    cout << "Ingrese contraseña: ";
    cin >> password;

    ofstream archive("usuarios.txt", ios::app);
    if (archive.is_open()) {
        archive << userName << " " << password << endl;
        archive.close();
        cout << "\nUsuario registrado con exito" << endl;
    } else {
        cout << "\nError al abrir el archivo" << endl;
    }
}

bool logIn() {
    string userName, password, uN, p;

    cout << "\n==============================" << endl;
    cout << "        INICIO DE SESION      " << endl;
    cout << "==============================" << endl;
    cout << "Usuario: ";
    cin >> userName;
    cout << "Contraseña: ";
    cin >> password;

    ifstream archive("usuarios.txt");
    if (archive.is_open()) {
        while (archive >> uN >> p) {
            if (uN == userName && p == password) {
                cout << "\nInicio de sesion exitoso" << endl;
                cout << "Bienvenido " << uN << endl;
                archive.close();
                return true;
            }
        }

        archive.close();
        cout << "\nUsuario o contraseña incorrectos" << endl;
    } else {
        cout << "\nError al abrir el archivo" << endl;
    }

    return false;
}
