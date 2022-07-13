#include <iostream>
#include <vector>

using namespace std;

template<typename T>
auto swap(T& vec, const int i, const int j) -> void {
    auto temp = vec[i];
    vec[i] = vec[j];
    vec[j] = temp;
}

template<typename T>
auto bubbleSort(T& vec) -> void {
    cout << "Bubble Sort" << endl;
    for(auto i=0; i<vec.size()-1; i++)
        for(auto j=i; j<vec.size(); j++)
            if(vec[i] > vec[j]) swap(vec, i, j);
}

template<typename T>
auto insertionSort(T& vec) -> void {
    cout << "Insertion Sort" << endl;
    for(auto i=1; i<vec.size(); i++)
        for(auto j=0; j<i; j++)
            if(vec[j] > vec[i]) {
                vec.insert(vec.begin()+j, vec[i]);
                vec.erase(vec.begin()+i+1);
            }
}

template<typename T>
auto sort(T& vec, void (*func)(T&)) -> void {
    func(vec);
}

auto question1(void) -> void {
    vector<int> vec{2, 3, 1, 0};
    for(auto it : vec) {
        cout << it << " ";
    }
    cout << endl;
    sort(vec, insertionSort);
    for(auto it : vec) {
        cout << it << " ";
    }
    cout << endl;
}

int main() {
    question1();
    return 0;
}