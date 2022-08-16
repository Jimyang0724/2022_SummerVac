#pragma once
#include <iostream>
using namespace std;

namespace question_7b {
    template<class T, int N, int n, int (&Q)[N]>
    class Printer {
        public:
            static void print() {
                // if (n != ) {
                    cout << Q[N-n] << " ";
                    return Printer<T, N, n-1, Q>::print();
                // }
            }
    };

    template<class T, int N, int (&Q)[N]>
    class Printer<T, N, 0, Q> {
        public:
            static void print() {
                cout << endl;
            }
    };
}