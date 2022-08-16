#pragma once
#include <iostream>
using namespace std;

namespace question_7a {
    template<class T, int N, int n, int (&Q)[N]>
    class Printer {
        public:
            static void print() {
                if (n == N)
                    return Printer<T, N, n-1, Q>::print();
                else {
                    cout << Q[n] << " ";
                    return Printer<T, N, n-1, Q>::print();
                }
            }
    };

    template<class T, int N, int (&Q)[N]>
    class Printer<T, N, 0, Q> {
        public:
            static void print() {
                cout << Q[0] << endl;
            }
    };
}