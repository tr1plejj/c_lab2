#include "task3.h"

#include <cstddef>
#include <iterator>
#include <list>
#include <vector>

#include "io_utils.h"

namespace lab2 {

void InterleaveFromEnds(std::list<int>& l) {
  std::list<int>::iterator i = l.begin();
  std::list<int>::iterator r = std::prev(l.end());
  size_t half = l.size() / 2;
  for (size_t k = 0; k < half; ++k) {
    l.splice(i++, l, r--);
  }
}

void RunTask3() {
  std::vector<int> numbers =
      ReadInts("Введите чётное количество целых чисел: ", 2, 2);
  std::list<int> l(numbers.begin(), numbers.end());
  Print("Исходный список L: ", l);
  InterleaveFromEnds(l);
  Print("Результат: ", l);
}

}  // namespace lab2
