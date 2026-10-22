#include "task8.h"

#include <deque>
#include <iterator>
#include <list>
#include <numeric>
#include <string>
#include <vector>

#include "io_utils.h"

namespace lab2 {

std::deque<std::string> MakePairStrings(const std::list<std::string>& l) {
  std::deque<std::string> d;
  std::adjacent_difference(
      l.begin(), l.end(), std::back_inserter(d),
      [](const std::string& right, const std::string& left) {
        return std::string{left.front(), right.back()};
      });
  if (!d.empty()) {
    d.erase(d.begin());
  }
  return d;
}

void RunTask8() {
  std::vector<std::string> words =
      ReadWords("Введите английские слова (не менее 2): ", 2);
  std::list<std::string> l(words.begin(), words.end());
  Print("Исходный список L: ", l);
  Print("Дек D: ", MakePairStrings(l));
}

}  // namespace lab2
