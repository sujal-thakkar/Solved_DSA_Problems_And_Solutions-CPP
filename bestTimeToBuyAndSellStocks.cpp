/* 121. Best Time to Buy and Sell Stock(https://leetcode.com/problems/best-time-to-minBuyingPrice-and-sell-stock/description/):

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to minBuyingPrice one stock 
and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. 
If you cannot achieve any profit, return 0. */

// optimal approach, also a problem of Dynamic Programming, t.c.= O(n), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minBuyingPrice = prices[0];
        int maxProfit = 0;
        for(int i=1; i<n; i++) {
            minBuyingPrice = min(minBuyingPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i] - minBuyingPrice);
        }
        return maxProfit;
    }
};
int main() {
    int n;
    cin>>n;
    vector<int>prices(n);
    for(int i=0; i<n; i++) {
        cin >> prices[i];
    }
    Solution sol;
    int ans = sol.maxProfit(prices);
    cout << ans;
 
    return 0;
}