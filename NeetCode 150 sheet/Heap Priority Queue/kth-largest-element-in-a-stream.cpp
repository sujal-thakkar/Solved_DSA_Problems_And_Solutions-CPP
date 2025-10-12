/* 703. Kth Largest Element in a Stream (https://leetcode.com/problems/kth-largest-element-in-a-stream/description/):

    You are part of a university admissions office and need to keep track of the kth highest test score from applicants in real-time. This helps to determine cut-off marks for interviews and admissions dynamically as new applicants submit their scores.

    You are tasked to implement a class which, for a given integer k, maintains a stream of test scores and continuously returns the kth highest test score after a new score has been submitted. More specifically, we are looking for the kth highest score in the sorted list of all scores.

    Implement the KthLargest class:

    KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of test scores nums.
    int add(int val) Adds a new test score val to the stream and returns the element representing the kth largest element in the pool of test scores so far. */

#include <bits/stdc++.h>
using namespace std;

class KthLargestUsingHeap {  // Heap implementation
public:
    int k;
    vector<int> v;
    KthLargestUsingHeap(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) add(num);
    }

    void _siftup(vector<int>& v, int i) {
        int parent = (i - 1) / 2;
        while(i != 0 and v[i] < v[parent]) {
            swap(v[i], v[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void _siftdown(vector<int>& v, int i) {
        int left = (i * 2) + 1;
        int right = (i * 2) + 2;
        while((left < v.size() and v[i] > v[left]) or (right < v.size() and v[i] > v[right])) {
            int smallest = (right >= v.size() or v[left] < v[right])? left : right;
            swap(v[i], v[smallest]);
            i = smallest;
            left = (i * 2) + 1;
            right = (i * 2) + 2; 
        }
    }
    
    int add(int val) {
        if(v.size() < k) {
            v.push_back(val);
            _siftup(v, v.size()-1);
        }
        else if(val > v[0]) {
            v[0] = val;
            _siftdown(v, 0);
        }
        return v[0];
    }
};

class KthLargestUsingPQ {  // Priority Queue implementation
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    KthLargestUsingPQ(int k, vector<int>& nums) {
        this->k = k;
        for(int num : nums) add(num);
    }
    
    int add(int val) {
        if(pq.size() < k) pq.push(val);
        else if(val > pq.top()) {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */

int main() {


    return 0;
}