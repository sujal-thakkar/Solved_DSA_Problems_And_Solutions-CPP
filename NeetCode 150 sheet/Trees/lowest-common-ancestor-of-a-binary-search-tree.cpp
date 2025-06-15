/* 235. Lowest Common Ancestor of a Binary Search Tree (https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/description/):

Given a binary search tree (BST), find the lowest common ancestor (LCA) node 
of two given nodes in the BST.

According to the definition of LCA on Wikipedia
(https://en.wikipedia.org/wiki/Lowest_common_ancestor): 
“The lowest common ancestor is defined between two nodes p and q as the lowest node 
in T that has both p and q as descendants (where we allow a node to be a descendant of itself).” */

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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(p->val == root->val or 
           q->val == root->val or 
           p->val < root->val and q->val > root->val or
           p->val > root->val and q->val < root->val)
        return root;

        if(p->val < root->val and q->val < root->val) return lowestCommonAncestor(root->left, p, q);
        else return lowestCommonAncestor(root->right, p, q);
    }
};

int main() {
    Solution sol;
    vector<int> v = {6,2,8,0,4,7,9,3,5};
    TreeNode* bst = createBST(v);
    printBST(bst); cout << endl;
    TreeNode* p = new TreeNode(2);
    TreeNode* q = new TreeNode(8);
    TreeNode* lca = sol.lowestCommonAncestor(bst, p, q);
    cout << "lca of bst is: " << lca->val;
 
    return 0;
}