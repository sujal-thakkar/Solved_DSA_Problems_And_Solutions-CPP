/* 136. Single Number(https://leetcode.com/problems/single-number/description/):

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space */

//The most beeter approach using map data structure and improved algorithm than previous
//with time complexity of O((n logn) + (n/2 + 1)) or O(n) and space complexity -> O(n/2 + 1).
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        unordered_map<long long, int> mpp;

        for (int i = 0; i < n; i++) { //inserting elements in map costs O(n logn) for ordered map and n for unordered map
            mpp[nums[i]]++;           //where n is the size of nums and logn time  
        }                             //is required to insert every element. whereas only O(1) time is required for an unordered map in best case

        int ans = 0;

        for (const auto& it : mpp) { //to iterate through the map, it takes O(n)
            if (it.second == 1)      //and the size of our map will always be
                ans = it.first;      //n/2(bcz every element appears twice)
        }                            //for that, we create one key and extra + 1 key-value for the single ele.
        
        //so our t.c. boils down to O(n logn(for inserting) + n/2 + 1(for iterating)).
        //and s.c. will be O(n/2 + 1).
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
    int ans = sol.singleNumber(nums);
    cout << ans;

    return 0;
}
