/* 973. K Closest Points to Origin (https://leetcode.com/problems/k-closest-points-to-origin/description/):

    Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

    The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

    You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in). */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distance(vector<int>& v) {
        int x1 = 0, x2 = v[0];
        int y1 = 0, y2 = v[1];
        return ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2));
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for(vector<int> point : points) {
            int dist = distance(point);
            if(pq.size() < k) pq.push({dist, point});
            else if(dist < pq.top().first) {
                pq.pop();
                pq.push({dist, point});
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};

int main() {
    
 
    return 0;
}