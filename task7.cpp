#include "task7.h"

#include <algorithm>
#include <cctype>
#include <deque>
#include <string>
#include <vector>

#include "io_utils.h"

namespace lab2 {

namespace {

bool LessIgnoreCase(const std::string& left, const std::string& right) {
  return std::lexicographical_compare(
      left.begin(), left.end(), right.begin(), right.end(),
      [](unsigned char a, unsigned char b) {
        return std::tolower(a) < std::tolower(b);
      });
}

}  // namespace

void SortByLengthDesc(std::deque<std::string>& d) {
  std::sort(d.begin(), d.end(),
            [](const std::string& left, const std::string& right) {
              if (left.size() != right.size()) {
                return left.size() > right.size();
              }
              return LessIgnoreCase(left, right);
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
