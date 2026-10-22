#include "task5.h"

#include <algorithm>
#include <vector>

#include "io_utils.h"

namespace lab2 {

void EraseSecondZero(std::vector<int>& v) {
  std::vector<int>::iterator first = std::find(v.begin(), v.end(), 0);
  if (first == v.end()) {
    return;
  }
  std::vector<int>::iterator second = std::find(first + 1, v.end(), 0);
  if (second != v.end()) {
    v.erase(second);
  }
}

void RunTask5() {
  std::vector<int> v = ReadInts("Введите элементы вектора V: ", 1, 1);
  Print("Исходный вектор V: ", v);
  EraseSecondZero(v);
  Print("Результат: ", v);
}

}  // namespace lab2
