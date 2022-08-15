#include <iostream>
#include <vector>
#include "car.h"
#include "engine.h"

#define SIZE 5

using namespace std;


int main() {
    vector<car::Car> vec;
    for (int i = 1; i <=5; i++) {
        engine::Engine e(i*1000, "test", i*10000);
        car::Car c(e);
        vec.push_back(c);
    }

    for (auto c : vec) {
        cout << c;
    }
    cout << endl;

    sort(vec.begin(), vec.end(), less<car::Car>());

    for (auto c : vec) {
        cout << c;
    }
    cout << endl;

}