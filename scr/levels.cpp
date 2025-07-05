#include <iostream>#include <iostream>
#include <string>
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()
#include "levels.h"
#include "gameplay.h"
using namespace std;

void gameTitle(){

    cout << "  _____ ____   ____    _    ____  _____   _____ ____   ___  __  __   _____ _   _ _____   _____ _____ __  __ ____  _     _____ \n"
     << " | ____/ ___| / ___|  / \\  |  _ \\| ____| |  ___|  _ \\ / _ \\|  \\/  | |_   _| | | | ____| |_   _| ____|  \\/  |  _ \\| |   | ____|\n"
     << " |  _| \\___ \\| |     / _ \\ | |_) |  _|   | |_  | |_) | | | | |\\/| |   | | | |_| |  _|     | | |  _| | |\\/| | |_) | |   |  _|  \n"
     << " | |___ ___) | |___ / ___ \\|  __/| |___  |  _| |  _ <| |_| | |  | |   | | |  _  | |___    | | | |___| |  | |  __/| |___| |___ \n"
     << " |_____|____/ \\____/_/   \\_\\_|   |_____| |_|   |_| \\_\\\\___/|_|  |_|   |_| |_| |_|_____|   |_| |_____|_|  |_|_|   |_____|_____|\n";

}

void nextLevel_Message(){

    cout << endl;
    cout << "==============================================" << endl;
    cout << "         Avanzando al siguiente nivel...   " << endl;
    cout << "==============================================" << endl;
}

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

    cout << "\n===============================================" << endl;
    cout << "         MINIJUEGO #1: Cruza el puente " << endl;
    cout << "===============================================" << endl;
    cout << "Debes adivinar la combinacion correcta para cruzar." << endl;
    cout << "Un paso en falso y caeras al vacio!" << endl;
    cout << "------------------------------------------" << endl;

    do {
        plataform = 1;
        success = true;

        while (plataform <= 5 && success) {
            cout << "\n------------------------------------------" << endl;
            cout << "Plataforma " << plataform << " de 5" << endl;
            cout << "Opciones disponibles: [1] [2] [3] [4] [5]" << endl;
            cout << "Elige una opcion: ";
            cin >> decision;

            if (decision == right_Path[plataform - 1]) {
                cout << "¡Correcto! Cruzaste el puente sano y salvo." << endl;
                plataform++;
            } else {
                cout << "¡Incorrecto! Has caído al vacio..." << endl;
                success = false;
            }
        }

    } while (!success);

}

