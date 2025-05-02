/* 19. Remove Nth Node From End of List (https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/):

Given the head of a linked list, 
remove the nth node from the end of the list and return its head.

Follow up: Could you do this in one pass? */

#include <bits/stdc++.h>
using namespace std;
// Definition for singly-linked list:
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Class for Utility methods:
class Utils : ListNode {
public:
    ListNode* convertArr2LL(vector<int>& v) {
        if(!v.size()) return NULL;
        ListNode* head = new ListNode(v[0]);
        ListNode* temp = head;
        for(int i=1; i<v.size(); i++) {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
        }
        return head;
    }
    void printLL(ListNode* head) {
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
    ListNode* removeNthFromEnd2Pass(ListNode* head, int n) { // 1 -> 4 -> n = 1
        if(!head->next and n == 1) {
            delete head;
            return NULL;
        }
        ListNode* temp = head;
        int size = 0;
        while(temp) {
            size++;
            temp = temp->next;
        }
        temp = head;
        if(size - n == 0) {
            head = head->next;
            delete temp;
            return head;
        }
        for(int i=1; i<size-n; i++) temp = temp->next;
        ListNode* toDlt = temp->next;
        temp->next = toDlt->next;
        delete toDlt;
        return head;
    }

    ListNode* removeNthFromEnd1Pass(ListNode* head, int n) {
        ListNode* l = head, *r = head;
        for(int i=0; i<n; i++) r = r->next;
        ListNode* temp;
        while(r) {
            r = r->next;
            temp = l;
            l = l->next;
        }
        if(l == head) head = head->next;
        else temp->next = l->next;
        delete l;
        return head;
    }
};
int main() {
    Utils utl;
    Solution sol;
    vector<int> v = {1,2,4,9,6};
    ListNode* head = utl.convertArr2LL(v);
    utl.printLL(head);
    head = sol.removeNthFromEnd1Pass(head, 5);
    utl.printLL(head);
 
    return 0;
}