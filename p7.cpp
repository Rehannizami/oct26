#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
void prb1(std::vector<int> array) {
  std::unordered_map<int, int> frequencies;
  for (int i = 0; i < array.size(); i++) {
    int frequency = std::count(array.begin(), array.end(), array[i]);
    frequencies[array.at(i)] = frequency;
  }
  for (const auto &[key, value] : frequencies) {
    std::cout << key << " : " << value;
    std::cout << "\n";
  }
}

void prb2(std::vector<int> array) {
  std::unordered_map<int, int> frequencies;
  for (int num : array) {
    frequencies[num]++;
  }
  for (const auto &[key, value] : frequencies) {
    if (value == 1) {
      std::cout << key;
      return;
    }
  }
  std::cout << "-1" << "\n";
}

void prb3(std::vector<int> array) {
  std::sort(array.begin(), array.end(), [](int a, int b) { return a < b; });
  for (int i = 0; i < array.size(); i++) {
    if (array.at(i) == array.at(i + 1))
      array.erase(array.begin() + i);
    if (array.at(i) != array.at(i + 1))
      continue;
  }
  for (int num : array) {
    std::cout << num << " , ";
  }
}

int main() {
  std::cout << "Program executed" << "\n";
  prb1({2, 3, 4, 4, 5, 5, 7, 1, 2});
  prb2({4, 5, 1, 2, 1, 4, 5});
  prb3({7, 2, 5, 2, 9, 7, 1, 5, 3});
  return 0;
}