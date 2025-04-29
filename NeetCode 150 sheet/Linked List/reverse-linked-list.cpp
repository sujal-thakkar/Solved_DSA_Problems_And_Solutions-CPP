/* 206. Reverse Linked List (https://leetcode.com/problems/reverse-linked-list/description/):

    Given the head of a singly linked list, reverse the list, and 
    return the reversed list. */

#include <bits/stdc++.h>
using namespace std;

//  * Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Class for Utility methods
class Utils : ListNode {
public:
    ListNode* convertArr2LL(vector<int>& v) {
        ListNode* head = new ListNode(v[0]);
        ListNode* temp = head;
        for(int i=1; i<v.size(); i++) {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return head;
    }
    void printLL(ListNode* head) {
        while(head) {
            cout << head->val << " ";
            head = head->next;
        }
        cout << endl;
    }
};

class Solution {
public:
    ListNode* reverseListIterative(ListNode* head) { // iterative:
        if(!head or !head->next) return head;
        ListNode* p = head, *c = p->next, *n = c->next;
        while(c) {
            c->next = p;
            if(p == head) p->next = nullptr;
            p = c;
            c = n;
            if(!c) break;
            n = n->next;
        }
        return p;
    }

    ListNode* reverseListRecursive(ListNode* head) { // recursive
        if(!head or !head->next) return head;

        ListNode* newHead = reverseListRecursive(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = nullptr;
        return newHead;
    }
};

int main() {
    Utils utl;
    Solution sol;

    vector<int> v = {4,9,8,3,6};
    ListNode* head = utl.convertArr2LL(v);
    utl.printLL(head);
    head = sol.reverseListRecursive(head);
    utl.printLL(head);
 
    return 0;
}