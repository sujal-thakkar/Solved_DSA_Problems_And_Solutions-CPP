/* 239. Sliding Window Maximum (https://leetcode.com/problems/sliding-window-maximum/description/):

    You are given an array of integers nums, there is a sliding window of size k 
    which is moving from the very left of the array to the very right. 
    You can only see the k numbers in the window. 
    Each time the sliding window moves right by one position.

    Return the max sliding window. */

//t.c.= O(n), s.c.= O(n)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        deque<int> dq;

        int l=0, r=0;

        while(r < k) {
            if(dq.empty()) dq.push_back(r);
            else {
                while(!dq.empty() and nums[r] > nums[dq.back()]) dq.pop_back();
                dq.push_back(r);
            }
            r++;
        }

        ans.push_back(nums[dq.front()]);

        while(r < nums.size()) {
            if(dq.front() == l) dq.pop_front();
            l++;
            while(!dq.empty() and nums[r] > nums[dq.back()]) dq.pop_back();
            dq.push_back(r);
            ans.push_back(nums[dq.front()]);
            r++;
        }
        return ans;
    }
};
int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0; i<n; i++) cin >> nums[i];
    int k; 
    cout << "k: "
    cin >> k;
    Solution sol;
    vector<int> ans = sol.maxSlidingWindow(nums, k);
    cout << "ans: " << ans;
 
    return 0;
}