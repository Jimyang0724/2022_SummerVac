#include <iostream>
#include <vector>
#include <tuple>
#include <random>
#include <algorithm>
#include "trade_date.h"

using namespace std;

#define MAX_DATE_DURATION 10
#define MIN_DATE_DURATION 1
#define MAX_DATE_DAY (365*100+24)

#define DEBUG false

namespace trade_date {
    int TRADE_DATE::ID_counter = 1;
    TRADE_DATE::TRADE_DATE(int _begin_day, int _end_day): \
                            ID(ID_counter++), \
                            duration(_end_day - _begin_day), \
                            begin_date(_calc_date(_begin_day)), \
                            end_date(_calc_date(_end_day)) {
        #if DEBUG
        cout << ID << ": generate success" << endl;
        cout << "Input begin: " << _begin_day << endl;
        cout << get<0>(begin_date) << " " << get<1>(begin_date) << " " << get<2>(begin_date) << endl;
        cout << "Reverse begin: " << _calc_back_to_days(begin_date) << endl;
        cout << endl;

        cout << "Input end: " << _end_day << endl;
        cout << get<0>(end_date) << " " << get<1>(end_date) << " " << get<2>(end_date) << endl;
        cout << "Reverse end: " << _calc_back_to_days(end_date) << endl;
        cout << endl << endl;
        #endif
    }

    auto TRADE_DATE::get_raw_begin_date() const {
        return _calc_back_to_days(begin_date);
    }

    auto TRADE_DATE::get_begin_date() const {
        return begin_date;
    }

    auto TRADE_DATE::get_raw_end_date() const {
        return _calc_back_to_days(end_date);
    }

    auto TRADE_DATE::get_end_date() const {
        return end_date;
    }

    auto TRADE_DATE::get_ID() const {
        return ID;
    }

    auto TRADE_DATE::operator<(const TRADE_DATE& rVal) const -> bool {
        return get_raw_begin_date() < rVal.get_raw_begin_date();
    }

    auto TRADE_DATE::operator<(const int& rVal) const -> bool {
        return get_raw_begin_date() < rVal;
    }

    auto TRADE_DATE::operator=(const TRADE_DATE& rVal) -> TRADE_DATE& {
        if (this != &rVal) {
            ID = rVal.ID;
            duration = rVal.duration;
            begin_date = rVal.begin_date;
            end_date = rVal.end_date;
        }
        return *this;
    }

    auto operator<(const int& lVal, const TRADE_DATE& rVal) -> bool {
        return lVal < rVal.get_raw_begin_date();
    }

    auto operator<<(ostream& os, const TRADE_DATE& tDate)  -> ostream& {
        auto b_date = tDate.get_begin_date(), e_date = tDate.get_end_date();
        return os << get<0>(b_date)<< " " << get<1>(b_date) << " " << get<2>(b_date);
    }

    auto _calc_back_to_days(const tuple<int, int, int> date) -> int {
        // calc days by year (sp case is 1900)
        auto num_of_years = get<0>(date) - 1900;
        auto num_days = \
            (num_of_years == 0) ? 0 : (num_of_years * 365 + num_of_years/4);
        
        //calc days by month (sp case is 1900)
        vector<tuple<int, int>> month{{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
        if (num_of_years != 0 && num_of_years % 4 == 0) month.at(1) = {2, 29};

        auto temp_days = 0;
        for (auto mm : month) {
            if (get<0>(mm) == get<1>(date)) break;
            temp_days += get<1>(mm);
            num_days += get<1>(mm);
        }

        // calc days by days
        num_days += get<2>(date);
        return num_days;
    }

    auto _calc_month(int days, bool leap) -> tuple<int, int> {
        vector<tuple<int, int>> month{{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
        if (leap) month.at(1) = {2, 29};

        auto result = make_tuple<int, int>(0, 0);
        for (auto mm : month) {
            // founded
            if ((days - get<1>(mm)) <= 0) {
                result = make_tuple(get<0>(mm), days);
                break;
            }
            days -= get<1>(mm);
        }

        return result;
    }

    auto _calc_date(int days) -> tuple<int, int, int> {
        auto yy = 0;
        tuple<int, int, int> result(0, 0, 0);
        // 1900 special case
        if (days <= 365) {
            result = tuple_cat(make_tuple(1900), _calc_month(days, false));
        }

        else {
            days -= 365;

            auto count = 0;
            while(days > 0) {
                ++ count;

                if ((count)%4 == 0) {  // leap year
                    if (days - 366 <= 0)
                        result = tuple_cat(make_tuple(1900 + count), _calc_month(days, true));
                    days -= 366;
                }
                else {
                    if (days - 365 <= 0)
                        result = tuple_cat(make_tuple(1900 + count), _calc_month(days, false));
                        auto temp_date = _calc_month(days, false);
                    days -= 365;
                }
            }
        }
        return result;
    }

    auto TRADE_DATE_gen(long seed, int num_of_date) -> vector<TRADE_DATE> {
        mt19937 gen(seed);
        uniform_int_distribution<int> distr_day(0, MAX_DATE_DAY), distr_duration(MIN_DATE_DURATION, MAX_DATE_DURATION);
        vector<TRADE_DATE> t_dates;

        for (auto i = 0; i < num_of_date; i++) {
            auto st_day = distr_day(gen);
            TRADE_DATE new_date(st_day, st_day + distr_duration(gen));
            t_dates.push_back(new_date);
        }
    
        return t_dates;
    }

    auto intersection_finder(vector<TRADE_DATE> tDate) -> void {
        sort(tDate.begin(), tDate.end(), less<TRADE_DATE>());

        for (auto date : tDate) {
            auto iter_begin = lower_bound(tDate.begin(), tDate.end(), date.get_raw_begin_date());
            auto iter_end = upper_bound(tDate.begin(), tDate.end(), date.get_raw_end_date());
            vector<TRADE_DATE> found_result{iter_begin, iter_end};
            for (auto sub_date : found_result) {
                auto end_date = min(sub_date.get_raw_end_date(), date.get_raw_end_date());
                cout << "TRADE_DATA ID: " << date.get_ID() \
                << " overlaps with TRADE_DATE ID: " << sub_date.get_ID() \
                << " by " << end_date - date.get_raw_begin_date() << " days." << endl;
            }
        }
    }
}