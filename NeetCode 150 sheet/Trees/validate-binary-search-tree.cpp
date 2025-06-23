/* 98. Validate Binary Search Tree (https://leetcode.com/problems/validate-binary-search-tree/description/):

Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees. */

#include <bits/stdc++.h>
using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left, *right;

    TreeNode(int val) {
        this->val = val;
        left = right = NULL;
    }
};

TreeNode* insert(TreeNode* root, int val) {
    if(!root) return new TreeNode(val);

    if(val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}

TreeNode* createBST(vector<int> v) {
    TreeNode* root = NULL;

    for(int val : v) {
        root = insert(root, val);
    }

    return root;
}

void printBST(TreeNode* root) {     
    if(!root) return;
    printBST(root->left);
    cout << root->val << " ";
    printBST(root->right);
}

class Solution {
public:
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if(!root) return true;
        if(min and root->val <= min->val) return false;
        if(max and root->val >= max->val) return false;
        return 
            helper(root->left, min, root) and
            helper(root->right, root, max);
    }
    bool isValidBST(TreeNode* root) {
        return helper(root, NULL, NULL);
    }
};

int main() {
    Solution sol;

    vector<int> v = {5,1,4,NULL,NULL,3,6};
    TreeNode* root = createBST(v);
    printBST(root); cout << endl;
    cout << sol.isValidBST(root);
 
    return 0;
}