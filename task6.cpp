#include "task6.h"

#include <algorithm>
#include <vector>

#include "io_utils.h"

namespace lab2 {

namespace {

constexpr int kBlockSize = 5;
constexpr int kMinSize = 2 * kBlockSize;

}  // namespace

void FillEndsWithFill(std::vector<int>& v, int a, int b) {
  std::fill(v.begin(), v.begin() + kBlockSize, a);
  std::fill(v.end() - kBlockSize, v.end(), b);
}

void FillEndsWithFillN(std::vector<int>& v, int a, int b) {
  std::fill_n(v.begin(), kBlockSize, a);
  std::fill_n(v.end() - kBlockSize, kBlockSize, b);
}

void RunTask6() {
  int a = ReadInt("Введите число A: ", kMinInt, kMaxInt);
  int b = ReadInt("Введите число B: ", kMinInt, kMaxInt);
  std::vector<int> v1 =
      ReadInts("Введите элементы V1 (не менее 10): ", kMinSize, 1);
  std::vector<int> v2 =
      ReadInts("Введите элементы V2 (не менее 10): ", kMinSize, 1);

  FillEndsWithFill(v1, a, b);
  FillEndsWithFillN(v2, a, b);
  Print("V1 после fill:   ", v1);
  Print("V2 после fill_n: ", v2);
}

}  // namespace lab2
