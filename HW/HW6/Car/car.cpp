#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "engine.h"
#include "car.h"
#define TEST 0

using namespace std;

namespace car {
    Car::Car() : _engine(engine::Engine()) {
        #if TEST
        cout << "[STATUS] Car's default constructor." << endl;
        #endif
    }
    Car::Car(engine::Engine& e) : _engine(e) {
        #if TEST
        cout << "[STATUS] Car's non default constructor. Type: " << endl;
        #endif
    }
    Car::~Car() {
        #if TEST
        cout << "[STATUS] Car's destructor. Type: " << endl;
        #endif
    }

    Car::Car(const Car& other) : _engine(other._engine) {
        #if TEST
        cout << "[STATUS] Car's copy constructor. Type: " << endl;
        #endif
    }
    Car::Car(Car&& other) noexcept : _engine(move(other._engine)) {
        #if TEST
        cout << "[STATUS] Car's move constructor. Type: " << endl;
        #endif
    }

    Car& Car::operator=(const Car& rVal) {
        #if TEST
        cout << "[STATUS] Car's copy assignment." << endl;
        #endif
        if (this != &rVal) {
            this -> _engine = rVal._engine;
        }
        return *this;
    }
    Car& Car::operator=(const Car&& rVal) {
        #if TEST
        cout << "[STATUS] Car's move assignment." << endl;
        #endif
        if (this != &rVal) {
            this -> _engine = move(rVal._engine);
        }
        return *this;
    }

    // void showItem(void) {
        // char *tmp = &(this -> _type[0]);
        // cout << &tmp << endl;
        // cout << "[STATUS] Show item,\n\tCC: " << this -> _CC\
        //     << ", Type: " << this -> _type\
        //     << ", Weight: " << this -> _weight\
        //     << endl;
    // }

    ostream& operator<<(ostream& os, Car C) {
        if (C._engine.getCC() > 0) {
            os << C._engine.getCC() << " ";
        }
        else os << "Error: " << " ";
        return os;
    }

    bool Car::operator<(const Car& right) const {
        return (_engine.getCC() < right._engine.getCC());
    }

    bool Car::operator>(const Car& right) const {
        return (_engine.getCC() > right._engine.getCC());
    }
}

