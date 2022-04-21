#include "Tests/tests.h"
#include <iostream>
#include "Menu/menu.h"

using namespace std;

int main() {
    cout << "Start!" << endl;
    testAll();
    menu();
    cout << "End!" << endl;
    return 0;
}
