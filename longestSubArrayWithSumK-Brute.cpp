/* Longest Sub-Array with Sum K(https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1):

Given an array arr containing n integers and an integer k. 
Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value k. */

// brute-force approach w/ t.c. O(~n^3), if optimized O(n^2), s.c.- O(1).
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lenOfLongestSubArr(int arr[], int n, int k) {
        int longestLen = 0;

        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=i; j<n; j++) {
                sum += arr[j];
                if(sum == k) 
                    longestLen = max(longestLen, j - i + 1);
            }
        }

        return longestLen;
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