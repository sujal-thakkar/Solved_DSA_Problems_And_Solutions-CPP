#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &nums) {
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int flag = 0;
            if (nums[j] > nums[i + 1]) {
                int temp = nums[i + 1];
                nums[i + 1] = nums[j];
                nums[j] = temp;
                flag = 1;
            }
            if (flag == 1)
                break;
        }
    }

    int k = 0;

    for (int i = 0; i < n; i++) {
        int flag = 0;
        if (nums[i + 1] < nums[i]) {
            k = i + 1;
            flag = 1;
        }
        if (flag == 1)
            break;
    }

    return k;
}
int main() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int ans = removeDuplicates(nums);
    cout << ans;
    return 0;
}