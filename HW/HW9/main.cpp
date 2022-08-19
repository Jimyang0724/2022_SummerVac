#include <iostream>
#include "trade_date.h"

using namespace std;

int main() {
    // auto temp = trade_date::TRADE_DATE_gen(1729, 100000);
    auto test_date = trade_date::TRADE_DATE_gen(1729, 100);
    // for (auto i : test_date) {
    //     cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
    // }
    // trade_date::_calc_date(365);
    // trade_date::_calc_date(366);
}