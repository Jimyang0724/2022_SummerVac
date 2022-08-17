#pragma once
#include <iostream>
#include <typeinfo>
#include <utility>
#include <vector>
#include <deque>
#include <set>
#include <list>
#include <random>
#include <chrono>

using namespace std;

namespace back_inserter {
    template <template <typename...> typename CONTer = vector, typename T = int>
    class Back_inserter {
        public:
            Back_inserter(CONTer<T>& c) : conter(c) {}

            auto insert_100k() {
                std::mt19937 gen(1729);
                auto s = conter.size();
                uniform_int_distribution<T> distr;

                chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
                while(s++ < 100000)
                    conter.insert(conter.end(), distr(gen));
                chrono::steady_clock::time_point t2 = chrono::steady_clock::now();

                cout<< "Time of insert_100k of " << typeid(conter).name() << ": "<< chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << "us" << endl;
            }

            auto change_to_5566() {
                chrono::steady_clock::time_point t1 = chrono::steady_clock::now();
                for_each(conter.begin(), conter.end(), [](T& temp){ temp = 5566; });
                chrono::steady_clock::time_point t2 = chrono::steady_clock::now();

                cout<< "Time of change_to_5566 of " << typeid(conter).name() << ": "<< chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << "us" << endl;
            }   

        private:
            CONTer<T>& conter;
    };
}