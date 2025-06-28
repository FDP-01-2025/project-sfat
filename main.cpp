#include <iostream>
#include <fstream>
#include "scr/header.h"
using namespace std;

int main(){
    int opcion;

    cout << "Que nivel quiere jugar? ";
    cin >> opcion;

    if (opcion == 1) level_01();
    
}
