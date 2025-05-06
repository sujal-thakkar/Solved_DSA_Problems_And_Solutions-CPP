/* 23. Merge k Sorted Lists (https://leetcode.com/problems/merge-k-sorted-lists/description/):

    You are given an array of k linked-lists lists, 
    each linked-list is sorted in ascending order.

    Merge all the linked-lists into one sorted linked-list and return it. */

// t.c.= O(n(log k)), where n is the total size of the array and k is the size of every list. s.c.= O(k), at-max pq holds k nodes inside.
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

class Utils {
public:
    vector<ListNode*> createArrayOfLL(vector<vector<int>>& v) { // {{1,4,5},{1,3,4},{2,6}}
        if(v.size()==0) return {NULL};
        vector<ListNode*> lists;
        for(int i=0; i<v.size(); i++) {
            if(v[i].size()==0) {
                lists.push_back(NULL);
                continue;
            }
            ListNode* head = new ListNode(v[i][0]);
            ListNode* temp = head;
            for(int j=1; j<v[i].size(); j++) {
                ListNode* newNode = new ListNode(v[i][j]);
                temp->next = newNode;
                temp = temp->next;
            }
            lists.push_back(head);
        }
        return lists;
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;

        priority_queue<
            pair<int, ListNode*>,
            vector<pair<int, ListNode*>>,
            greater<pair<int, ListNode*>>
        > pq;

        for(int i=0; i<lists.size(); i++) {
            if(lists[i]) pq.push({lists[i]->val, lists[i]});
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;

        while(!pq.empty()) {
            temp->next = pq.top().second;
            temp = temp->next;
            pq.pop();
            if(temp->next) pq.push({temp->next->val, temp->next});
        }
        return dummy->next;
    }
};
int main() {
    Utils utl;
    Solution sol;

    vector<vector<int>> v = {{1,4,5},{1,3,4},{2,6}};
    vector<vector<int>> v2 = {{},{1,3,4},{2,6}};
    vector<vector<int>> v3 = {{},{},{}};

    vector<ListNode*> lists = utl.createArrayOfLL(v2);
    ListNode* ans = sol.mergeKLists(lists);
    utl.printLL(ans);
 
    return 0;
}