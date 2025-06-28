#include <iostream>
#include <string>
using namespace std;

int main() {
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
            cout << "Plataforma " << plataforma << endl;
            cin >> decision;

            if (decision == caminoCorrecto[plataforma - 1]) {
                cout << "Correcto! Avanzas a la siguiente plataforma." << endl;
                plataforma++;
            } else {
                cout << "Incorrecto! Has caido." << endl;
                exito = false;
            }
        }

        if (!exito) {
            cout <<"Quieres volver a intentarlo? ('1' = si / '0' = no): ";
            int opcion;
            cin >> opcion;
            if (opcion != 1) {
                cout << "Gracias por jugar. Hasta la proxima!" << endl;
                return 0;
            }
        }

    } while (!exito);

    cout << "Felicidades! Has cruzado todas las plataformas." << endl;

    return 0;
}