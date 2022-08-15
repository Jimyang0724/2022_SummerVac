#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include "engine.h"
#define TEST 0

using namespace std;

namespace engine {
    Engine::Engine() : _CC(0), _type(""), _weight(0) {
        #if TEST
        cout << "[STATUS] Default constructor. Type: " << this->_type << endl;
        #endif
    }
    Engine::Engine(int CC, string type, int weight) : _CC(CC), _type(type), _weight(weight) {
        #if TEST
        cout << "[STATUS] Non default constructor. Type: " << this->_type << endl;
        #endif
    }
    Engine::~Engine() {
        #if TEST
        cout << "[STATUS] Destructor. Type: " << this->_type << endl;
        #endif
        
    }

    Engine::Engine(const Engine& other) : _CC(other._CC), _type(other._type), _weight(other._weight) {
        #if TEST
        cout << "[STATUS] Copy constructor. Type: " << this->_type << endl;
        #endif
    }
    Engine::Engine(Engine&& other) noexcept : _CC(exchange(other._CC, 0)), _type(move(other._type)), _weight(exchange(other._weight, 0)) {
        #if TEST
        cout << "[STATUS] Move constructor. Type: " << this->_type << endl;
        #endif
    }

    Engine& Engine::operator=(const Engine& rVal) {
        #if TEST
        cout << "[STATUS] Copy assignment." << endl;
        #endif
        if (this != &rVal) {
            this -> _CC = rVal._CC;
            this -> _type = rVal._type;
            this -> _weight = rVal._weight;
        }
        return *this;
    }
    Engine& Engine::operator=(Engine&& rVal) {
        #if TEST
        cout << "[STATUS] Move assignment." << endl;
        #endif
        if (this != &rVal) {
            this -> _CC = exchange(rVal._CC, 0);
            this -> _type = move(rVal._type);
            this -> _weight = exchange(rVal._weight, 0);
        }
        return *this;
    }

    int Engine::getCC() const {
        return this -> _CC;
    }
}