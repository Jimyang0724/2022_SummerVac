#include <iostream>
#include <vector>
#include <random>
#include <fstream>
#include <algorithm>

using namespace std;

template<typename T>
auto printMatrix(const T& vec) {
    for(auto& it1 : vec) {
        for(auto& it2 : it1)
            cout << it2 << " ";
        cout << endl;
    }
    cout << endl;
}

template<typename T>
auto writeMatrix(const T& vec, const string filename) {
    fstream file;
    file.open(filename, ios::out);
    if(file) {
        cout << "writting!" << endl;
        for(auto& it1 : vec) {
            for(auto& it2 : it1)
                file << it2 << " ";
            file << endl;
        }
    }
    file.close();
}

template<typename T>
auto rotate(T& vec) -> void{
    auto copy_vec = vec;
    auto it1_count = vec.size() - 1;
    for(auto& it1 : vec) {
        auto it2_count = vec.size() - 1;
        for(auto& it2 : it1) {
            it2 = copy_vec[vec.size() - 1 - it2_count--][it1_count];
        }
        --it1_count;
    }
}

auto question1(void) -> void {
    random_device rd;   // non-deterministic generator
    mt19937 gen(rd());  // to seed mersenne twister.
                        // replace the call to rd() with a
                        // constant value to get repeatable
                        // results.

    auto K = 0;
    cout << "Question 1: " << endl;
    cout << "Input an integer: ";
    cin >> K;

    // Generate 2d vector
    vector<vector<int>> vec(K, vector<int>(K, 0));
    for(auto& it1 : vec)
        for(auto& it2 : it1)
            it2 = gen()%10;

    writeMatrix(vec, "A.txt");
    // printMatrix(vec);
    for(auto i=0; i<3; ++i) {
        rotate(vec);
    }
    // printMatrix(vec);

    writeMatrix(vec, "B.txt");
    
}


template<typename T>
auto dfs(const T& vec, const int ind, const int curSum, const int& tar, T& rec) {
    if(ind == vec.size()+1 || curSum > tar) return false;
    else if(curSum == tar) {
        rec.clear();
        return true;
    }
    // cout << ind << " " << curSum << endl;

    if(dfs(vec, ind+1, curSum+vec[ind], tar, rec)) {
        rec.insert(rec.begin(), vec[ind]);
        return true;
    }
    if(dfs(vec, ind+1, curSum, tar, rec)) {
        return true;
    }
    // for(const auto& it : rec) {
    //     cout << it << " ";
    // }
    // cout<<endl;
}

auto question3(void) -> void {
    auto size = 0;
    cout << "Question 3: " << endl;
    cout << "Input Size: ";
    cin >> size;

    vector<int> A;
    for(auto i=0; i<size; ++i) {
        int in;
        cout << "Input " << i+1 << ": ";
        cin >> in;
        A.push_back(in);
    }
    sort(A.begin(), A.end());

    auto K = 0;
    cout << "Input Larger Integer: ";
    cin >> K;

    dfs(A, 0, 0, K, A);

    // for(auto it : A) {
    //     cout << it << " ";
    // }
    // cout << endl;
}


int main(void) {
    // question1();
    question3();
    return 0;
}