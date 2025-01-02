/* Maximum Score from Subarray Minimums(https://www.geeksforgeeks.org/problems/max-sum-in-sub-arrays0824/0?category):

Given an array arr[], with 0-based indexing, select any two indexes, i and j such that i < j. 
From the subarray arr[i...j], select the smallest and second smallest numbers and add them, 
you will get the score for that subarray. 
Return the maximum possible score across all the subarrays of array arr[]. */

// Brute force approach, t.c.= O(n^2), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pairWithMaxSum(vector<int> &arr) {
        int n = arr.size();
        int maxScore = 0; // arr = [2 1 5 7 8 1 6 3] ans = 15
        for (int i = 0; i < n - 1; i++) {
            int curScore = 0;
            int small = arr[i];
            int secSmall = arr[i + 1];
            for (int j = i + 1; j < n; j++) {
                if (arr[j] < small) {
                    secSmall = small;
                    small = arr[j];
                } else if (arr[j] < secSmall)
                    secSmall = arr[j];
                curScore = small + secSmall;
                maxScore = max(maxScore, curScore);
            }
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