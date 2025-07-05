#include <iostream>
#include <string>
#include <cstdlib>   // rand() y srand()
#include <ctime>     // time()
#include "levels.h"
using namespace std;

void level_01(){
    int decision;
    int plataform;
    bool success;
    int right_Path[5];

    // Generate random paths
    srand(time(0));
    for (int i = 0; i < 5; i++) {
        right_Path[i] = rand() % 5 + 1; // Numbers between 1 and 5
    }

    cout << "== MINIJUEGO #1: Cruza el puente ==" << endl;
    cout << "Debes adivinar la combinacion correcta para cruzar, un paso en falso y caeras al vacio." << endl;

    do {
        plataform = 1;
        success = true;

        while (plataform <= 5 && success) {
            cout << "Elige una opcion (1, 2, 3, 4 o 5): "<<endl;
            cout << "==================================" << endl;
            cout << "Plataforma " << plataform <<": ";
            cin >> decision;

            if (decision == right_Path[plataform - 1]) {
                cout << "Correcto! Avanzas a la siguiente plataforma." << endl;
                plataform++;
            } else {
                cout << "Incorrecto! Has caido." << endl;
                success = false;
            }
        }

    } while (!success);

    cout << "Felicidades! Has cruzado el puente sano y salvo." << endl;
}

