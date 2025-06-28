#include <iostream>
#include "header.h"
using namespace std;

void level_01(){
    int decision;
    int plataforma;
    bool exito;

    int caminoCorrecto[5] = {2, 5, 3, 1, 4};

    cout << "== MINIJUEGO #1: Cruza el las 5 plataformas ==" << endl;
    cout << "Debes elegir la opcion correcta en cada plataforma para avanzar." << endl;

    do {
        plataforma = 1;
        exito = true;

        while (plataforma <= 5 && exito) {
            cout << "Elige una opcion (1, 2, 3, 4 o 5): "<<endl;
            cout << "==================================" << endl;
            cout << "Plataforma " << plataforma <<": ";
            cin >> decision;

            if (decision == caminoCorrecto[plataforma - 1]) {
                cout << "Correcto! Avanzas a la siguiente plataforma." << endl;
                plataforma++;
            } else {
                cout << "Incorrecto! Has caido." << endl;
                exito = false;
            }
        }

    } while (!exito);

    cout << "Felicidades! Has cruzado todas las plataformas." << endl;
}
