// Given a non-decreasing array of integers and a target,
// return the 1-based indices of the two numbers that add up to the target.
// Exactly one answer exists. Use O(1) extra space.

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target) {
  int l = 0;
  int r = nums.size() - 1;
  while (l < r) {
    if (nums.at(l) + nums.at(r) == target) {
      return {l + 1, r + 1};
    } else if (nums.at(l) + nums.at(r) < target) {
      l++;
    } else {
      r--;
    }
  }
  return {};
}
int main() {
  try {
    vector<int> array = {2, 7, 11, 15};
    if (array.size() < 2 || array.size() > 1e5) {
      throw "Out of Constraints";
    }
    for (int i = 0; i < array.size(); i++) {
      if (array[i] < -1e9 || array[i] > 1e9) {
        throw "Out of Constraints";
      }
    }
    vector<int> result = twoSum(array, 9);
    for (int num : result) {
      std::cout << num << " ";
    }
    std::cout << "\n";
  } catch (const char *msg) {
    std::cout << "Error: " << msg << "\n";
  }
}