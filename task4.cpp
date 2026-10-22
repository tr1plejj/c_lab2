#include "task4.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

#include "io_utils.h"

namespace lab2 {

void ReplaceDigits(std::istream& in, std::ostream& out) {
  in >> std::noskipws;
  std::replace_copy_if(
      std::istream_iterator<char>(in), std::istream_iterator<char>(),
      std::ostream_iterator<char>(out),
      [](unsigned char c) { return std::isdigit(c) != 0; }, '_');
}

void RunTask4() {
  std::string line = ReadLine("Введите набор символов: ");
  while (line.empty()) {
    line = ReadLine("Ошибка: набор пуст. Введите хотя бы один символ: ");
  }
  std::istringstream in(line);
  std::cout << "Результат: ";
  ReplaceDigits(in, std::cout);
  std::cout << '\n';
}

}  // namespace lab2
