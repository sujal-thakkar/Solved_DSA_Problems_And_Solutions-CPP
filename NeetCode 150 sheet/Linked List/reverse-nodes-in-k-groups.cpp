/* 25. Reverse Nodes in k-Group (https://leetcode.com/problems/reverse-nodes-in-k-group/description/):

    Given the head of a linked list, reverse the nodes of the list k at a time, 
    and return the modified list.

    k is a positive integer and is less than or equal to the length of the linked list. 
    If the number of nodes is not a multiple of k then left-out nodes, 
    in the end, should remain as it is.

    You may not alter the values in the list's nodes, 
    only nodes themselves may be changed. */

// Optimal sol. t.c.= O(n), s.c.= O(1)
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Utils : ListNode {
public:
    ListNode* convertArr2LL(vector<int>& v) {
        if(v.size()==0) return NULL;
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
private:
    ListNode* reverseLL(ListNode* head) {
        if(!head or !head->next) return head;
        ListNode* p = NULL, *c = head, *n = c->next;
        while(c) {
            c->next = p;
            p = c;
            c = n;
            if(!c) break;
            n = n->next;
        }
        return p;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head->next or k==1) return head;

        ListNode* dummyNode = new ListNode(-1);
        ListNode* dummyT = dummyNode;
        while(true) {
            ListNode* t1 = head;
            for(int i=1; i<k; i++) { // running this k times, for n/k times in total. so k * n/k = n times
                t1 = t1->next;
                if(!t1) return dummyNode->next;
            }
            ListNode* t2 = t1->next;
            t1->next = NULL;
            ListNode* reverseHead = reverseLL(head);
            dummyT->next = reverseHead;
            dummyT = head;
            if(!t2) return dummyNode->next;
            head->next = t2;
            head = t2;
        }
        return dummyNode->next;
    }
};

int main() {
    Utils utl;
    Solution sol;

    vector<int> v = {1,2,3,4,5};
    ListNode* head = utl.convertArr2LL(v);
    utl.printLL(head);
    int k = 2;
    ListNode* ans = sol.reverseKGroup(head, k);
    utl.printLL(ans);
 
    return 0;
}