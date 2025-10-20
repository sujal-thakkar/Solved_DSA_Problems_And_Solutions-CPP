/* 295. Find Median from Data Stream (https://leetcode.com/problems/find-median-from-data-stream/description/):
The median is the middle value in an ordered integer list. If the size of the list is even, 
there is no middle value, and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted. */

#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
public:
    priority_queue<int> smaller;
    priority_queue<int, vector<int>, greater<int>> greater;
    MedianFinder() {}
    
    void addNum(int num) {
        if(smaller.empty() or num <= smaller.top()) smaller.push(num);
        else greater.push(num);

        //rebalancing
        if(smaller.size() > greater.size()+1) {
            greater.push(smaller.top()); 
            smaller.pop();
        }
            
        // we always keep the smaller pq 1 size larger, never the larger pq.
        else if(greater.size() > smaller.size()) {
            smaller.push(greater.top());
            greater.pop();
        }
    }
    
    double findMedian() {
        if(smaller.size() > larger.size()) return smaller.top();
        return (smaller.top() + larger.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

int main() {
    std::cout << "Hello world!" << std::endl;
    return 0;
}