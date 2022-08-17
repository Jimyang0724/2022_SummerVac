#pragma once
#include <iostream>
#include <tuple>

using namespace std;

namespace tuple_printer {
    template<typename Tuple, size_t ...Is>
    auto _pop_front(Tuple& t, index_sequence<Is...>) {
        return make_tuple(get<1 + Is>(t)...);
    }

    template<typename T>
    auto pop_front(T& t) {
        return _pop_front(t, make_index_sequence<tuple_size<T>::value -1 >());
    }

    template<typename T>
    auto printer(T t) -> void {
        cout << endl;
    }

    template<typename T, typename... Ts>
    auto printer(tuple<T, Ts...> t) -> void {
        cout << get<0>(t)<< " ";
        printer(pop_front(t));
    }
}