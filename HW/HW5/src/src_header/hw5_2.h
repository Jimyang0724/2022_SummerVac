#pragma once
#include <string>

namespace Hw5_2 {
    class Engine {
        public:
            Engine();   // Default constructor
            Engine(int, std::string, int);  // Non default constructor
            ~Engine();  // Destructor

            Engine(const Engine& ); // Copy constructor
            Engine(Engine&& ) noexcept;    // Move constructor

            Engine& operator=(const Engine& );   // Copy assignment
            Engine& operator=(const Engine&& );   // Move assignment
        private:
            int _CC, _weight;
            std::string _type;
    };

    void question2(void);
}