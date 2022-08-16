#include <iostream>
#include <vector>
#include "question_7a.h"
#include "question_7b.h"
#include "question_7c.h"

using namespace std;

int main () {
    static int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    question_7a::Printer<int, 10, 10, a>::print();
    question_7b::Printer<int, 10, 10, a>::print();
    cout << question_7c::_Equal(1, 2, 3, 4, 5) << endl;
}