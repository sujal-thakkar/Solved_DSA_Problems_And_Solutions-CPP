#include <bits/stdc++.h>
using namespace std;

int main() {
    // Priority Queue implementation in C++

    /* Operations: 
    1. push() - to insert an element
    2. pop() - to delete an element
    3. top() - to get the top element
    4. size() - to get the size of the queue
    5. empty() - to check if the queue is empty or not */

    // By default Priority Queues are implemented as Max Heap.
    priority_queue<int> pq; // Max Heap
    pq.push(1);
    pq.push(3);
    pq.push(4);
    pq.push(2);

    // while(!pq.empty()) {
    //     cout << pq.top() << " ";
    //     pq.pop();
    // }

    // to use pq as min heap, we have to change the syntax of declaration:
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(34);
    pq2.push(12);
    pq2.push(13);
    pq2.push(9);

    while(!pq2.empty()) {
        cout << pq2.top() << " ";
        pq2.pop();
    }
 
    return 0;
}