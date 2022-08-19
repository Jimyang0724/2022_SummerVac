#include <iostream>
#include <vector>
#include <tuple>
#include <random>
#include "trade_date.h"

using namespace std;

#define MAX_DATE_DURATION 10
#define MIN_DATE_DURATION 1
#define MAX_DATE_DAY (365*100+24)

#define DEBUG false

namespace trade_date {
    int TRADE_DATE::ID_counter = 0;
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

    auto _calc_back_to_days(tuple<int, int, int> date) -> int {
        // calc days by year (sp case is 1900)
        auto num_of_years = get<0>(date) - 1900;
        auto num_days = \
            (num_of_years == 0) ? 0 : (num_of_years * 365 + num_of_years/4);
        
        //calc days by month (sp case is 1900)
        vector<tuple<int, int>> month{{1, 31}, {2, 28}, {3, 31}, {4, 30}, {5, 31}, {6, 30}, {7, 31}, {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}};
        if (num_of_years != 0 && num_of_years % 4 == 0) month.at(1) = {2, 29};

        auto temp_days = 0;
        cout << num_days << " ";
        for (auto mm : month) {
            if (get<0>(mm) == get<1>(date)) break;
            temp_days += get<1>(mm);
            num_days += get<1>(mm);
        }
        cout << temp_days << " ";
        cout << get<2>(date) << endl;

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
        // cout << get<0>(result) << " " << get<1>(result) << " " << get<2>(result) << endl;
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
}