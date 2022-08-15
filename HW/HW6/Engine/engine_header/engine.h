#pragma once
#include <string>

namespace engine {
    class Engine {
        public:
            Engine();   // Default constructor
            Engine(int, std::string, int);  // Non default constructor
            ~Engine();  // Destructor

            Engine(const Engine& ); // Copy constructor
            Engine(Engine&& ) noexcept;    // Move constructor

            Engine& operator=(const Engine& );   // Copy assignment
            Engine& operator=(Engine&& );   // Move assignment

            int getCC() const;
        private:
            int _CC, _weight;
            std::string _type;
    };
}