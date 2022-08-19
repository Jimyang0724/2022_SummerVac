#pragma once
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

namespace trade_date {
    class TRADE_DATE {
        public:
            TRADE_DATE(int, int);
        private:
            const int ID, duration;   // duration: the number of day in this peroid.
            const tuple<int, int, int> begin_date, end_date;
            static int ID_counter;

    };

    template<typename >

    auto _calc_month(int) -> tuple<int, int>;
    auto _calc_date(int) -> tuple<int, int, int>;
    auto _calc_back_to_days(tuple<int, int, int>) -> int;
    auto TRADE_DATE_gen(long, int) -> vector<TRADE_DATE>;
}