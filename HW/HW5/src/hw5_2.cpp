#include <iostream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

namespace Hw5_2 {
    class Engine {
        public:
            Engine() : _CC(0), _type(""), _weight(0) {
                cout << "[STATUS] Default constructor. Type: " << this->_type << endl;
            }
            Engine(int CC, string type, int weight) : _CC(CC), _type(type), _weight(weight) {
                cout << "[STATUS] Non default constructor. Type: " << this->_type << endl;
            }
            ~Engine() {
                cout << "[STATUS] Destructor. Type: " << this->_type << endl;
            }

            Engine(const Engine& other) : _CC(other._CC), _type(other._type), _weight(other._weight) {
                cout << "[STATUS] Copy constructor. Type: " << this->_type << endl;
            }
            Engine(Engine&& other) noexcept : _CC(exchange(other._CC, 0)), _type(move(other._type)), _weight(exchange(other._weight, 0)) {
                cout << "[STATUS] Move constructor. Type: " << this->_type << endl;
            }

            Engine& operator=(Engine& rVal) {
                cout << "[STATUS] Copy assignment." << endl;
                if (this != &rVal) {
                    this -> _CC = rVal._CC;
                    this -> _type = rVal._type;
                    this -> _weight = rVal._weight;
                }
                return *this;
            }
            Engine& operator=(Engine&& rVal) {
                cout << "[STATUS] Move assignment." << endl;
                if (this != &rVal) {
                    this -> _CC = exchange(rVal._CC, 0);
                    this -> _type = move(rVal._type);
                    this -> _weight = exchange(rVal._weight, 0);
                }
                return *this;
            }

            void showItem(void) {
                // char *tmp = &(this -> _type[0]);
                // cout << &tmp << endl;
                cout << "[STATUS] Show item,\n\tCC: " << this -> _CC\
                    << ", Type: " << this -> _type\
                    << ", Weight: " << this -> _weight\
                    << endl;
            }
        private:
            int _CC, _weight;
            string _type;
    };

    void question2(void) {
        cout << "[STEP] Question 2" << endl;
        Engine engineDefault, engineNonDefault(2, "type_0", 2), engineCopy = engineNonDefault;

        engineNonDefault.showItem();
        Engine engineMove = move(engineNonDefault);
        engineNonDefault.showItem();
        engineMove.showItem();

        engineNonDefault = engineMove;
        engineNonDefault.showItem();
        engineMove.showItem();
        engineMove = move(engineNonDefault);
        engineNonDefault.showItem();
        engineMove.showItem();
        // Engine* enginePtr = new Engine();
        // delete enginePtr;
    }
}