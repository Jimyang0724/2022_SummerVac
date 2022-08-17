#include <iostream>
#include <tuple>
#include "tuple_printer.h"
using namespace std;

int main() {
    tuple<int, int, int> t1(1, 2, 3);
    tuple_printer::printer(t1);
    return 0;
}