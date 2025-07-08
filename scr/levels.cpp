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
    cout << "          Level complete!\n";
    cout << "     Press ENTER for the next level...";
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
    cout << "         Level 1: Cross the bridge." << endl;
    cout << "===============================================" << endl;
    cout << "You stop at the edge of an ancient suspension bridge suspended over a bottomless abyss.\n";
    cout << "The wooden boards are marked with ancient symbols... only one combination of steps is safe.\n";
    cout << "If you choose wrong, the bridge will give way and you will fall into the void.\n";
    cout << "You must guess the correct combination to cross to the other side.\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do {
        currentPlatform = 1;
        isSuccess = true;

        while (currentPlatform <= 5 && isSuccess) {
            cout << endl;
            cout << "-----------------------------------------------" << endl;
            cout << "Platform " << currentPlatform << " of 5." << endl;
            cout << "Available options: 1, 2, 3, 4, 5." << endl;
            cout << "Choose an option: ";

            while (!(cin >> userChoice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry. Please enter a number between 1 and 5.: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            if (userChoice == correctPath[currentPlatform - 1]) {
                cout << endl;
                cout << "**********************************************" << endl;
                cout << "Correct. You advance to the next platform." << endl;
                cout << "**********************************************" << endl;
                currentPlatform++;
            } else {
                cout << endl;
                cout << "**********************************************" << endl;
                cout << "Wrong. You've fallen into the void." << endl;
                cout << "**********************************************" << endl;
                isSuccess = false;
            }
        }

        if (currentPlatform > 5 && isSuccess) {
            cout << endl;
            cout << "**********************************************" << endl;
            cout << "Congratulations; you've crossed the bridge safely." << endl;
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
                cout << "Invalid movement. Use W, A, S or D." << endl;
                return false;
        }

        if (nextX < 0 || nextX >= maze.size() || nextY < 0 || nextY >= maze[0].size()) {
            cout << "You can't get out of the maze. Choose another direction." << endl;
            return false;
        }

        char destination = maze[nextX][nextY];

        if (destination == '#') {
            cout << "A wall blocks the way. Try another direction.." << endl;
            return false;
        }

        if (destination == 'S') {
            cout << endl;
            cout << "**********************************************" << endl;
            cout << "Congratulations; you've escaped the maze alive." << endl;
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
        cout << "           Level 2: Escape the Maze" << endl;
        cout << "==============================================" << endl;
        cout << "Control the explorer using the keys." << endl;
        cout << "W: up; A: left; S: down; D: right." << endl;
        cout << "Your goal is to reach the exit marked S." << endl;
        cout << "You have 20 seconds to escape the maze." << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        escaped = false;
        while (!escaped) {
            auto now = steady_clock::now();
            int seconds = std::chrono::duration_cast<std::chrono::seconds>(now - start).count();
            if (seconds >= 20) {
                cout << endl;
                cout << "----------------------------------------------" << endl;
                cout << "Time up. You must try again." << endl;
                cout << "----------------------------------------------" << endl;
                break;
            }
            cout << endl;
            cout << "----------------- Map of the maze -----------------" << endl;
            showMaze(maze);
            cout << "------------------------------------------------------" << endl;
            cout << "Time elapsed: " << seconds << " of 20 seconds." << endl;
            cout << "Enter your movement (W, A, S o D): ";
            char key;
            cin >> key;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            escaped = movePlayer(tolower(key));
        }
        if (!escaped) {
            cout << endl;
            cout << "Resetting the maze. Please try again." << endl;
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
    cout << "        Level 3: Hall of Wisdom." << endl;
    cout << "==============================================" << endl;
    cout << "After escaping the dark labyrinth, you reach a secret room in the temple.\n";
    cout << "In the center is an altar with ancient riddles carved in stone...\n";
    cout << "Only by solving its riddles will you be able to continue your journey.\n";
    cin.ignore();

    auto riddleWithHint = [&](string titulo, string enunciado, vector<string> respuestas, string pista) -> bool {
        cout << "\n" << titulo << endl;
        cout << enunciado << "\n";
        cout << "Your answer: ";
        string answer; getline(cin, answer);
        answer = toLower(answer);
        for (const auto& r : respuestas) {
            if (answer.find(r) != string::npos) {
                cout << "Correct. The old mechanism is activated.\n";
                return true;
            }
        }
        cout << "Incorrect. Clue: " << pista << "\n";
        return false;
    };

    while (!riddleWithHint(
        "Puzzle 1: The Entrance of the Temple",
        "Guarded by the ancestors, this entrance never closes, day or night.\nWhat is that which is always open, but never closes?",
        {"door"},
        "You can enter and exit through it."
    )) {}

    while (!riddleWithHint(
        "Puzzle 2: The Mystic Torch",
        "It lives in every corner of the temple, giving life to the shadows without having body or form.\nThat lights up everything, but no one can touch?",
        {"light"},
        "Without her, everything would be dark."
    )) {}

    while (!riddleWithHint(
        "Puzzle 3: The Stone Guardian",
        "It has remained motionless for centuries, contemplating each traveler without saying a word.\nThat he is big, doesn't speak and always watches in the temples?",
        {"statue"},
        "It is made of stone or metal."
    )) {}

    while (!riddleWithHint(
        "Puzzle 4: The River of Eternity",
        "It flows without rest, it knows no end, and its voice is a constant murmur.\nThat never stops but never walks either?",
        {"water", "river"},
        "It is vital for life and is found in rivers and lakes."
    )) {}

    while (!riddleWithHint(
        "Puzzle 5: The Key to the Invisible",
        "Without it, seals can't be broken. You can't see it or hold it, but it opens closed doors.\nWhat is it?",
        {"word", "password"},
        "It's something you say or write to get in."
    )) {}

    while (!riddleWithHint(
        "Puzzle 6: The Traces of the Echo",
        "You leave it behind at every step, but without it you could never move forward.\nWhat grows the more you walk?",
        {"step", "footprint"},
        "They are signs that you leave while walking."
    )) {}

    while (!riddleWithHint(
        "Puzzle 7: The Flame of the Heavens",
        "It burns without burning, it shines in the firmament, it guides the wise and amazes travelers.\nWhat is lit without fire?",
        {"star", "sun"},
        "It shines in the sky during the day or night."
    )) {}

    while (!riddleWithHint(
        "Puzzle 8: The Infinite Wheel",
        "It spins endlessly, dragging the destiny of every being, and never stops.\nWhat moves without you being able to push it?",
        {"earth", "planet"},
        "It's where we all live."
    )) {}

    while (!riddleWithHint(
        "Puzzle 9: The Voice of the Mountains",
        "It answers when no one asks, he shouts what you just said, but he has no mouth or ears.\nWhat is it?",
        {"echo"},
        "It is heard in caves and mountains."
    )) {}

    while (!riddleWithHint(
        "Puzzle 10: The Guardian of the Centuries",
        "It moves forward without looking back, consumes everything in its path and never stops.\nWho reigns over every moment, but no one can see?",
        {"time", "clock"},
        "We measure it with watches and calendars."
    )) {}

    cout << "\nCongratulations.\nYou have solved all the puzzles and the temple reveals a new secret exit.";
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
    cout << "      Level 4: Wall of Sequences." << endl;
    cout << "==============================================" << endl;
    cout << "In front of you is an ancient wall with number sequences carved in stone.\n";
    cout << "You must observe each sequence and write the number that follows correctly.\n";
    cout << "Solve at least two sequences for the secret door to open.\n";
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
            cout << "\nSequence " << i + 1 << ": " << selected[i].text << "\n";
            cout << "Your answer: ";

            while (!(cin >> playerAnswer)) {
                cout << "Invalid entry. Please enter an integer: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            if (playerAnswer == selected[i].correctAnswer) {
                cout << "Correct. The wall shines slightly...\n";
                correctCount++;
            } else {
                cout << "Incorrect. The stone trembles slightly.\n";
            }
        }

        if (correctCount >= 2) {
            cout << "\nYou have solved the mystery of the Wall of Sequences.\n";
            cout << "A hidden hatch slowly opens...\n";

            cout << "\nSuddenly, the statue that has been watching you all this time starts to move...\n";
            cout << "\nIts stone cracks and reveals an ancient being: the Temple Guardian.";
            cout << "Its stone cracks and reveals an ancient being: the Temple Guardian.\n";

            nextLevel_Message();

            completed = true;
        } else {
            cout << "\nThe stones remain motionless. You failed to decipher the sacred pattern.\n";
            cout << "Try again.\n";
            nextLevel_Message();
        }
    }
}

void level_05() {
    srand(static_cast<unsigned>(time(0)));

    system("cls");
    cout << "==============================================" << endl;
    cout << "   Final Level: The Guardian of the Temple" << endl;
    cout << "==============================================" << endl;
    cout << "You've reached the final chamber. A giant statue awakens and challenges you.\n";
    cout << "You must survive the combat to get to the exit.\n";
    cin.ignore();

    bool won = false;

    while (!won) {
        int playerHP = 100;
        int guardianHP = 80;

        while (playerHP > 0 && guardianHP > 0) {
            cout << "\nYour health: " << playerHP << " | Guardian's health: " << guardianHP << endl;
            cout << "Choose your action:\n";
            cout << "1. Attack\n2. Defend\n3. Heal\n";
            cout << "Option: ";

            int choice;
            while (!(cin >> choice) || choice < 1 || choice > 3) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid entry. Elige 1, 2 or 3: ";
            }
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            int playerDamage = 0;
            int guardianDamage = rand() % 15 + 5; // Daño aleatorio entre 5 y 19

            switch (choice) {
                case 1:
                    playerDamage = rand() % 20 + 10; // Daño entre 10 y 29
                    guardianHP -= playerDamage;
                    cout << "You attacked the guardian and dealt " << playerDamage << " damage.\n";
                    break;
                case 2:
                    guardianDamage /= 2;
                    cout << "You defended yourself. The guardian's damage will be reduced.\n";
                    break;
                case 3: {
                    int heal = rand() % 15 + 5; // Curación entre 5 y 19
                    playerHP = min(100, playerHP + heal);
                    cout << "You are healed " << heal << " health points.\n";
                    break;
                }
            }

            if (guardianHP > 0) {
                playerHP -= guardianDamage;
                cout << "The guardian attacks you, dealing " << guardianDamage << " damage.\n";
            }
        }

        if (playerHP > 0) {
            cout << "\nYou have defeated the Temple Guardian.\n";
            cout << "The temple rumbles and a shaft of light appears before you.\n";

            if (playerHP >= 70) {
                cout << "\nHeroic Ending:\n";
                cout << "You left the temple with honor and glory. The ancient deities bless you.\n";
                cout << "Your name will be remembered for generations..\n";
            } else if (playerHP >= 30) {
                cout << "\nFair Ending:\n";
                cout << "You managed to escape from the temple with the sacred relic, although you paid a high price.\n";
                cout << "The scars of battle will remain with you.\n";
            } else {
                cout << "\nDark Ending:\n";
                cout << "You escaped... but something inside you changed forever.\n";
                cout << "The power of the temple and its darkness now burn within you.\n";
            }

            won = true;
        } else {
            cout << "\nYou've been defeated by the guardian. Try again...\n";
            cout << "Press ENTER to try again.";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
            system("cls");
        }
    }

    cout << "\nGame Over.\n";
    cout << "Press ENTER to exit.";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}
