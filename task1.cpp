#include "task1.h"

#include <iostream>
#include <vector>

#include "io_utils.h"

namespace lab2 {

void PrintSecondHalfThenFirst(const std::vector<int>& v) {
  std::vector<int>::const_iterator middle = v.begin() + v.size() / 2;
  std::cout << "Результат: ";
  for (std::vector<int>::const_iterator it = middle; it != v.end(); ++it) {
    std::cout << *it << ' ';
  }
  for (std::vector<int>::const_iterator it = v.begin(); it != middle; ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
}

void RunTask1() {
  std::vector<int> numbers =
      ReadInts("Введите чётное количество целых чисел: ", 2, 2);
  std::vector<int> v(numbers.begin(), numbers.end());
  Print("Вектор V: ", v);
  PrintSecondHalfThenFirst(v);
}

}  // namespace lab2
