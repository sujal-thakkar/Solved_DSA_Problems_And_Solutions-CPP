/* 124. Binary Tree Maximum Path Sum (https://leetcode.com/problems/binary-tree-maximum-path-sum/description/):

A path in a binary tree is a sequence of nodes where each pair of adjacent nodes 
in the sequence has an edge connecting them. A node can only appear in the sequence at most once. 
Note that the path does not need to pass through the root.

The path sum of a path is the sum of the node's values in the path.

Given the root of a binary tree, return the maximum path sum of any non-empty path. */

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
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
    int helper(TreeNode* root, int& maxi) {
        if(!root) return 0;
        int leftSum = max(0, helper(root->left, maxi));
        int rightSum = max(0, helper(root->right, maxi));
        maxi = max(maxi, root->val + leftSum + rightSum);
        return root->val + max(leftSum, rightSum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root, maxi);
        return maxi;
    }
};

int main() {
    Solution sol;
    TreeNode bt;

    vector<int> v = {-10,9,20,NULL,NULL,15,7};
    TreeNode* root = bt.createTree(v);
    int ans = sol.maxPathSum(root);
    cout << ans;
 
    return 0;
}