#include "task9.h"

#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

#include "io_utils.h"

namespace lab2 {

namespace {

constexpr int kMaxVectorCount = 100;

}  // namespace

int CountContainingAll(const std::vector<int>& v0,
                       const std::vector<std::vector<int>>& vectors) {
  std::set<int> required(v0.begin(), v0.end());
  int count = 0;
  for (std::vector<std::vector<int>>::const_iterator it = vectors.begin();
       it != vectors.end(); ++it) {
    std::set<int> current(it->begin(), it->end());
    if (std::includes(current.begin(), current.end(), required.begin(),
                      required.end())) {
      ++count;
    }
  }
  return count;
}

void RunTask9() {
  std::vector<int> v0 = ReadInts("Введите элементы V0: ", 1, 1);
  int n = ReadInt("Введите N (от 1 до 100): ", 1, kMaxVectorCount);
  std::vector<std::vector<int>> vectors;
  for (int i = 1; i <= n; ++i) {
    vectors.push_back(ReadInts("Введите элементы V" + std::to_string(i) +
                                   " (не менее " + std::to_string(v0.size()) +
                                   "): ",
                               v0.size(), 1));
  }
  std::cout << "Векторов, содержащих все элементы V0: "
            << CountContainingAll(v0, vectors) << '\n';
}

}  // namespace lab2
