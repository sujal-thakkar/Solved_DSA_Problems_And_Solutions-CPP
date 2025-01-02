/* Array Leaders(https://www.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1):

Given an array arr of n positive integers, your task is to find all the leaders in the array.
An element of the array is considered a leader if it is greater than all the elements on its right side
or if it is equal to the maximum element on its right side. The rightmost element is always a leader. */

// Brute force approach, t.c.= o(n^2), s.c.= O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
    // Function to find the leaders in the array.
public:
    vector<int> leaders(int n, int arr[]) {
        // Code here
        vector<int> ans;

        for (int i = 0; i < n; i++) { // [12 25 6 8 1 5]
            if (i == n - 1) {
                ans.push_back(arr[i]);
                break;
            }
            bool flag = true;
            for (int j = i + 1; j < n; j++) {
                if (arr[j] > arr[i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag)
                ans.push_back(arr[i]);
        }
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