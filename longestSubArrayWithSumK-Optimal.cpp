/* Longest Sub-Array with Sum K(https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1):

Given an array arr containing n integers and an integer k.
Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k. */

// The most Optimal Approach when the array consist only [zeroes and postive elements]
// doesn't work if array consist neg elements.
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenOfLongestSubArr(int arr[], int n, int k) {
        int left = 0, right = 0;
        int preSum = arr[0];
        int maxLen = 0;

        while (right < n) {
            while (preSum > k and left <= right) {
                preSum -= arr[left];
                left++;
            }
            if (preSum == k)
                maxLen = max(maxLen, right - left + 1);

            right++;
            if (right < n)
                preSum += arr[right];
        }

        return maxLen;
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