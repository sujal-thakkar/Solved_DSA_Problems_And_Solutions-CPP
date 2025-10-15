/* 621. Task Scheduler(https://leetcode.com/problems/task-scheduler/description/):

You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. 
Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, 
but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks. */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n == 0) return tasks.size();
        priority_queue<pair<int, char>> pq;
        queue<pair<pair<int, char>, int>> q;
        int time = 0;
        vector<pair<int, char>> v(26);
        for(int task : tasks) {
            v[task - 'A'].first++;
            v[task - 'A'].second = task;
        }
        for(pair<int, char> i : v) {
            if(i.first > 0) pq.push(i);
        }
        while(!pq.empty() or !q.empty()) {
            time++;
            if(!q.empty() and q.front().second == time) {
                pq.push(q.front().first);
                q.pop();
            }
            if(!pq.empty()) {
                pair<int, char> top = pq.top();
                top.first--;
                pq.pop();
                if(top.first > 0) {
                    q.push({top}, time + n + 1);
                }
            }
        }
        return time;
    }
};

int main() {
    
 
    return 0;
}