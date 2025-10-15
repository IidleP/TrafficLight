#include <iostream>
#include "traficlight.h"
using namespace std;

int main() {
    Road road;
    setlocale(LC_ALL, "Russian");
    cout << "Начальное состояние: " << road << endl;


    for (int i = 0; i < 12; i++) {
        road.switch_light();
        cout << "Переключючение: " << i + 1 << ": " << road << endl;

        if (i % 3 == 2) cout << "---" << endl;
    }

    return 0;
}

//cd C:\Users\Илья\source\repos\TraficLight\TraficLightFINISH
// 
//rmdir /s /q build

//mkdir build
//cd build

//cmake ..

//cmake --build . --config Debug