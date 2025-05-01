/* 143. Reorder List (https://leetcode.com/problems/reorder-list/description/):

You are given the head of a singly linked-list. The list can be represented as:
L0 → L1 → … → Ln - 1 → Ln

Reorder the list to be on the following form:
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …

You may not modify the values in the list's nodes. 
Only nodes themselves may be changed. */

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
private:
    ListNode* reverseLL(ListNode* head) {
        ListNode* p = nullptr, *c = head, *n = c->next;
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
    // t.c.= O(n), s.c.= O(n)
    void reorderList(ListNode* head) { 
        unordered_map<int, ListNode*> m;
        ListNode* temp = head;
        int size = 0;
        while(temp) {
            m[size] = temp;
            size++;
            temp = temp->next;
        }
        if(size <= 2) return;
        int l=0, r=size-1;
        while(l < r) {
            m[l]->next = m[r];
            l++;
            if(l == r) break;
            m[r]->next = m[l];
            r--;
        }
        m[r]->next = nullptr;
    }

    // t.c.= O(n), s.c.= O(1)
    void reorderListOptimal(ListNode* head) { // 1 -> 2 -> 3 <- 4 <- 5 | 1 -> 5 -> 2 -> 4 -> 3
        int size = 0;
        ListNode* temp = head;
        while(temp) {
            size++;
            temp = temp->next;
        }
        if(size <= 2) return;
        temp = head;
        for(int i=0; i<size/2; i++) temp = temp->next;
        temp = reverseLL(temp);
        ListNode* l = head, *r = temp;
        while(l != r) {
            ListNode* l_next = l->next;
            l->next = r;
            l = l_next;
            if(l == r) return;
            ListNode* r_next = r->next;
            r->next = l;
            r = r_next;
        }
    }

    // t.c.= O(n), s.c.= O(1)
    void reorderListOptimal2(ListNode* head) { // 1 -> 2 -> NULL <- 3 <- 4 <- 5 | 1 -> 5 -> 2 -> 4 -> 3
        int size = 0;
        ListNode* temp = head;
        while(temp) {
            size++;
            temp = temp->next;
        }
        if(size <= 2) return;
        temp = head;
        for(int i=1; i<size/2; i++) temp = temp->next;
        ListNode* secondHalf = temp->next;
        temp->next = nullptr;
        secondHalf = reverseLL(secondHalf);
        ListNode* l = head, *r = secondHalf;
        while(r) {
            ListNode* l_next = l->next;
            l->next = r;
            l = l_next;
            if(l == NULL) return;
            ListNode* r_next = r->next;
            r->next = l;
            r = r_next;
        }
    }
};

int main() {
    Utils utl;
    Solution sol;
    vector<int> v = {5,9,6,8,2,1,4};
    ListNode* head = utl.convertArr2LL(v);
    utl.printLL(head);
    sol.reorderListOptimal(head);
    utl.printLL(head);
 
    return 0;
}