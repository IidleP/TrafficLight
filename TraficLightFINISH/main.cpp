#include <iostream>
#include "traficlight.h"
using namespace std;
//cmake --build . --config Release

int main() {
    Road road;
    setlocale(LC_ALL, "Russian");
    cout << "��������� ���������: " << road << endl;


    for (int i = 0; i < 12; i++) {
        road.switch_light();
        cout << "��������������: " << i + 1 << ": " << road << endl;

        if (i % 3 == 2) cout << "---" << endl;
    }

    return 0;
}
