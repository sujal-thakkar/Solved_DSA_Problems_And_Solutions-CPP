// You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n,
// representing the number of elements in nums1 and nums2 respectively.
// Merge nums1 and nums2 into a single array sorted in non-decreasing order

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> aux;
    int i = 0, j = 0;

    while (i < m and j < n)
    {
        if (nums1[i] < nums2[j])
            aux.push_back(nums1[i++]);

        else
            aux.push_back(nums2[j++]);
    }
    while (i < m)
        aux.push_back(nums1[i++]);

    while (j < n)
        aux.push_back(nums2[j++]);

    nums1 = aux;
}

int main()
{
    // your code goes here
    int m = 4, n = 6;
    vector<int> v1 = {1, 5, 5, 10, 0, 0, 0, 0, 0, 0};
    vector<int> v2 = {2, 3, 6, 6, 6, 9};

    merge(v1, m, v2, n);

    cout << "The merged sorted array is: ";
    for (int num : v1)
        cout << num << ' ';
    return 0;
}