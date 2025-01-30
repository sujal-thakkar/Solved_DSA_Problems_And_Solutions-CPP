/* 121. Best Time to Buy and Sell Stock(https://leetcode.com/problems/best-time-to-buy-and-sell-stock/):

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to minBuyingPrice one stock
and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction.
If you cannot achieve any profit, return 0. */

//t.c.-O(n), s.c.- O(1), two pointer approach.
#include <bits/stdc++.h>
using namespace std;

class Solution { 
public:
    int maxProfit(vector<int> &prices) {
        int l = 0, r = 1;
        int maxP = 0;
        while (r < prices.size()) {
            if (prices[r] > prices[l]) {
                maxP = max(maxP, prices[r] - prices[l]);
                r++;
            } else {
                l = r;
                r++;
            }
        }
        return maxP;
    }
    // 2nd method using approach of calculating cost of each stock buy and sell. t.c.- O(n), s.c.- O(1)
    int maxProfitSecondSol(vector<int> &prices) {
        int buyingPrice=prices[0];
        int maxProfit=0;
        for(int i=1;i<prices.size();i++){
            int cost=prices[i]-buyingPrice;
            maxProfit=max(maxProfit,cost);
            buyingPrice=min(buyingPrice,prices[i]);
        }
        return maxProfit;
    }
};
    int main() {
        int n;
        cin >> n;
        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        Solution sol;
        int ans = sol.maxProfit(prices);
        cout << ans;

        return 0;
    }