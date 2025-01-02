/* Array Leaders(https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1):

Given an array arr of n positive integers, your task is to find all the leaders in the array.
An element of the array is considered a leader if it is greater than all the elements on its right side
or if it is equal to the maximum element on its right side. The rightmost element is always a leader. */

//
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> ans;
        int maxi = INT_MIN;
        for (int i = n - 1; i >= 0; i--) {
            if (arr[i] >= maxi) {
                ans.push_back(arr[i]);
                maxi = arr[i];
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Solution sol;
    vector<int> ans = sol.leaders(n, arr);
    cout << "the leaders are: ";
    for (int i : ans)
        cout << i << " ";

    return 0;
}