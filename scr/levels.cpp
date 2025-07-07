#include <iostream>
#include <algorithm>
#include <vector>
#include <cctype>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <limits>
#include <conio.h>
#include <windows.h>

using namespace std;

void gameTitle(){
    cout << "  _____ ____   ____    _    ____  _____   _____ ____   ___  __  __   _____ _   _ _____   _____ _____ __  __ ____  _     _____ " << endl;
    cout << " | ____/ ___| / ___|  / \\  |  _ \\| ____| |  ___|  _ \\ / _ \\|  \\/  | |_   _| | | | ____| |_   _| ____|  \\/  |  _ \\| |   | ____|" << endl;
    cout << " |  _| \\___ \\| |     / _ \\ | |_) |  _|   | |_  | |_) | | | | |\\/| |   | | | |_| |  _|     | | |  _| | |\\/| | |_) | |   |  _|  " << endl;
    cout << " | |___ ___) | |___ / ___ \\|  __/| |___  |  _| |  _ <| |_| | |  | |   | | |  _  | |___    | | | |___| |  | |  __/| |___| |___ " << endl;
    cout << " |_____|____/ \\____/_/   \\_\\_|   |_____| |_|   |_| \\_\\\\___/|_|  |_|   |_| |_| |_|_____|   |_| |_____|_|  |_|_|   |_____|_____|" << endl;
}

void nextLevel_Message() {
    system("cls");
    cout << "\n==============================================\n";
    cout << "          ¡Nivel completado!\n";
    cout << "     Presiona ENTER para el siguiente nivel...";
    cout << "\n==============================================\n";
    cin.get();
    system("cls");
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

    cout << "===============================================" << endl;
    cout << "         Nivel 1: Cruza el puente." << endl;
    cout << "===============================================" << endl;
    cout << "Te detienes al borde de un antiguo puente colgante suspendido sobre un abismo sin fondo.\n";
    cout << "Las tablas de madera estan marcadas con simbolos antiguos... solo una combinacion de pasos es segura.\n";
    cout << "Si eliges mal, el puente cedera y caerás al vacio.\n";
    cout << "Debes adivinar la combinacion correcta para cruzar hasta el otro lado.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
            cout << "Felicidades; has cruzado el puente sano y salvo." << endl;
            cout << "**********************************************" << endl;
            nextLevel_Message();
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

        system("cls");
        cout << "==============================================" << endl;
        cout << "           Nivel 2: Escape del laberinto." << endl;
        cout << "==============================================" << endl;
        cout << "Controla al explorador usando las teclas." << endl;
        cout << "W: arriba; A: izquierda; S: abajo; D: derecha." << endl;
        cout << "Tu objetivo es llegar a la salida marcada con S." << endl;
        cout << "Tienes 20 segundos para escapar del laberinto." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

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
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            escaped = movePlayer(tolower(key));
        }
        if (!escaped) {
            cout << endl;
            cout << "Reiniciando el laberinto. Intenta nuevamente." << endl;
            cout << "----------------------------------------------" << endl;
        }
    } while (!escaped);
    nextLevel_Message();
}

void level_03() {
    auto toLower = [](string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        return s;
    };

    system("cls");
    cout << "==============================================" << endl;
    cout << "        Nivel 3: Sala de la Sabiduria." << endl;
    cout << "==============================================" << endl;
    cout << "Despues de escapar del oscuro laberinto, llegas a una sala secreta del templo.\n";
    cout << "En el centro hay un altar con antiguos acertijos grabados en piedra...\n";
    cout << "Solo resolviendo sus enigmas podras continuar tu viaje.\n";
    cin.ignore();

    auto riddleWithHint = [&](string titulo, string enunciado, vector<string> respuestas, string pista) -> bool {
        cout << "\n" << titulo << endl;
        cout << enunciado << "\n";
        cout << "Tu respuesta: ";
        string answer; getline(cin, answer);
        answer = toLower(answer);
        for (const auto& r : respuestas) {
            if (answer.find(r) != string::npos) {
                cout << "Correcto. El mecanismo antiguo se activa.\n";
                return true;
            }
        }
        cout << "Incorrecto. Pista: " << pista << "\n";
        return false;
    };

    while (!riddleWithHint(
        "Acertijo 1: La Entrada del Templo",
        "Guardada por los ancestros, esta entrada jamas se cierra, ni de dia ni de noche.\nQue es aquello que siempre esta abierto, pero jamas se cierra?",
        {"puerta"},
        "Puedes entrar y salir por ella."
    )) {}

    while (!riddleWithHint(
        "Acertijo 2: La Antorcha Mistica",
        "Habita en cada rincon del templo, da vida a las sombras sin tener cuerpo ni forma.\nQue ilumina todo, pero nadie puede tocar?",
        {"luz"},
        "Sin ella, todo estaria oscuro."
    )) {}

    while (!riddleWithHint(
        "Acertijo 3: El Guardian de Piedra",
        "Permanece inmovil desde hace siglos, contempla a cada viajero sin decir palabra.\nQue es grande, no habla y siempre vigila en los templos?",
        {"estatua"},
        "Esta hecho de piedra o metal."
    )) {}

    while (!riddleWithHint(
        "Acertijo 4: El Rio de la Eternidad",
        "Fluye sin descanso, no conoce el final, y su voz es un murmullo constante.\nQue nunca se detiene pero tampoco camina?",
        {"agua", "rio"},
        "Es vital para la vida y esta en rios y lagos."
    )) {}

    while (!riddleWithHint(
        "Acertijo 5: La Llave de lo Invisible",
        "Sin ella, los sellos no se rompen. No se puede ver ni sostener, pero abre puertas cerradas.\nQue es?",
        {"palabra", "contrasena"},
        "Es algo que dices o escribes para entrar."
    )) {}

    while (!riddleWithHint(
        "Acertijo 6: Las Huellas del Eco",
        "A cada paso la dejas atras, pero sin ella jamas podrias avanzar.\nQue crece cuanto mas caminas?",
        {"paso", "huella"},
        "Son senales que dejas caminando."
    )) {}

    while (!riddleWithHint(
        "Acertijo 7: La Llama de los Cielos",
        "Arde sin quemar, resplandece en el firmamento, guia a los sabios y asombra a los viajeros.\nQue esta encendido sin fuego?",
        {"estrella", "sol"},
        "Brilla en el cielo durante el dia o la noche."
    )) {}

    while (!riddleWithHint(
        "Acertijo 8: La Rueda Infinita",
        "Gira sin cesar, arrastra el destino de todo ser, y jamas se detiene.\nQue se mueve sin que puedas empujarlo?",
        {"tierra", "planeta"},
        "Es donde vivimos todos."
    )) {}

    while (!riddleWithHint(
        "Acertijo 9: La Voz de las Montanas",
        "Responde cuando nadie pregunta, grita lo que tu acabas de decir, pero no tiene boca ni oidos.\nQue es?",
        {"eco"},
        "Se escucha en cavernas y montanas."
    )) {}

    while (!riddleWithHint(
        "Acertijo 10: El Guardian de los Siglos",
        "Avanza sin mirar atras, consume todo a su paso y nunca se detiene.\nQue reina sobre cada instante, pero nadie puede ver?",
        {"tiempo", "reloj"},
        "Lo medimos con relojes y calendarios."
    )) {}

    cout << "\nFelicidades. Has resuelto todos los acertijos y el templo revela una nueva salida secreta.\n";
    nextLevel_Message();
}

struct Sequence {
    string text;
    int correctAnswer;
};

void level_04() {
    srand(static_cast<unsigned>(time(0)));

    system("cls");
    cout << "==============================================" << endl;
    cout << "      Nivel 4: Muro de las Secuencias." << endl;
    cout << "==============================================" << endl;
    cout << "Delante de ti hay un muro antiguo con secuencias numericas talladas en piedra.\n";
    cout << "Debes observar cada secuencia y escribir el numero que sigue correctamente.\n";
    cout << "Resuelve al menos dos secuencias para que la puerta secreta se abra.\n";
    cin.ignore();

    vector<Sequence> easy = {
        {"1, 2, 3, 4, ?", 5},
        {"5, 10, 15, 20, ?", 25},
        {"10, 9, 8, 7, ?", 6}
    };

    vector<Sequence> medium = {
        {"2, 4, 8, 16, ?", 32},
        {"1, 4, 9, 16, ?", 25},
        {"1, 1, 2, 3, 5, ?", 8}
    };

    vector<Sequence> hard = {
        {"100, 90, 81, 73, ?", 66},
        {"1, 3, 6, 10, 15, ?", 21},
        {"1, 2, 6, 24, ?", 120}
    };

    bool completed = false;

    while (!completed) {
        int playerAnswer;
        int correctCount = 0;

        Sequence seq1 = easy[rand() % easy.size()];
        Sequence seq2 = medium[rand() % medium.size()];
        Sequence seq3 = hard[rand() % hard.size()];

        vector<Sequence> selected = {seq1, seq2, seq3};

        for (int i = 0; i < 3; ++i) {
            cout << "\nSecuencia " << i + 1 << ": " << selected[i].text << "\n";
            cout << "Tu respuesta: ";

            while (!(cin >> playerAnswer)) {
                cout << "Entrada invalida. Por favor ingresa un numero entero: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (playerAnswer == selected[i].correctAnswer) {
                cout << "Correcto. La pared brilla levemente...\n";
                correctCount++;
            } else {
                cout << "Incorrecto. La piedra tiembla levemente.\n";
            }
        }

        if (correctCount >= 2) {
            cout << "\nHas resuelto el misterio del Muro de las Secuencias.\n";
            cout << "Una compuerta oculta se abre lentamente...\n";

            cout << "\nDe pronto, la estatua que te observaba todo este tiempo empieza a moverse...\n";
            cout << "Su piedra se agrieta y revela un ser ancestral: el Guardian del Templo.\n";
            cout << "No basta con resolver acertijos. Ahora debes enfrentarlo...\n";

            nextLevel_Message();

            completed = true;
        } else {
            cout << "\nLas piedras permanecen inmoviles. No lograste descifrar el patron sagrado.\n";
            cout << "Intentalo de nuevo.\n";
            nextLevel_Message();
        }
    }
}

void level_05() {
    srand(static_cast<unsigned>(time(0)));

    system("cls");
    cout << "==============================================" << endl;
    cout << "   Nivel Final: El Guardian del Templo" << endl;
    cout << "==============================================" << endl;
    cout << "Has llegado a la camara final. Una estatua gigante despierta y te desafia.\n";
    cout << "Debes sobrevivir al combate para obtener la salida.\n";
    cin.ignore();

    bool won = false;

    while (!won) {
        int playerHP = 100;
        int guardianHP = 80;

        while (playerHP > 0 && guardianHP > 0) {
            cout << "\nTu vida: " << playerHP << " | Vida del Guardian: " << guardianHP << endl;
            cout << "Elige tu accion:\n";
            cout << "1. Atacar\n2. Defender\n3. Curarte\n";
            cout << "Opcion: ";

            int choice;
            while (!(cin >> choice) || choice < 1 || choice > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada invalida. Elige 1, 2 o 3: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int playerDamage = 0;
            int guardianDamage = rand() % 15 + 5; // Daño aleatorio entre 5 y 19

            switch (choice) {
                case 1:
                    playerDamage = rand() % 20 + 10; // Daño entre 10 y 29
                    guardianHP -= playerDamage;
                    cout << "Atacaste al guardian e hiciste " << playerDamage << " de daño.\n";
                    break;
                case 2:
                    guardianDamage /= 2;
                    cout << "Te defendiste. El daño del guardian sera reducido.\n";
                    break;
                case 3: {
                    int heal = rand() % 15 + 5; // Curación entre 5 y 19
                    playerHP = min(100, playerHP + heal);
                    cout << "Te curaste " << heal << " puntos de vida.\n";
                    break;
                }
            }

            if (guardianHP > 0) {
                playerHP -= guardianDamage;
                cout << "El guardian te ataca e inflige " << guardianDamage << " de daño.\n";
            }
        }

        if (playerHP > 0) {
            cout << "\nHas derrotado al Guardian del Templo.\n";
            cout << "El templo retumba y una salida de luz aparece ante ti.\n";

            if (playerHP >= 70) {
                cout << "\nFinal Heroico:\n";
                cout << "Saliste del templo con honor y gloria. Las antiguas deidades te bendicen.\n";
                cout << "Tu nombre sera recordado por generaciones.\n";
            } else if (playerHP >= 30) {
                cout << "\nFinal Justo:\n";
                cout << "Lograste escapar del templo con la reliquia sagrada, aunque pagaste un alto precio.\n";
                cout << "Las cicatrices de la batalla quedaran contigo.\n";
            } else {
                cout << "\nFinal Oscuro:\n";
                cout << "Escapaste... pero algo dentro de ti cambio para siempre.\n";
                cout << "El poder del templo y su oscuridad ahora arden en tu interior.\n";
            }

            won = true;
        } else {
            cout << "\nHas sido vencido por el guardian. Intentalo nuevamente...\n";
            cout << "Presiona ENTER para volver a intentar.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("cls");
        }
    }

    cout << "\nFin del juego.\n";
    cout << "Presiona ENTER para salir.";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
