#include <bits/stdc++.h>
using namespace std;

long long totalCost(vector<int> &length, int n) {
    sort(length.begin(), length.end());
    int target = length[n / 2];
    long long count = 0;
    for (int i = 0; i < n; i++) {
        int x = 0;
        x = abs(length[i] - target);
        count += x;
    }

    return count;
}
int main() {
    int n;
    cin >> n;
    vector<int> length(n);
    for (int i = 0; i < n; i++)
        cin >> length[i];
    long long ans = totalCost(length, n);
    cout << ans;
    return 0;
}