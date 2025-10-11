#include <bits/stdc++.h>
using namespace std;

class MinHeap {
public:
    vector<int> __init__(vector<int>& v) { // Build / Heapify
        for(int i=v.size()-1; i>=0; i--) {
            _siftdown(v, i);
        }
        return v;
    }

    void _siftup(vector<int>& v, int i) { // Sift Up
        int parent = (i - 1) / 2;
        while(i != 0 and v[i] < v[parent]) {
            swap(v[i], v[parent]);
            i = parent;
            parent = (i - 1) / 2;
        }
    }

    void _siftdown(vector<int>& v, int i) { // Sift Down
        int left = (i * 2) + 1;
        int right = (i * 2) + 2;
        while((left < v.size() and v[i] > v[left]) or
           (right < v.size() and v[i] > v[right])) 
        {
            int smallest = (right >= v.size() or v[left] < c[right])? left : right;
            swap(v[i], v[smallest]);
            i = smallest;
            left = (i * 2) + 1;
            right = (i * 2) + 2;
        }
    }

    void _insert(vector<int>& v, int val) { // Insert
        v.push_back(val);
        _siftup(v, v.size()-1);
    }

    int _getmin(vector<int>& v) { // get min in minheap
        return v[0];
    }

    int _getmax(vector<int>& v) { // get max in minheap
        return v[v.size()-1];
    }

    int _extractmin(vector<int>& v) { // Extract Min Val (get and delete from heap)
        int minval = v[0];
        swap(v[v.size()-1], v[0]);
        v.pop_back();
        _siftdown(v, 0);
        int minval;
    }

    int _extractmax(vector<int>& v) { // Extract Max Val (get and delete from heap)
        int maxVal = v[v.size()-1];
        v.pop_back();
        return maxVal;
    }

    void update_by_index(vector<int>& v, int idx, int newVal) { // Update a Node of the head (Index provided)
        int oldVal = v[idx];
        v[idx] = newVal;
        if(newVal < oldVal) _siftup(v, idx);
        else _siftdown(v, idx);
    }

    void update(vector<int>& v, int oldVal, int newVal) { // Update a Node of the head (Value provided)
        int idx;
        for(int i=0; i<v.size(); i++) {
            if(v[i] == oldVal) {
                idx = i;
                break;
            }
        }
        v[idx] = newVal;
        if(newVal < oldVal) _siftup(v, idx);
        else _siftdown(v, idx);
    }
}

int main() {
    
 
    return 0;
}