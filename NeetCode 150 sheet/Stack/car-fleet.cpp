/* 853. Car Fleet (https://leetcode.com/problems/car-fleet/description/):

There are n cars at given miles away from the starting mile 0, traveling to reach the mile target.

You are given two integer array position and speed, both of length n, 
where position[i] is the starting mile of the ith car and speed[i] is the speed of the ith car in miles per hour.

A car cannot pass another car, but it can catch up and then travel next to it at the speed of the slower car.

A car fleet is a car or cars driving next to each other. 
The speed of the car fleet is the minimum speed of any car in the fleet.

If a car catches up to a car fleet at the mile target, it will still be considered as part of the car fleet.

Return the number of car fleets that will arrive at the destination. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int carFleet(int target, vector<int>& position, vector<int>& speed) {
            int n=position.size();
            vector<pair<int, double>> v;
            for(int i=0; i<n; i++)
                v.push_back({position[i], speed[i] + 0.0});
            sort(v.begin(), v.end());
            stack<double> st;
            for(int i=n-1; i>=0; i--) {
                double t = (target - v[i].first) / v[i].second;
                if(st.empty()) st.push(t);
                else if(t > st.top()) st.push(t);
            }
            return st.size();
        }
    };
int main() {
    int target;
    cout << "Enter target: ";
    cin>>target;
    int n;
    cout << "Enter n: ";
    cin>>n;
    vector<int> position(n), speed(n);
    for(int i=0; i<n; i++)  {
        cout << "Enter position and speed for car no " << i << ": ";
        cin>>position[i]>>speed[i];
    }
    Solution sol;
    int ans = sol.carFleet(target, position, speed);
    cout << "Number of car fleets that will reach the target is: " << ans;
 
    return 0;
}