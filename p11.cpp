// You are given two sorted arrays A and B and an integer k. Form pairs (A[i],
// B[j]) and return the k pairs with the smallest sums, in increasing order of
// sum.

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> kSmallestPairs(vector<int> &A, vector<int> &B, int k) {
  vector<pair<int, int>> result;
  if (A.empty() || B.empty() || k <= 0)
    return result;
  using Element = tuple<long long, int, int>;
  priority_queue<Element, vector<Element>, greater<Element>> miniHeap;
  // Initialize heap with (A[i], B[0]) for the first min(A.size(), k) rows
  int limit = min((int)A.size(), k);
  for (int i = 0; i < limit; i++) {
    minHeap.push({(long long)A[i] + B[0], i, 0});
  }

  // Extract the smallest pairs up to k times
  while (!minHeap.empty() && (int)result.size() < k) {
    auto [sum, i, j] = minHeap.top();
    minHeap.pop();

    result.push_back({A[i], B[j]});

    // Push the next candidate in the same row: (A[i], B[j + 1])
    if (j + 1 < (int)B.size()) {
      minHeap.push({(long long)A[i] + B[j + 1], i, j + 1});
    }
  }

  return result;
}

int main() {
  vector<int> A = {1, 7, 11};
  vector<int> B = {2, 4, 6};
  int k = 3;

  auto ans = kSmallestPairs(A, B, k);
  for (auto &p : ans) {
    cout << "[" << p.first << ", " << p.second << "] ";
  }
  cout << "\n";
  // Expected output: [1, 2] [1, 4] [1, 6]

  return 0;
}
