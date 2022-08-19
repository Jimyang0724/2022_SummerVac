#include <iostream>
#include "trade_date.h"

using namespace std;

int main() {
    // auto temp = trade_date::TRADE_DATE_gen(1729, 100000);
    auto test_date = trade_date::TRADE_DATE_gen(1729, 100);
    // for (auto i : test_date) {
    //     cout << get<0>(i) << " " << get<1>(i) << " " << get<2>(i) << endl;
    // }
    // auto date = trade_date::_calc_date(425);
    // cout << get<0>(date) << " " << get<1>(date) << " " << get<2>(date) << endl;
    // cout << "Reverse begin: " << trade_date::_calc_back_to_days(date) << endl;
    // cout << endl;
    // trade_date::_calc_date(366);
}