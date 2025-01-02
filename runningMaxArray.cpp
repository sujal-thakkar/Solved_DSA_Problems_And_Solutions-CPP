// same as running sum array but it is about the maximum element from [a[0],a[0-1],a[0-2]....a[0-n]]
// with same algo as well...

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> runningSum(vector<int> &nums)
    {
        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            ans[i] = i > 0 ? max(ans[i - 1], nums[i]) : nums[i];
        }
        
        return ans;
    }
};

int main()
{
    Solution sol;

    vector<int> v1 = {5, 6, 2, 7, 8, 9, 15};

    vector<int> result = sol.runningSum(v1);

    for (int i : result)
        cout << i << " ";

    cout << endl;
    return 0;
}