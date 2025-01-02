#include <bits/stdc++.h>
using namespace std;
int maxFrequency(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    int l = 0, r = 0;
    int total = 0;
    int result = 0;

    while (r < nums.size())
    {
        total += nums[r];

        while (nums[r] * (r - l + 1) > total + k)
        {
            total -= nums[l];
            l++;
        }

        result = max(result, r - l + 1);
        r++;
    }

    return result;
}

int main()
{
    int n;
    int k;
    cout << "n = ";
    cin >> n;
    cout << "k = ";
    cin >> k;
    vector<int> nums(n);
    for (int i : nums)
        cin >> nums[i];
    int result = maxFrequency(nums, k);
    cout << result;
    return 0;
}