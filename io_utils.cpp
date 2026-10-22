#include "io_utils.h"

#include <cctype>
#include <charconv>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <optional>
#include <sstream>
#include <string>
#include <vector>

namespace lab2 {

namespace {

std::vector<std::string> SplitBySpaces(const std::string& line) {
  std::istringstream stream(line);
  return std::vector<std::string>(std::istream_iterator<std::string>(stream),
                                  std::istream_iterator<std::string>());
}

std::optional<int> ParseInt(const std::string& text) {
  int value = 0;
  const char* end = text.data() + text.size();
  auto [stop, error] = std::from_chars(text.data(), end, value);
  if (error != std::errc() || stop != end) {
    return std::nullopt;
  }
  return value;
}

bool IsEnglishWord(const std::string& word) {
  for (unsigned char c : word) {
    if (!std::isalpha(c)) {
      return false;
    }
  }
  return true;
}

}  // namespace

std::string ReadLine(const std::string& prompt) {
  std::cout << prompt;
  std::string line;
  if (!std::getline(std::cin, line)) {
    std::cout << "\nВвод завершён. Выход из программы.\n";
    std::exit(EXIT_SUCCESS);
  }
  return line;
}

int ReadInt(const std::string& prompt, int min, int max) {
  while (true) {
    std::vector<std::string> tokens = SplitBySpaces(ReadLine(prompt));
    std::optional<int> value;
    if (tokens.size() == 1) {
      value = ParseInt(tokens[0]);
    }
    if (value && *value >= min && *value <= max) {
      return *value;
    }
    std::cout << "Ошибка: нужно одно целое число от " << min << " до " << max
              << ".\n";
  }
}

std::vector<int> ReadInts(const std::string& prompt, size_t min_count,
                          size_t multiple) {
  while (true) {
    std::vector<std::string> tokens = SplitBySpaces(ReadLine(prompt));
    std::vector<int> numbers;
    std::string bad_token;
    for (const std::string& token : tokens) {
      std::optional<int> value = ParseInt(token);
      if (!value) {
        bad_token = token;
        break;
      }
      numbers.push_back(*value);
    }

    if (!bad_token.empty()) {
      std::cout << "Ошибка: \"" << bad_token
                << "\" не является целым числом (int).\n";
    } else if (numbers.size() < min_count) {
      std::cout << "Ошибка: нужно не меньше " << min_count << " чисел.\n";
    } else if (numbers.size() % multiple != 0) {
      std::cout << "Ошибка: количество чисел должно делиться на " << multiple
                << ".\n";
    } else {
      return numbers;
    }
  }
}

std::vector<std::string> ReadWords(const std::string& prompt,
                                   size_t min_count) {
  while (true) {
    std::vector<std::string> words = SplitBySpaces(ReadLine(prompt));
    bool all_english = true;
    for (const std::string& word : words) {
      if (!IsEnglishWord(word)) {
        std::cout << "Ошибка: \"" << word
                  << "\" не английское слово (только буквы a-z, A-Z).\n";
        all_english = false;
        break;
      }
    }
    if (!all_english) {
      continue;
    }
    if (words.size() >= min_count) {
      return words;
    }
    std::cout << "Ошибка: нужно не меньше " << min_count << " слов.\n";
  }
}

}  // namespace lab2
