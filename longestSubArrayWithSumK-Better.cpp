/* Longest Sub-Array with Sum K(https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1):

Given an array arr containing n integers and an integer k.
Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k. */

// better approach w/ t.c. O(n logn)[if use ordered map] & O(n * 1)[if use unordered map]...
// but can go upto O(n * n)[if collisions happen when using unor-map], s.c.- O(n).
// But *The most Optimal approach when the array consist [neg, zeroes, positive] elements.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenOfLongestSubArr(int arr[], int n, int k) {
        map<int, int> mpp;

        int prefSum = 0;
        int longestSarr = 0;

        for (int i = 0; i < n; i++) {
            prefSum += arr[i];

            if (prefSum == k)
                longestSarr = i + 1;

            int remaining = prefSum - k;

            if (mpp.find(remaining) != mpp.end()) {
                int len = i - mpp[remaining];
                longestSarr = max(longestSarr, len);
            }

            if (mpp.find(prefSum) == mpp.end()) {
                mpp[prefSum] = i;
            }
        }

        return longestSarr;
    }
};
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    Solution sol;
    int ans = sol.lenOfLongestSubArr(arr, n, k);
    cout << ans;

    return 0;
}