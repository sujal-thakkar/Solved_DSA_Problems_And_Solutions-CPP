/* Union of Two Sorted Arrays(https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1):

Given two sorted arrays of size n and m respectively, find their union.
The Union of two arrays can be defined as the common and distinct elements in the two arrays.
Return the elements in sorted order. */

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m) {
    // Optimized solution.
    // time complexity for the worst case - O(n+m)
    // space complexity (extra space taken for the worst case) - O(n+m)
    // (the extra space is taken in order to return the answer.
    // It's not taken to calculate the problem)

    int i = 0, j = 0;

    vector<int> ans;

    if (arr1[i] <= arr2[j]) {
        ans.push_back(arr1[i++]);
    } else {
        ans.push_back(arr2[j++]);
    }

    while (i < n and j < m) {
        if (arr1[i] <= arr2[j]) {
            if (ans.back() == arr1[i]) {
                i++;
                continue;
            } else {
                ans.push_back(arr1[i++]);
            }
        } else if (arr2[j] < arr1[i]) {
            if (ans.back() == arr2[j]) {
                j++;
                continue;
            } else {
                ans.push_back(arr2[j++]);
            }
        }
    }

    while (i < n) {
        if (ans.back() == arr1[i]) {
            i++;
            continue;
        } else {
            ans.push_back(arr1[i]);
        }
    }

    while (j < m) {
        if (ans.back() == arr2[j]) {
            j++;
            continue;
        } else {
            ans.push_back(arr2[j++]);
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;
    int arr1[n];
    int arr2[m];
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }
    vector<int> ans = findUnion(arr1, arr2, n, m);
    for (int i : ans)
        cout << i << " ";
    return 0;
}