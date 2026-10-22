#include <iostream>
#include <iterator>

#include "io_utils.h"
#include "task1.h"
#include "task10.h"
#include "task2.h"
#include "task3.h"
#include "task4.h"
#include "task5.h"
#include "task6.h"
#include "task7.h"
#include "task8.h"
#include "task9.h"

namespace {

struct MenuItem {
  const char* title;
  void (*run)();
};

constexpr MenuItem kMenu[] = {
    {"1.3  Вектор: вторая половина, затем первая", lab2::RunTask1},
    {"2.3  Список: дописать первую треть в обратном порядке", lab2::RunTask2},
    {"3.10 Список: порядок AN, A1, AN-1, A2, ... (splice)", lab2::RunTask3},
    {"4.5  Символы: заменить цифры на '_'", lab2::RunTask4},
    {"5.1  Вектор: удалить второй нулевой элемент", lab2::RunTask5},
    {"6.1  Векторы: первые 5 = A, последние 5 = B", lab2::RunTask6},
    {"7.11 Дек слов: сортировка по убыванию длины", lab2::RunTask7},
    {"8.2  Список слов -> дек пар букв", lab2::RunTask8},
    {"9.1  Множества: сколько VI содержат все элементы V0", lab2::RunTask9},
    {"10.1 Отображение: количество повторений чисел", lab2::RunTask10},
};
constexpr int kMenuSize = static_cast<int>(std::size(kMenu));

}  // namespace

int main() {
  while (true) {
    std::cout << "\n=== Лабораторная работа №2 (STL), вариант 1 ===\n";
    for (int i = 0; i < kMenuSize; ++i) {
      std::cout << (i + 1) << ". " << kMenu[i].title << '\n';
    }
    std::cout << "0. Выход\n";

    int choice = lab2::ReadInt("Выберите задание: ", 0, kMenuSize);
    if (choice == 0) {
      return 0;
    }
    std::cout << '\n';
    kMenu[choice - 1].run();
  }
}
