// Given a binary array nums, return the maximum number of consecutive 1's in the array. O(N)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int n = nums.size();

        int count = 0, ans = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                count++;
            else
                count = 0;
            ans = max(ans, count);
        }

        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    Solution sol;
    int ans = sol.findMaxConsecutiveOnes(nums);
    cout << ans;
    return 0;
}