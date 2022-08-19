#include <iostream>
#include <algorithm>
#include <tuple>
#include "trade_date.h"

using namespace std;

int main() {
    auto test_date = trade_date::TRADE_DATE_gen(1729, 100000);
    // auto test_date = trade_date::TRADE_DATE_gen(1729, 100);
    trade_date::intersection_finder(test_date);
}