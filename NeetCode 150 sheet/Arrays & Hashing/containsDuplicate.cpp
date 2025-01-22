/* 217. Contains Duplicate (https://leetcode.com/problems/contains-duplicate/description/):

Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct. */

// t.c.- O(n), s.c.- O(n)
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> s;
        for (int i : nums) {
            if (s.find(i) != s.end())
                return true;
            s.insert(i);
        }
        return false;
    }
};
int main() {

    return 0;
}