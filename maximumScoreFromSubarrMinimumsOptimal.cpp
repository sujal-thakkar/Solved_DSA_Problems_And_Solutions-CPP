/* Maximum Score from Subarray Minimums(https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category):

Given an array arr[], with 0-based indexing, select any two indexes, i and j such that i < j.
From the subarray arr[i...j], select the smallest and second smallest numbers and add them,
you will get the score for that subarray.
Return the maximum possible score across all the subarrays of array arr[]. */

// Optimal solution, t.c.= O(n), s.c.= O(1)
/* Intuition: An efficient solution is based on the observation that this problem reduces to finding
a maximum sum of two consecutive elements in array.
If (x,y) is the pair such that (x+y) is the answer,
then x and y must be consecutive elements in the array. */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pairWithMaxSum(vector<int> &arr) {
        int n = arr.size();
        if (n < 2)
            return -1;
        int maxScore = arr[0] + arr[1];
        for (int i = 1; i < n - 1; i++) {
            maxScore = max(maxScore, arr[i] + arr[i + 1]);
        }
        return maxScore;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution sol;
    int ans = sol.pairWithMaxSum(arr);
    cout << ans;

    return 0;
}