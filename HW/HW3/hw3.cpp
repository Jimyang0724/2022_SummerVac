#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

template<typename T>
auto sum(const T& K) {
    auto k = K, s = 0;
    while(k--) s += k + 1;
    return s;
}

template<typename T>
auto fill(const T& K) {
    auto k = 1;
    vector<T> vec {0};
    while(k < K) {
        for(auto i = 0; i <= k; ++i) {
            if(i == 0 || i == k) vec.push_back(1);
            else {
                vec.push_back(vec[vec.size() - k] + vec[vec.size() - k - 1]);
            }
        }
        ++k;
    }

    auto count = 0, len = 0;
    for(const auto& i : vec) {
        cout << i << " ";
        if(count == len && count != K-1) {
            count = 0;
            len += 1;
            cout << endl;
        }
        else ++count;
    }    
    cout << endl;
}

auto question2() -> void {
    cout << "question2: " << endl;
    cout << "input integer K: ";
    auto K = 0;
    cin >> K;

    cout << "a. " << K << endl << endl;

    cout << "b. " << endl;
    for(auto k = K; k >= 0; --k) {
        auto count = k;
        while(count--) cout << "*";
        if(k != K) cout << "1";
        cout << endl;
    }
    cout << endl;

    cout << "c. " << endl;
    cout << sum(K) << endl << endl;

    cout << "d. " << endl;
    fill(K);
    cout << endl;

}

auto question3() -> void {
    cout << "question3: " << endl;
    cout << "input integer K: ";
    auto K = 0;
    cin >> K;

    cout << "a. " << K << endl << endl;

    cout << "b. " << endl;
    auto k = 0;
    while(++k < 10)
        cout << K << " x " << k << " = " << K * k << endl;
    cout << endl;

    cout << "c. " << endl;

}

auto toDec(int input, const int base) -> int {
    auto decNum = 0, lastDigit = input % 10, exp = 0;

    do {
        if(lastDigit >= base) return -1;
        decNum += lastDigit * pow(base, exp++);
        input /= 10;
        lastDigit = input % 10;
    } while(input != 0);
    return decNum;
}

auto toDesired(int input, const int base) -> int {
    auto desired_num = 0, count = 0;
    do {
        // desired_num *= 10;
        desired_num += (input % base) * pow(10, count++);
        input /= base;
    } while(input != 0);
    return desired_num;
}

auto question4(int argc, char* argv[]) -> void {
    if(argc != 4) {
        cout << "Usage: Must 3 argument!" << endl;
        return;
    }
    auto input_int = stoi(argv[1]), from_base = stoi(argv[2]), to_base = stoi(argv[3]);
    auto decNum = toDec(input_int, from_base);
    if(decNum == -1) {
        cout << "ERROR INPUT!" << endl;
        return;
    }
    auto desired_num = toDesired(decNum, to_base);

    cout << desired_num << endl;
}

int main(int argc, char** argv) {
    question2();
    question3();
    question4(argc, argv);
    return 0;
}