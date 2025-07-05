#include <iostream>
#include "menu.h"
#include "gameplay.h"
#include "levels.h"
using namespace std;

void mainMenu() {
    int option;
    do {
        
        gameTitle();

        cout << "\n==========================================" << endl;
        cout << "              MENU PRINCIPAL  " << endl;
        cout << "==========================================" << endl;
        cout << "  1.  Iniciar Partida" << endl;
        cout << "  2.  Volver al Menu de Usuario" << endl;
        cout << "------------------------------------------" << endl;
        cout << "Seleccione una opcion: ";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "\n Cargando el juego...\n" << endl;
            gameplay();
            break;

        case 2:
            cout << "\n Regresando al Menú de Usuario...\n" << endl;
            break;
        
        default:
            cout << "\n Opción inválida. Intente de nuevo.\n" << endl;
            break;
        }
    } while (option != 2);
    
}
