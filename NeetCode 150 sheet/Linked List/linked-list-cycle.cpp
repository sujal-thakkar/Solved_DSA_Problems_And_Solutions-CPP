/* 141. Linked List Cycle (https://leetcode.com/problems/linked-list-cycle/description/):

Given head, the head of a linked list, 
determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list 
that can be reached again by continuously following the next pointer. 
Internally, pos is used to denote the index of the node 
that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false. */

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(NULL) {}
    ListNode(int x) : val(x), next(NULL) {}
};

// Class for Utility methods
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

    ListNode* convertArr2LLCycle(vector<int>& v, int pos) { // 1 2 6 8 6 22
        if(!v.size()) return NULL;
        ListNode* head = new ListNode(v[0]);
        ListNode* temp = head;
        ListNode* loopingNode;
        if(pos == 0) loopingNode = head;
        for(int i=1; i<v.size(); i++) {
            temp->next = new ListNode(v[i]);
            temp = temp->next;
            if(i == pos) loopingNode = temp;
        }
        if(pos != -1) temp->next = loopingNode;
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
    bool hasCycle(ListNode *head) {
        if(!head or !head->next) return false;

        ListNode* slow = head, *fast = head;
        while(fast and fast->next) {
            fast = fast->next->next;
            if(fast == slow) return true;
            slow = slow->next;
        }
        return false;
    }
};
int main() {
    Utils utl;
    Solution sol;

    vector<int> v = {4};
    int pos = -1;
    ListNode* head = utl.convertArr2LLCycle(v, pos);
    ListNode* head2 = utl.convertArr2LL(v);
    cout << sol.hasCycle(head);
 
    return 0;
}