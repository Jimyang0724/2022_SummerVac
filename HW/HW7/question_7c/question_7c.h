#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

namespace question_7c {
    template<typename V, typename T>
    auto Equal(V vec, T t) -> bool {
        auto it = find(vec.begin(), vec.end(), t);
        if (it == vec.end()) {
            return false;
        }
        else return true;
    }

    template<typename V, typename T, typename... Ts>
    auto Equal(V vec, T t, Ts... ts) -> bool {
        auto it = find(vec.begin(), vec.end(), t);
        if (it == vec.end()) {
            vec.push_back(t);
            return Equal(vec, ts...);
        }
        else return true;
        
    }

    template<typename T, typename... Ts>
    auto _Equal(T t, Ts... ts) -> bool {
        vector<T> vec;
        return Equal(vec, t, ts...);
    }
}