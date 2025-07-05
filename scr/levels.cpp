#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <cstdlib>   // Para rand() y srand()
#include <ctime>     // Para time()
#include <chrono>
#include "levels.h"
#include "gameplay.h"
using namespace std;

void gameTitle(){
    cout << "  _____ ____   ____    _    ____  _____   _____ ____   ___  __  __   _____ _   _ _____   _____ _____ __  __ ____  _     _____ " << endl;
    cout << " | ____/ ___| / ___|  / \\  |  _ \\| ____| |  ___|  _ \\ / _ \\|  \\/  | |_   _| | | | ____| |_   _| ____|  \\/  |  _ \\| |   | ____|" << endl;
    cout << " |  _| \\___ \\| |     / _ \\ | |_) |  _|   | |_  | |_) | | | | |\\/| |   | | | |_| |  _|     | | |  _| | |\\/| | |_) | |   |  _|  " << endl;
    cout << " | |___ ___) | |___ / ___ \\|  __/| |___  |  _| |  _ <| |_| | |  | |   | | |  _  | |___    | | | |___| |  | |  __/| |___| |___ " << endl;
    cout << " |_____|____/ \\____/_/   \\_\\_|   |_____| |_|   |_| \\_\\\\___/|_|  |_|   |_| |_| |_|_____|   |_| |_____|_|  |_|_|   |_____|_____|" << endl;
}

void nextLevel_Message(){
    cout << "Avanzando al siguiente nivel..." << endl;
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

    cout << endl;
    cout << "===============================================" << endl;
    cout << "         Nivel 1: Cruza el puente." << endl;
    cout << "===============================================" << endl;
    cout << "Debes adivinar la combinacion correcta para cruzar." << endl;
    cout << "Un paso en falso y caeras al vacio." << endl;
    cout << "-----------------------------------------------" << endl;

    do {
        plataform = 1;
        success = true;

        while (plataform <= 5 && success) {
            cout << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "Plataforma " << plataform << " de 5." << endl;
            cout << "Opciones disponibles: 1, 2, 3, 4, 5." << endl;
            cout << "Elige una opcion: ";
            cin >> decision;

            if (decision == right_Path[plataform - 1]) {
                cout << endl;
                cout << "**********************************************" << endl;
                cout << "Correcto. Cruzaste el puente sano y salvo." << endl;
                cout << "**********************************************" << endl;
                plataform++;
            } else {
                cout << endl;
                cout << "**********************************************" << endl;
                cout << "Incorrecto. Has caido al vacio." << endl;
                cout << "**********************************************" << endl;
                success = false;
            }
        }

    } while (!success);

}

void level_02() {
    // Mapa del laberinto (8x8)
    vector<vector<char>> laberinto = {
        {'#','#','#','#','#','#','#','#'},
        {'#','@',' ',' ','#',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#','#'},
        {'#',' ','#',' ',' ',' ',' ','#'},
        {'#',' ','#','#','#','#',' ','#'},
        {'#',' ',' ',' ','#',' ',' ','#'},
        {'#','#','#',' ',' ',' ','S','#'},
        {'#','#','#','#','#','#','#','#'}
    };

    int jugadorX = 1, jugadorY = 1;

    auto mostrarLaberinto = [&](const vector<vector<char>>& lab) {
        for (const auto& fila : lab) {
            for (char celda : fila)
                cout << celda << ' ';
            cout << '\n';
        }
    };

    auto moverJugador = [&](char direccion) -> bool {
        int nuevaX = jugadorX, nuevaY = jugadorY;

        switch (direccion) {
            case 'w': nuevaX--; break;
            case 's': nuevaX++; break;
            case 'a': nuevaY--; break;
            case 'd': nuevaY++; break;
            default:
                cout << "Movimiento invalido. Usa W, A, S o D." << endl;
                return false;
        }

        if (nuevaX < 0 || nuevaX >= laberinto.size() || nuevaY < 0 || nuevaY >= laberinto[0].size()) {
            cout << "No puedes salir del laberinto. Elige otra direccion." << endl;
            return false;
        }

        char destino = laberinto[nuevaX][nuevaY];

        if (destino == '#') {
            cout << "Una pared bloquea el camino. Intenta otra direccion." << endl;
            return false;
        }

        if (destino == 'S') {
            cout << endl;
            cout << "**********************************************" << endl;
            cout << "Felicidades; has escapado del laberinto con vida." << endl;
            cout << "**********************************************" << endl;
            return true;
        }

        laberinto[jugadorX][jugadorY] = ' ';
        jugadorX = nuevaX;
        jugadorY = nuevaY;
        laberinto[jugadorX][jugadorY] = '@';

        return false;
    };

    using namespace std::chrono;
    bool escapaste = false;
    do {
        auto inicio = steady_clock::now();

    cout << "==============================================" << endl;
    cout << "           Nivel 2: Escape del laberinto." << endl;
    cout << "==============================================" << endl;
    cout << "Controla al explorador usando las teclas." << endl;
    cout << "W: arriba; A: izquierda; S: abajo; D: derecha." << endl;
    cout << "Tu objetivo es llegar a la salida marcada con S." << endl;
    cout << "Tienes 20 segundos para escapar del laberinto." << endl;

        escapaste = false;
        while (!escapaste) {
            auto ahora = steady_clock::now();
            int segundos = duration_cast<seconds>(ahora - inicio).count();
            if (segundos >= 20) {
                cout << endl;
                cout << "----------------------------------------------" << endl;
                cout << "Tiempo agotado. Debes intentarlo de nuevo." << endl;
                cout << "----------------------------------------------" << endl;
                break;
            }
            cout << endl;
            cout << "----------------- Mapa del laberinto -----------------" << endl;
            mostrarLaberinto(laberinto);
            cout << "------------------------------------------------------" << endl;
            cout << "Tiempo transcurrido: " << segundos << " de 20 segundos." << endl;
            cout << "Ingresa tu movimiento (W, A, S o D): ";
            char tecla;
            cin >> tecla;

            escapaste = moverJugador(tolower(tecla));
        }
        if (!escapaste) {
            cout << endl;
            cout << "Reiniciando el laberinto. Intenta nuevamente." << endl;
            cout << "----------------------------------------------" << endl;
        }
    } while (!escapaste);
}

