#include <bits/stdc++.h>
using namespace std;

vector<int> sumOfAbsoluteDifference(vector<int> &nums, int n) {
    vector<int> pref(n), suf(n);
    for (int i = 0; i < n; i++) {
        pref[i] = (i == 0) ? nums[i] : pref[i - 1] + nums[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = (i == n - 1) ? nums[i] : suf[i + 1] + nums[i];
    }

    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int prefSum = (i == 0) ? 0 : pref[i - 1];
        int sufSum = (i == n - 1) ? 0 : suf[i + 1];

        int leftSum = nums[i] * i - prefSum;
        int rightSum = sufSum - nums[i] * (n - 1 - i);

        ans[i] = leftSum + rightSum;
    }
    for (int i : ans)
        cout << i << " ";

    return ans;
}
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sumOfAbsoluteDifference(nums, n);

    return 0;
}