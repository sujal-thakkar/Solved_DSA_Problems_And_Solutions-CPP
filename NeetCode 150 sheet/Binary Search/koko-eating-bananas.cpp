/* 875. Koko Eating Bananas (https://leetcode.com/problems/koko-eating-bananas/description/):

    Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
    The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour,
she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas,
she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours. */

// t.c.= O(n * log(max_element(piles))), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            long long totalTime = 0;
            for (int i : piles) {
                double p = i;
                totalTime += static_cast<int>(ceil(p / mid));
            }
            if (totalTime <= h) {
                ans = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }
        return ans;
    }
};
int main() {
    vector<int> piles = {3,6,7,11};
    int h = 8;
    Solution sol;
    int ans = sol.minEatingSpeed(piles, h);
    cout << "the minimum required eating banana-per-hour speed is: " << ans;

    return 0;
}