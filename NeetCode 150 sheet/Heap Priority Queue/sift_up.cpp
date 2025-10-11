// when the node which we want to position above, then we perform up-sift. where we check if the parent node's val is
// smaller, if it's not then we swipe it with the node, and bring the node at the top.
// the formula to find the parent node of the node is: (i - 1) / 2; where i is the index of the node.

#include <bits/stdc++.h>
using namespace std;

void _siftup(vector<int>& v, int i) { // where v is the array of represented heap, and i is the index of node to be inserted
    int parent = (i - 1) / 2;
    while(i != 0 and v[i] < v[parent]) {
        swap(v[i], v[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

int main() {
    
 
    return 0;
}