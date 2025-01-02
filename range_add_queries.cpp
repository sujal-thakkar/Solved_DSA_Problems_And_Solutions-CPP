// (https://playground.learnyard.com/compiler/cly5yy5zb05rzyp0197vniam7):
// Given an array of all 0s, then 'Q' queries are given:-

// 1) each query has 'l','r', and 1. Meaning 1 should be added to arr[l],arr[l+1].....arr[r];

// 2) Print the final state of the array after all the queries are processed -->

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, Q;
    cin >> N >> Q;

    vector<int> arr(N, 0);

    for (int i = 0; i < Q; i++)
    {
        int l, r;
        cin >> l >> r;

        arr[l] += 1;

        if (arr[r + 1] < N)
            arr[r + 1] -= 1;
    }

    for (int i = 1; i < N; i++)
        arr[i] += arr[i - 1];

    for (int num : arr)
        cout << num << " ";

    return 0;
}