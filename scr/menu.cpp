#include <iostream>
#include "menu.h"
#include "levels.h"
using namespace std;

void mainMenu() {
    int option;
    do {
        cout << "\n=== Escapa del Templo Antiguo ===\n";
        cout << "=== Menú Principal ===\n";
        cout << "\n1. Iniciar Partida";
        cout << "\n2. Volver al Menú de Usuario\n";
        cout << "Seleccione una opción: ";
        cin >> option;

        switch (option)
        {
        case 1:
            level_01();
            break;

        case 2:
            cout << "\nRegresando al Menú de Usuario...\n";
            break;
        
        default:
            break;
        }
    } while (option != 2); // Sale cuando elige volver

    // Al salir del ciclo, mainMenu() termina y regresa al menú de usuario
}

