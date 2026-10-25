// Given an integer array, return all unique triplets [a, b, c] with a + b + c =
// 0. The result must not contain duplicate triplets.

#include <bits/stdc++.h>
using namespace std;

vector<int> threeSum(vector<int> &nums) {

  int left, right = 0;
  for (int i = 0; i < nums.size(); i++) {
    left = 0;
    right = nums.size() - 1;
    if (nums[left] + nums[right] == -nums[i]) {
      return {left, i, right};
    } else if (nums[left] + nums[right] > -nums[i]) {
      left++;
      right--;
    } else {
      return {};
    }
  }
  return {};
}

int main() {
  try {
    vector<int> array = { −1, 0, 1, 2, −1, −4};
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
  return 0;
}