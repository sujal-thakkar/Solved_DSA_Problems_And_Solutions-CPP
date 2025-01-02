#include <bits/stdc++.h>
using namespace std;

int minimumDifference(int arr[], int n)
{
    sort(arr, arr + n);
    int ans = INT_MAX;
    for (int i = 0; i <= n - 2; i++)
    {
        int curmin = abs(arr[i] - arr[i + 1]);
        ans = min(ans, curmin);
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = minimumDifference(arr, n);
    cout << ans;

    return 0;
}