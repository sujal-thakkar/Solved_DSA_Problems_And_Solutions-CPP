/* 1011. Capacity To Ship Packages Within D Days(https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/):

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i].
Each day, we load the ship with packages on the conveyor belt (in the order given by weights).
We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days. */

// optimized solution: s.c.= O(n * (sum of weights)) + O(n), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findDays(vector<int> &weights, int capacity) {
        int n = weights.size();
        int load = 0;
        int days = 1;
        for (int it : weights) {
            if (it <= capacity - load) {
                load += it;
            } else {
                days++;
                load = 0;
                load = it;
            }
        }
        return days;
    }
    int shipWithinDays(vector<int> &weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0);
        int ans = -1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int curDays = findDays(weights, mid);
            if (curDays <= days) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    int days;
    cin >> days;
    Solution sol;
    int ans = sol.shipWithinDays(weights, days);
    cout << ans;

    return 0;
}