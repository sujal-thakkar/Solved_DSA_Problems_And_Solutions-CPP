// In order to insert a new node in our binary heap, we can do it in O(log n), let's se how:

#include <iostream>

void _siftup(vector<int>& v, int i) {
    int parent = (i - 1) / 2;
    while(i != 0 and v[parent] > v[i]) {
        swap(v[i], v[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

vector<int> _insert(vector<int>& v, int val) {
    v.push_back(val);
    _siftup(v, v.size()-1);
    return v;
}

int main() {

    
    return 0;
}W