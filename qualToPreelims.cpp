#include <bits/stdc++.h>
using namespace std;

bool compare(int a, int b) {
    return a > b;
}
int qualifiedTeams(int arr[], int n, int k) {
    sort(arr, arr + n, compare);
    int target = arr[k - 1];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] >= target)
            ans++;
    }

    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int ans = qualifiedTeams(arr, n, k);
        cout << ans;
    }
    return 0;
}