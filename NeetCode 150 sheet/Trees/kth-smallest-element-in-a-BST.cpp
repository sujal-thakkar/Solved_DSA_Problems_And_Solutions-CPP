/* 230. Kth Smallest Element in a BST (https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/):

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) 
of all the values of the Nodes in the tree. */


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

bool searchBST(TreeNode* root, int tar) {
    if(!root) return false;
    if(root->val == tar) return true;
    else if(root->val > tar) searchBST(root->left, tar);
    else searchBST(root->right, tar);
}

class Solution {
public:
    int ans;
    int idx = 0;
    void helper(TreeNode* root, int k) {
        if(!root or idx >= k) return;
        helper(root->left, k);
        idx++;
        if(idx == k) {
            ans = idx;
            return;
        }
        helper(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        helper(root, k);
        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> v = {5,3,6,2,4,NULL,NULL,1};
    TreeNode* root = createBST(v);
    printBST(root); cout << endl;
    cout << sol.kthSmallest(root, 3);
 
    return 0;
}