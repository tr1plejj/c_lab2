#ifndef LAB2_IO_UTILS_H_
#define LAB2_IO_UTILS_H_

#include <cstddef>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

namespace lab2 {

constexpr int kMinInt = std::numeric_limits<int>::min();
constexpr int kMaxInt = std::numeric_limits<int>::max();

std::string ReadLine(const std::string& prompt);

int ReadInt(const std::string& prompt, int min, int max);

std::vector<int> ReadInts(const std::string& prompt, size_t min_count,
                          size_t multiple);

std::vector<std::string> ReadWords(const std::string& prompt, size_t min_count);

template <typename Container>
void Print(const std::string& title, const Container& container) {
  std::cout << title;
  for (typename Container::const_iterator it = container.begin();
       it != container.end(); ++it) {
    std::cout << *it << ' ';
  }
  std::cout << '\n';
}

}  // namespace lab2

#endif  // LAB2_IO_UTILS_H_
