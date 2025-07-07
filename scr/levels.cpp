#include <iostream>
#include <vector>
#include <cctype>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "levels.h"
#include "gameplay.h"
#include <conio.h>
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
    int userChoice;
    int currentPlatform;
    bool isSuccess;
    int correctPath[5];

    srand(time(0));
    for (int i = 0; i < 5; i++) {
        correctPath[i] = rand() % 5 + 1;
    }

    cout << endl;
    cout << "===============================================" << endl;
    cout << "         Nivel 1: Cruza el puente." << endl;
    cout << "===============================================" << endl;
    cout << "Debes adivinar la combinacion correcta para cruzar." << endl;
    cout << "Un paso en falso y caeras al vacio." << endl;
    cout << "-----------------------------------------------" << endl;

    do {
        currentPlatform = 1;
        isSuccess = true;

        while (currentPlatform <= 5 && isSuccess) {
            cout << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "Plataforma " << currentPlatform << " de 5." << endl;
            cout << "Opciones disponibles: 1, 2, 3, 4, 5." << endl;
            cout << "Elige una opcion: ";

            while (!(cin >> userChoice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada invalida. Por favor, ingresa un numero entre 1 y 5: ";
            }

            if (userChoice == correctPath[currentPlatform - 1]) {
                cout << endl;
                cout << "**********************************************" << endl;
                cout << "Correcto. Avanzas a la siguiente plataforma." << endl;
                cout << "**********************************************" << endl;
                currentPlatform++;
            } else {
                cout << endl;
                cout << "**********************************************" << endl;
                cout << "Incorrecto. Has caido al vacio." << endl;
                cout << "**********************************************" << endl;
                isSuccess = false;
            }
        }

        if (currentPlatform > 5 && isSuccess) {
            cout << endl;
            cout << "**********************************************" << endl;
            cout << "Felicidades; has cruzado el sano y salvo." << endl;
            cout << "**********************************************" << endl;
        }

    } while (!isSuccess);

}

void level_02() {
    vector<vector<char>> maze = {
        {'#','#','#','#','#','#','#','#'},
        {'#','@',' ',' ','#',' ',' ','#'},
        {'#',' ','#',' ','#',' ','#','#'},
        {'#',' ','#',' ',' ',' ',' ','#'},
        {'#',' ','#','#','#','#',' ','#'},
        {'#',' ',' ',' ','#',' ',' ','#'},
        {'#','#','#',' ',' ',' ','S','#'},
        {'#','#','#','#','#','#','#','#'}
    };

    int playerX = 1, playerY = 1;

    auto showMaze = [&](const vector<vector<char>>& m) {
        for (const auto& row : m) {
            for (char cell : row)
                cout << cell << ' ';
            cout << '\n';
        }
    };

    auto movePlayer = [&](char direction) -> bool {
        int nextX = playerX, nextY = playerY;

        switch (direction) {
            case 'w': nextX--; break;
            case 's': nextX++; break;
            case 'a': nextY--; break;
            case 'd': nextY++; break;
            default:
                cout << "Movimiento invalido. Usa W, A, S o D." << endl;
                return false;
        }

        if (nextX < 0 || nextX >= maze.size() || nextY < 0 || nextY >= maze[0].size()) {
            cout << "No puedes salir del laberinto. Elige otra direccion." << endl;
            return false;
        }

        char destination = maze[nextX][nextY];

        if (destination == '#') {
            cout << "Una pared bloquea el camino. Intenta otra direccion." << endl;
            return false;
        }

        if (destination == 'S') {
            cout << endl;
            cout << "**********************************************" << endl;
            cout << "Felicidades; has escapado del laberinto con vida." << endl;
            cout << "**********************************************" << endl;
            return true;
        }

        maze[playerX][playerY] = ' ';
        playerX = nextX;
        playerY = nextY;
        maze[playerX][playerY] = '@';

        return false;
    };

    using namespace std::chrono;
    bool escaped = false;
    do {
        auto start = steady_clock::now();

        cout << "==============================================" << endl;
        cout << "           Nivel 2: Escape del laberinto." << endl;
        cout << "==============================================" << endl;
        cout << "Controla al explorador usando las teclas." << endl;
        cout << "W: arriba; A: izquierda; S: abajo; D: derecha." << endl;
        cout << "Tu objetivo es llegar a la salida marcada con S." << endl;
        cout << "Tienes 20 segundos para escapar del laberinto." << endl;

        escaped = false;
        while (!escaped) {
            auto now = steady_clock::now();
            int seconds = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
            if (seconds >= 20) {
                cout << endl;
                cout << "----------------------------------------------" << endl;
                cout << "Tiempo agotado. Debes intentarlo de nuevo." << endl;
                cout << "----------------------------------------------" << endl;
                break;
            }
            cout << endl;
            cout << "----------------- Mapa del laberinto -----------------" << endl;
            showMaze(maze);
            cout << "------------------------------------------------------" << endl;
            cout << "Tiempo transcurrido: " << seconds << " de 20 segundos." << endl;
            cout << "Ingresa tu movimiento (W, A, S o D): ";
            char key;
            cin >> key;

            escaped = movePlayer(tolower(key));
        }
        if (!escaped) {
            cout << endl;
            cout << "Reiniciando el laberinto. Intenta nuevamente." << endl;
            cout << "----------------------------------------------" << endl;
        }
    } while (!escaped);
}

void level_03() {
    using namespace std::chrono;
    srand(static_cast<unsigned int>(time(0)));
    const int totalPresses = 50;
    const int timeLimit = 15;

    bool completed = false;

    do {
        int counter = 0;

        char targetKey = 'a' + (rand() % 26);

        cout << endl;
        cout << "==============================================" << endl;
        cout << "           Nivel 3: Gira la palanca          " << endl;
        cout << "==============================================" << endl;
        cout << "Presiona la tecla '" << targetKey << "' " << totalPresses << " veces lo mas rapido posible." << endl;
        cout << "Tienes " << timeLimit << " segundos para completar el reto." << endl;
        cout << "Empieza a presionar." << endl;

        auto start = steady_clock::now();

        while (counter < totalPresses) {
            auto now = steady_clock::now();
            int elapsed = duration_cast<seconds>(now - start).count();
            if (elapsed >= timeLimit) {
                break;
            }
            if (_kbhit()) {
                char key = _getch();
                if (key == targetKey) {
                    counter++;
                    cout << "Progreso: " << counter << "/" << totalPresses << "\r";
                    cout.flush();
                } else {
                    cout << "Tecla incorrecta: '" << key << "'." << endl;
                }
            }
        }

        auto end = steady_clock::now();
        auto duration = duration_cast<seconds>(end - start).count();

        if (counter >= totalPresses && duration <= timeLimit) {
            cout << endl;
            cout << "**********************************************" << endl;
            cout << "Felicidades; completaste la fase en " << duration << " segundos." << endl;
            cout << "**********************************************" << endl;
            completed = true;
        } else {
            cout << endl;
            cout << "**********************************************" << endl;
            cout << "No lograste completar el reto en " << timeLimit << " segundos. Intenta de nuevo." << endl;
            cout << "**********************************************" << endl;
        }

    } while (!completed);
}
