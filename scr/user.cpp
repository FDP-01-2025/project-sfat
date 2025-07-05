#include "user.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void SignUp() {
    string userName, password;

    cout << "=== Registro de Usuario ===" << endl;
    cout << "Ingrese nombre de usuario: ";
    cin >> userName;
    cout << "Ingrese contraseña: ";
    cin >> password;

    ofstream archive("usuarios.txt", ios::app);
    if (archive.is_open()) {
        archive << userName << " " << password << endl;
        archive.close();
        cout << "Usuario registrado con éxito.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }
}

bool logIn() {
    string userName, password, uN, p;

    cout << "=== Inicio de Sesión ===" << endl;
    cout << "Usuario: ";
    cin >> userName;
    cout << "Contraseña: ";
    cin >> password;

    ifstream archive("usuarios.txt");
    if (archive.is_open()) {
        while (archive >> uN >> p) {
            if (uN == userName && p == password) {
                cout << "Inicio de sesión exitoso. ¡Bienvenido " << uN << "!\n";
                archive.close();
                return true;
            }
        }

        archive.close();
        cout << "Usuario o contraseña incorrectos.\n";
    } else {
        cout << "Error al abrir el archivo.\n";
    }

    return false;
}
