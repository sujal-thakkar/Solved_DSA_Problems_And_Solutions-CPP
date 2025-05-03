/* 2. Add Two Numbers (https://leetcode.com/problems/add-two-numbers/description/):

You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, 
except the number 0 itself. */

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
class Utils {
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
    vector<int> convertLL2Arr(ListNode* head) {
        vector<int> result;
        while (head) {
            result.push_back(head->val);
            head = head->next;
        }
        return result;
    }
    bool compareVecs(vector<int>& a, vector<int>& b) {
        if(a.size() != b.size()) return false;
        for(int i=0; i<a.size(); i++) if(a[i] != b[i]) return false;
        return true;
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
    ListNode* add(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* t1 = l1, *t2 = l2;
        ListNode* dummyHead = new ListNode(-1);
        ListNode* t3 = dummyHead;
        while(t1 and t2) {
            int num = t1->val + t2-> val + carry;
            int keep = num % 10;
            t3->next = new ListNode(keep);;
            t3 = t3->next;
            carry = num / 10;
            t1 = t1->next;
            t2 = t2->next;
        }
        while(t1) {
            int num = t1->val + carry;
            int keep = num % 10;
            t3->next = new ListNode(keep);
            t3 = t3->next;
            carry = num / 10;
            t1 = t1->next;
        }
        while(t2) {
            int num = t2->val + carry;
            int keep = num % 10;
            t3->next = new ListNode(keep);
            t3 = t3->next;
            carry = num / 10;
            t2 = t2->next;
        }
        if(carry) t3->next = new ListNode(carry);
        return dummyHead->next;
    }
public:
    // t.c.= O(max(m, n)), s.c.= O(max(m, n))
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1->next and !l2->next and l1->val == 0 and l2->val == 0) return l1;

        return add(l1, l2);
    }
};

int main() {
    Utils utl;
    Solution sol;

    vector<int> l1v = {9,9,9,9,9,9,9}, l2v = {9,9,9,9}, exp = {8,9,9,9,0,0,0,1};
    ListNode* l1 = utl.convertArr2LL(l1v), *l2 = utl.convertArr2LL(l2v);
    ListNode* expect = utl.convertArr2LL(exp);
    ListNode* ans = sol.addTwoNumbers(l1, l2);
    utl.printLL(ans);
    vector<int> expectVec = utl.convertLL2Arr(expect), ansVec = utl.convertLL2Arr(ans);
    cout << utl.compareVecs(expectVec, ansVec);
 
    return 0;
}