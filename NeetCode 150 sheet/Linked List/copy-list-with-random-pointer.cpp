/* 138. Copy List with Random Pointer (https://leetcode.com/problems/copy-list-with-random-pointer/description/):

A linked list of length n is given such that each node contains 
an additional random pointer, which could point to any node in the list, or null.

Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, 
where each new node has its value set to the value of its corresponding original node. 
Both the next and random pointer of the new nodes should point to new nodes in the copied list 
such that the pointers in the original list and copied list represent the same list state. 
None of the pointers in the new list should point to nodes in the original list.

For example, if there are two nodes X and Y in the original list, where X.random --> Y, 
then for the corresponding two nodes x and y in the copied list, x.random --> y.

Return the head of the copied linked list.

The linked list is represented in the input/output as a list of n nodes. 
Each node is represented as a pair of [val, random_index] where:

val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, 
or null if it does not point to any node.
Your code will only be given the head of the original linked list. */

#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

// Class for Utility methods:
class Utils {
public:
    Node* convertArr2LL(vector<pair<int,int>>& v) {
        if(!v.size()) return NULL;
        vector<Node*> nodes;
        Node* head = new Node(v[0].first);
        nodes.push_back(head);
        Node* temp = head;
        for(int i=1; i<v.size(); i++) {
            temp->next = new Node(v[i].first);
            temp = temp->next;
            nodes.push_back(temp);
        }
        temp = head;
        for(int i=0; i<v.size(); i++) {
            if(v[i].second != -1) temp->random = nodes[v[i].second];
            temp = temp->next;
        }
        return head;
    }
    void printLL(Node* head) {
        if(!head){
            cout << "NULL\n";
            return;
        }
        while(head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

class Solution {
public:
    // t.c.= O(2n), s.c.= O(2n) (extra space is taken beside the space required to return the answer)
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m;
        Node* temp = head;
        while(temp) {
            m[temp] = new Node(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp) {
            m[temp]->next = m[temp->next];
            m[temp]->random = m[temp->random];
            temp = temp->next;
        }
        return m[head];
    }

    // t.c.= O(3n), s.c.= O(n) (no extra space is taken beside the space to return the answer, it can't be reduced)
    Node* copyRandomListOptimal(Node* head) {
        if(!head) return NULL;
        Node* temp = head;
        while(temp) {
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        temp = head;
        while(temp) {
            temp->next->random = !temp->random? NULL : temp->random->next;
            temp = temp->next->next;
        }
        temp = head;
        /* Node* copyHead = temp->next;
        Node* temp2 = copyHead;
        while(temp) {
            temp->next = temp2->next;
            temp = temp->next;
            if(temp) temp2->next = temp->next;
            temp2 = temp2->next;
        }
        return copyHead; */
        // OR,
        Node* dummyHead = new Node(-1);
        Node* temp2 = dummyHead;
        while(temp) {
            temp2->next = temp->next;
            temp2 = temp2->next;
            temp->next = temp2->next;
            temp = temp->next;
        }
        return dummyHead->next;
    }
};
int main() {
    Utils utl;
    Solution sol;
    vector<pair<int,int>> v = {{5,-1}, {9,3}, {12,5}, {8,-1}, {6,1}, {4,2}};
    Node* head = utl.convertArr2LL(v);
    Node* head2 = sol.copyRandomListOptimal(head);
    utl.printLL(head2);
 
    return 0;
}