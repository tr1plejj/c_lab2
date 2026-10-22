#include "task7.h"

#include <algorithm>
#include <deque>
#include <string>
#include <vector>

#include "io_utils.h"

namespace lab2 {

void SortByLengthDesc(std::deque<std::string>& d) {
  std::sort(d.begin(), d.end(),
            [](const std::string& left, const std::string& right) {
              if (left.size() != right.size()) {
                return left.size() > right.size();
              }
              return left < right;
            });
}

void RunTask7() {
  std::vector<std::string> words =
      ReadWords("Введите английские слова через пробел: ", 1);
  std::deque<std::string> d(words.begin(), words.end());
  Print("Исходный дек D: ", d);
  SortByLengthDesc(d);
  Print("Результат: ", d);
}

}  // namespace lab2
