#include <iostream>
#include "hw5_1.h"
#include "hw5_2.h"

using namespace std;

void question5_1(void) {
    Hw5_1::question1();
}

void question5_2(void) {
    Hw5_2::question2();
}

int main() {
    question5_1();
    cout << "\n==========" << endl;
    question5_2();
    cout << endl;
    return 0;
}
