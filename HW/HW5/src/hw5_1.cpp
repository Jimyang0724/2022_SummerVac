#include <iostream>
#include <vector>
#include "hw5_1.h"

using namespace std;

namespace Hw5_1 {
    template<typename T>
    void swap(T& vec, const int i, const int j) {
        auto temp = vec[i];
        vec[i] = vec[j];
        vec[j] = temp;
    }

    template<typename T>
    void bubbleSort(T& vec) {
        cout << "[STATUS] Bubble sort" << endl;
        for(auto i=0; i<vec.size()-1; i++)
            for(auto j=i; j<vec.size(); j++)
                if(vec[i] > vec[j]) swap(vec, i, j);
    }

    template<typename T>
    void insertionSort(T& vec) {
        cout << "[STATUS] Insertion sort" << endl;
        for(auto i=1; i<vec.size(); i++)
            for(auto j=0; j<i; j++)
                if(vec[j] > vec[i]) {
                    vec.insert(vec.begin()+j, vec[i]);
                    vec.erase(vec.begin()+i+1);
                }
    }

    template<typename T>
    void sort(T& vec, void (*func)(T&)) {
        func(vec);
    }


    void question1(void) {
        cout << "[STEP] Question 1" << endl;

        vector<int> vec{2, 3, 1, 0};
        cout << "[STATUS] Original vector" << endl;
        for(auto it : vec) {
            cout << it << " ";
        }
        cout << endl;

        sort(vec, insertionSort);
        for(auto it : vec) {
            cout << it << " ";
        }
        cout << endl;

        sort(vec, bubbleSort);
        for(auto it : vec) {
            cout << it << " ";
        }
        cout << endl;
    }
}