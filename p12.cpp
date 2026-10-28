/* prices[i] is the price of a stock on day i.
Pick one day to buy and a later day to sell.
Return the maximum profit,
or 0 if no profit is possible.
*/

#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &prices, int buyDate, int sellDate) {
  int profit = prices.at(sellDate - 1) - prices.at(buyDate - 1);
  if (profit >= 0) {
    return profit;
  }
  return 0;
}

int main() {
  vector<int> stockprice;
  stockprice.resize(5);
  for (int num : stockprice) {
    std::cin >> num;
    std::cout << "\n";
  }
  for (int num : stockprice) {
    std::cout << num << " ";
  }
  std::cout << "buyDate: ";
  int bD;
  std::cin >> bD;
  std::cout << "sellDate: ";
  int sD;
  std::cin >> sD;
  std::cout << maxProfit(stockprice, bD, sD);
}
