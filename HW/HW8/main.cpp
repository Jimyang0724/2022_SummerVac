#include <iostream>
#include <tuple>
#include <vector>
#include <deque>
#include <set>
#include <list>
#include "tuple_printer.h"
#include "back_inserter.h"
using namespace std;

int main() {
    tuple<int, char, int> t1(1, 'a', 3);
    tuple_printer::printer(t1);

    vector<short> v1;
    deque<short> d1;
    set<short> s1;
    list<short> l1;

    back_inserter::Back_inserter v(v1);
    v.insert_100k();

    back_inserter::Back_inserter d(d1);
    d.insert_100k();

    back_inserter::Back_inserter s(s1);
    s.insert_100k();

    back_inserter::Back_inserter l(l1);
    l.insert_100k();

    cout << "========================" << endl;

    v.change_to_5566();
    d.change_to_5566();
    s.insert_100k();
    l.change_to_5566();
    return 0;
}
