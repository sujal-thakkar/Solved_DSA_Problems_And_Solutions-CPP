// when we want our node to position at bottom and the children of the node is smaller than the node then we perform down-sift.
// we first check if the children of the node is smaller than it or not, to start the algo.
// if any of the children is smaller than the node's value, we swap places with it. and if both the children are smaller, then we
// swap places with the smaller one.
// the formula to find the left and right child of the node is: left = (i * 2) + 1; and right = (i * 2) + 2; where i = node's index.

#include <bits/stdc++.h>
using namespace std;

void _siftdown(vector<int>&v, int i) {
    int left = (i * 2) + 1;
    int right = (i * 2) + 2;
    while((left < v.size() and v[i] > v[left])
        or (right < v.size() and v[i] > v[right]))
    {
        int smaller = (right >= v.size() or v[left] < v[right])? left : right;
        swap(v[i], v[smaller]);
        i = smaller;
        left = (i * 2) + 1;
        right = (i * 2) + 2;
    }
}

int main() {
    
 
    return 0;
}