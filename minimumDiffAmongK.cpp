#include <bits/stdc++.h>
using namespace std;

int minimumDiff(int arr[], int n, int k)
{
    sort(arr, arr + n);
    int ans = INT_MAX;
    for (int st = 0, en = k - 1; en < n; st++, en++)
    {
        ans = min(ans, arr[en] - arr[st]);
    }

    return ans;
}
int main()
{
    int n;
    cin >> n;
    int k;
    cin >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = minimumDiff(arr, n, k);
    cout << ans;
    return 0;
}
