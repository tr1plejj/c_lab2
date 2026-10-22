#include "task2.h"

#include <iterator>
#include <list>
#include <vector>

#include "io_utils.h"

namespace lab2 {

void AppendFirstThirdReversed(std::list<int>& l) {
  std::list<int>::iterator third_end = std::next(l.begin(), l.size() / 3);
  l.insert(l.end(), std::make_reverse_iterator(third_end), l.rend());
}

void RunTask2() {
  std::vector<int> numbers = ReadInts(
      "Введите целые числа (количество кратно 3): ", 3, 3);
  std::list<int> l(numbers.begin(), numbers.end());
  Print("Исходный список L: ", l);
  AppendFirstThirdReversed(l);
  Print("Результат: ", l);
}

}  // namespace lab2
