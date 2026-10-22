#include "task10.h"

#include <iostream>
#include <map>
#include <vector>

#include "io_utils.h"

namespace lab2 {

std::map<int, int> CountRepeats(const std::vector<int>& v) {
  std::map<int, int> m;
  for (std::vector<int>::const_iterator it = v.begin(); it != v.end(); ++it) {
    ++m[*it];
  }
  return m;
}

void RunTask10() {
  std::vector<int> v = ReadInts("Введите элементы вектора V: ", 1, 1);
  std::map<int, int> m = CountRepeats(v);
  std::cout << "Элемент и количество повторений:\n";
  for (std::map<int, int>::const_iterator it = m.begin(); it != m.end();
       ++it) {
    std::cout << it->first << ' ' << it->second << '\n';
  }
}

}  // namespace lab2
