/* Union of Two Sorted Arrays(https://www.geeksforgeeks.org/problems/union-of-two-sorted-arrays-1587115621/1):

Given two sorted arrays of size n and m respectively, find their union. 
The Union of two arrays can be defined as the common and distinct elements in the two arrays. 
Return the elements in sorted order. */

#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(int arr1[], int arr2[], int n, int m)
{
    // Your code here
    // return vector with correct order of elements

    // brute force solution -
    // time complexity - O(n + m + (n logn))
    // space complexity - O(2(n+m))

    vector<int> temp(n + m);

    for (int i = 0; i < n; i++)
    {
        temp[i] = arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        temp[n] = arr2[i];
        n++;
    }

    sort(temp.begin(), temp.end());
    vector<int> ans;

    int t = temp[0];
    for (int i = 1; i < temp.size(); i++)
    {
        if (temp[i] != t)
        {
            ans.push_back(temp[i - 1]);
            t = temp[i];
        }
        if (i == temp.size() - 1)
        {
            ans.push_back(temp[i]);
        }
    }

    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    int arr1[n];
    int arr2[m];
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    vector<int> ans = findUnion(arr1, arr2, n, m);
    for (int i : ans)
        cout << i << " ";
    return 0;
}