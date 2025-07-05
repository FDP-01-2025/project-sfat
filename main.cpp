#include <iostream>
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
        cin >> option;

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
