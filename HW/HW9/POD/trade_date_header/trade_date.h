#pragma once
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

namespace trade_date {
    class TRADE_DATE {
        public:
            TRADE_DATE(int, int);
            auto get_raw_begin_date() const;
            auto get_begin_date() const;
            auto get_raw_end_date() const;
            auto get_end_date() const;
            auto get_ID() const;

            auto operator<(const TRADE_DATE&) const -> bool;
            auto operator<(const int&) const -> bool;
            auto operator=(const TRADE_DATE&) -> TRADE_DATE&;
            friend auto operator<(const int&, const TRADE_DATE&) -> bool;
            friend auto operator<< (ostream&, const TRADE_DATE&) -> ostream&;

        private:
            int ID, duration;   // duration: the number of day in this peroid.
            tuple<int, int, int> begin_date, end_date;
            static int ID_counter;

    };

    template<typename >

    auto _calc_month(int) -> tuple<int, int>;
    auto _calc_date(int) -> tuple<int, int, int>;
    auto _calc_back_to_days(const tuple<int, int, int>) -> int;
    auto TRADE_DATE_gen(long, int) -> vector<TRADE_DATE>;
    auto intersection_finder(vector<TRADE_DATE>) -> void;
}