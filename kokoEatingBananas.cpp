/* 875. Koko Eating Bananas(https://leetcode.com/problems/koko-eating-bananas/description/):

Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas.
The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour,
she chooses some pile of bananas and eats k bananas from that pile.
If the pile has less than k bananas,
she eats all of them instead and will not eat any more bananas during this hour.

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long findHours(vector<int> &piles, int k) { // piles = [3,6,7,11], h = 8 | ans = 4
        int n = piles.size();
        long hours = 0;
        for (int i = 0; i < n; i++) {
            hours += piles[i] / k;
            if (piles[i] % k != 0)
                hours++;
        }
        return hours;
    }
    int minEatingSpeed(vector<int> &piles, int h) {
        int n = piles.size();
        int maxEle = 0;
        for (int i = 0; i < n; i++)
            maxEle = max(maxEle, piles[i]);

        int ans = 0;
        int l = 1, r = maxEle;

        // (Linear search) Overall Time Complexity: O(maXEle(for loop) * maxEle(calling of the findHours func) * n(opearations in findHours().));
        /* for(int i=l; i<=r; i++) { 
            if(findHours(piles, i) <= h) {
                ans = i;
                break;
            }
        } */

       // (Binary Search) Overall Time Complexity: O(log maxEle * n)
        while (l <= r) {
            int k = l + (r - l) / 2;
            long reqHours = findHours(piles, k);
            if (reqHours <= h) {
                ans = k;
                r = k - 1;
            } else if (reqHours > h) {
                l = k + 1;
            }
        }
        return ans;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }
    int h;
    cin >> h;
    Solution sol;
    int ans = sol.minEatingSpeed(piles, h);
    cout << ans;
    return 0;
}