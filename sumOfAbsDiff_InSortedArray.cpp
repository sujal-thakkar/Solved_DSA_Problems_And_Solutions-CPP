#include <bits/stdc++.h>
using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int> &nums, int n) {
    vector<int> ans;

    for (int i = 0; i < n; i++) {
        int add = 0;
        for (int j = 0; j < n; j++) {
            add += abs(nums[i] - nums[j]); //[1 4 6 8 10]
        }
        ans.push_back(add);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";

    return ans;
}
//*Brute Force method
// Time Complexity - O(N^2)
// Space Complexity - O(N)
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    getSumAbsoluteDifferences(nums, n);

    return 0;
}