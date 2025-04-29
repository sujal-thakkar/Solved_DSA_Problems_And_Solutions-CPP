/* 21. Merge Two Sorted Lists (https://leetcode.com/problems/merge-two-sorted-lists/description/):

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. 
The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list. */

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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       if(!list1) return list2;
       if(!list2) return list1;
       
       ListNode* dummyNode = new ListNode(-1);
       ListNode* t1 = list1, *t2 = list2, *temp = dummyNode;

        while(t1 and t2) {
            if(t1->val <= t2->val) {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            }
            else {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }
        if(t1) temp->next = t1;
        if(t2) temp->next = t2;

        return dummyNode->next;
    }
};
int main() {
    Solution sol;
    Utils utl;
    vector<int> v1 = {5, 8, 12, 16};
    vector<int> v2 = {9,11,38,42};
    ListNode* list1 = utl.convertArr2LL(v1);
    ListNode* list2 = utl.convertArr2LL(v2);
    utl.printLL(list1);
    utl.printLL(list2);
    ListNode* mergedList = sol.mergeTwoLists(list1, list2);
    utl.printLL(mergedList);
 
    return 0;
}