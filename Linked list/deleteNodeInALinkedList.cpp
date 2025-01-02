/* 237. Delete Node in a Linked List(https://leetcode.com/problems/delete-node-in-a-linked-list/description/):

There is a singly-linked list head and we want to delete a node node in it.

You are given the node to be deleted node. You will not be given access to the first node of head.

All the values of the linked list are unique, 
and it is guaranteed that the given node node is not the last node in the linked list.

Delete the given node. Note that by deleting the node, we do not mean removing it from memory. We mean:

The value of the given node should not exist in the linked list.
The number of nodes in the linked list should decrease by one.
All the values before node should be in the same order.
All the values after node should be in the same order.
Custom testing:

For the input, you should provide the entire linked list head and the node to be given node. 
node should not be the last node of the list and should be an actual node in the list.
We will build the linked list and pass the node to your function.
The output will be the entire list after calling your function. */

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct Node {
    int val;
    Node *next;
    Node(int x) : val(x), next(NULL) {}
};
Node* LinkedList() {
    Node* head = new Node(4);
    Node* temp = head;
    int n = 4;
    int val = 12;
    for(int i=0; i<n; i++) {
        Node* newNode = new Node(val);
        val += 9;
        temp->next = newNode;
        temp = temp->next;
    }
    return head;
};
int sizeofLL(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while(temp) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
class Solution {
public:
    void deleteNode(Node *node) { // Input: head = [4,5,1,9], node = 5 | Output: [4,1,9] 
        node->val = node->next->val;
        Node* toDelete = node->next;
        node->next = node->next->next;
        delete toDelete;
    }
};
int main() {
    Node* head = LinkedList();
    Node* temp = head; // [4 12 21 30 39]
    Solution sol; 
    // sol.deleteNode(temp->next->next->next);
    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "Size of LL: " << sizeofLL(head);

    return 0;
}