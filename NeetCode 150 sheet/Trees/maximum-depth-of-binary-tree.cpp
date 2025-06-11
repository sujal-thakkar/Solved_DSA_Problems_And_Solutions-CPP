/* 104. Maximum Depth of Binary Tree (https://leetcode.com/problems/maximum-depth-of-binary-tree/description/):

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path 
from the root node down to the farthest leaf node. */

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
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        return max(leftDepth, rightDepth) + 1;
    }
};

int main() {
    TreeNode bt;
    Solution sol;

    vector<int> v = {3,9,20,NULL,NULL,15,7};

    TreeNode* root = bt.createTree(v);

    int ans = sol.maxDepth(root);

    cout << ans;
 
    return 0;
}