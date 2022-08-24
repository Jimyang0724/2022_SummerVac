#include <tuple>
#include <variant>
#include <iostream>

// Implement jhh::get which return a std::variant whose value is 
// N-th value of std::tuple.
namespace jhh {
    using var_t = std::variant<double, int, char, const char*>;
    template <typename Tuple>
    struct get<std::size_t id>;


}

auto printvarint = [] (const auto& x) {
    std::cout << x << std::endl;
};

int main() {
    std::tuple t{3.14, 42, 'a', "hello", 0.5};
    // print 3.14 42 a hello 0.5 
    for (auto i = 0; i < std::tuple_size_v<decltype(t)>; i++)
        std::visit([](auto x) { std::cout << x << " "; }, jhh::get<i>(t));
        // auto& item = jhh::get_item<i>(t);
        // std::cout << jhh::get_index(i) << " ";
}