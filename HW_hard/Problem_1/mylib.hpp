#include "mylib.hpp"
#include <cassert>

struct Class1 {
  void size();
} 
o1;

struct Class2 {
  void size();
}
o2;

struct Empty {

}
e1;

int main() {

  std::cout << "123" << std::endl;
  mylib::has_size answer_machine;
  static_assert(mylib::has_size<Class1>::value == true);
  static_assert(mylib::has_size<Class2>::value == true);
  static_assert(mylib::has_size<Empty>::value == false);
  
  static_assert(mylib::has_size_v<Class1> == true);
  static_assert(mylib::has_size_v<Class2> == true);
  static_assert(mylib::has_size_v<Empty> == false);

  assert(mylib::has_size(o1) == true);
  assert(mylib::has_size(o2) == true);
  assert(mylib::has_size(e1) == false);

  assert(answer_machine(o1) == true);
  assert(answer_machine(o2) == true);
  assert(answer_machine(e1) == false);
}
