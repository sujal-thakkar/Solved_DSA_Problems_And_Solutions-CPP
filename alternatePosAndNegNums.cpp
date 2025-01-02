// Alternate positive and negative numbers (https://www.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1):
// Given an unsorted array Arr of N positive and negative numbers.
// Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers.

// Note: Array should start with a positive number and 0 (zero) should be considered a positive element.

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void rearrange(int arr[], int n)
    {
        vector<int> pos, neg;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] < 0)
                neg.push_back(arr[i]);
            else
                pos.push_back(arr[i]);
        }
        int i = 0, j = 0, k = 0;
        while (i < pos.size() and j < neg.size())
        {
            arr[k++] = pos[i++];
            arr[k++] = neg[j++];
        }
        while (i < pos.size())
            arr[k++] = pos[i++];

        while (j < neg.size())
            arr[k++] = neg[j++];
    }
};

int main()
{
    Solution sol;

    int n = 9;
    int arr[n] = {9, 8, -2, -6, 3, -4, 5, 4, -3};

    sol.rearrange(arr, n);

    for (int i : arr)
        cout << arr[i] << " ";

    return 0;
}
