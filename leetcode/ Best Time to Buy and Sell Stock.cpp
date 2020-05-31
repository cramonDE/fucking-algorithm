// Say you have an array for which the ith element is the price of a given stock on day i.

// If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.

// Note that you cannot sell a stock before you buy one.

// Example 1:

// Input: [7,1,5,3,6,4]
// Output: 5
// Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
//              Not 7-1 = 6, as selling price needs to be larger than buying price.
// Example 2:

// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.

//暴力解，不断的滑动窗口得到最大的值
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        int flag = 0;
        for (int i = 0; i < prices.size() - 1; i++) {
           if (prices[i] < prices[i + 1]) {
               flag = 1;
               break;
           } 
        }
        if (!flag) return 0;
        int ans = 0;
        for (int i = 0; i < prices.size(); i++) {
            for (int j = i + 1; j < prices.size(); j++) {
                ans = max(ans, prices[j] - prices[i]);
            }
        }
        return ans;
    }
};
// 暴力会超时
// 注意有关顺序的问题，可以考虑最大值和最小值，当发生替换的时候，注意重置
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        int low = prices[0], high = -1, ans = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > low && prices[i] > high) {
                high = prices[i];
            }
            if (prices[i] < low) {
                ans = max(ans, high - low);
                low = prices[i];
                high = -1;
            }
        }
        ans = max(ans, high - low);
        return ans;
    }
};