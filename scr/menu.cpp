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

}

void mainMenu() {
    int option;
    do {
        
        system("cls");
        gameTitle();

        cout << "\n==========================================" << endl;
        cout << "              MENU PRINCIPAL  " << endl;
        cout << "==========================================" << endl;
        cout << "  1.  Iniciar Partida" << endl;
        cout << "  2.  Volver al Menu de Usuario" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Seleccione una opcion: ";

        while (!(cin >> option)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada invalida. Por favor, ingrese un numero: ";
        }

        switch (option)
        {
        case 1:
            cout << "\n Cargando el juego...\n" << endl;
            gameplay();
            break;

        case 2:
            cout << "\n Regresando al Menu de Usuario...\n" << endl;
            break;
        
        default:
            cout << "\n Opción invalida. Intente de nuevo.\n" << endl;
            break;
        }
    } while (option != 2);
    
}

