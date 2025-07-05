#include <iostream>
#include <fstream>
#include "scr/levels.h"
#include "scr/user.h"
#include "scr/menu.h"
using namespace std;

int main() {
    int option;
    bool logged_In = false;

    do {
        cout << "\n=== Menú de Usuario ===\n";
        cout << "1. Registrarse\n";
        cout << "2. Iniciar Sesión\n";
        cout << "3. Salir\n";
        cout << "Seleccione una opción: ";
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
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
        
    } while (option != 3);

    return 0;
}
