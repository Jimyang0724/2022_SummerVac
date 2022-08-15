#pragma once
#include <iostream>
#include <string>
#include "engine.h"     
using namespace std;

namespace car {
    class Car {
        public:
            friend ostream& operator<<(ostream& os, Car);
            bool operator<(const Car&) const;
            bool operator>(const Car&) const;

            Car();   // Default constructor
            Car(engine::Engine& );  // Non default constructor
            ~Car();  // Destructor

            Car(const Car& ); // Copy constructor
            Car(Car&& ) noexcept;    // Move constructor

            Car& operator=(const Car& );   // Copy assignment
            Car& operator=(const Car&& );   // Move assignment
        
        private:
            engine::Engine _engine;
    };
}