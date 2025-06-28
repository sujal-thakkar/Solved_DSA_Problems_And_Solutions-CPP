/* 662. Maximum Width of Binary Tree (https://leetcode.com/problems/maximum-width-of-binary-tree/description/):

Given the root of a binary tree, return the maximum width of the given tree.

The maximum width of a tree is the maximum width among all levels.

The width of one level is defined as the length between the end-nodes 
(the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes 
that would be present in a complete binary tree extending down to that level are also 
counted into the length calculation.

It is guaranteed that the answer will in the range of a 32-bit signed integer. */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    // Definition for a binary tree node.
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    // construct tree using level order, iterative algorithm
    TreeNode* createTree(vector<int> v) { 
        if(v.empty()) return NULL;

        TreeNode* root = new TreeNode(v[0]);
        queue<TreeNode*> q;
        q.push(root);

        int i = 1;
        while(!q.empty() and i < v.size()) {
            TreeNode* cur = q.front();
            q.pop();

            if(i < v.size()) {
                cur->left = new TreeNode(v[i]);
                q.push(cur->left);
                i++;
            }

            if(i < v.size()) {
                cur->right = new TreeNode(v[i]);
                q.push(cur->right);
                i++;
            }
        }

        return root;
    }

    // Print binary tree
    void printTree(TreeNode* root) {
        if(!root) return;
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty()) {
            int sz = q.size();
            int min = q.front().second;
            int first, last;
            for(int i=0; i<sz; i++) {
                long long curIdx = q.front().second - min;
                TreeNode* curNode = q.front().first;
                q.pop();
                if(i==0) first = curIdx;
                if(i==sz-1) last = curIdx;
                if(curNode->left) q.push({curNode->left, 2*curIdx+1});
                if(curNode->right) q.push({curNode->right, 2*curIdx+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    TreeNode bt;

    vector<int> v = {1,3,2,5,NULL,NULL,9,6,NULL,7};
    TreeNode* root = bt.createTree(v);
    int ans = sol.widthOfBinaryTree(root);
    cout << ans;
 
    return 0;
}