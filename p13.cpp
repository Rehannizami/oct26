/* You may complete as many transactions as you like,
but after selling you cannot buy on the next day (one-day cooldown).
You hold at most one share at a time.
Return the maximum profit.
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(const std::vector<int> &prices) {
  if (prices.empty())
    return 0;

  int hold = -prices[0];
  int sold = 0;
  int rest = 0;
  for (size_t i = 1; i < prices.size(); ++i) {
    int prev_hold = hold;
    int prev_sold = sold;

    hold = std::max(prev_hold, rest - prices[i]);
    sold = prev_hold + prices[i];
    rest = std::max(rest, prev_sold);
  }
  return std::max(sold, rest);
}

int main() {
  const std::vector<int> stock = {665, 312, 887, 441, 886, 445};
  std::cout << maxProfit(stock) << std::endl;
}