#include <iostream>
#include <limits>
#include <fstream>
#include "scr/gameplay.h"
#include "scr/user.h"
#include "scr/menu.h"
using namespace std;

int main() {
    int option;
    bool logged_In = false;

    do {

        cout << endl;
        cout << "==============================" << endl;
        cout << "        MENU DE USUARIO       " << endl;
        cout << "==============================" << endl;
        cout << "1. Registrarse" << endl;
        cout << "2. Iniciar Sesion" << endl;
        cout << "3. Salir" << endl;
        cout << "Seleccione una opcion: ";

        while (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, ingrese un numero: ";
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
                cout << "Saliendo..." << endl;
                break;
            default:
                cout << "Opcion invalida" << endl;
        }

    } while (option != 3);

    return 0;
}
