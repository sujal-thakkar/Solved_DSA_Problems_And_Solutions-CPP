/* 572. Subtree of Another Tree (https://leetcode.com/problems/subtree-of-another-tree/description/):

Given the roots of two binary trees root and subRoot, return true if there is a subtree 
of root with the same structure and node values of subRoot and false otherwise.

A subtree of a binary tree tree is a tree that consists of a node in tree and 
all of this node's descendants. The tree tree could also be considered as a subtree of itself. */

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
    bool isSameTree(TreeNode* r1, TreeNode* r2) {
        if(!r1 or !r2) return r1 == r2;
        bool ils = isSameTree(r1->left, r2->left);
        bool irs = isSameTree(r1->right, r2->right);
        return irs and ils and r1->val == r2->val;
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        if(isSameTree(root, subRoot)) return true; 
        return isSubtree(root->left, subRoot) or isSubtree(root->right, subRoot);
    }
};

int main() {
    TreeNode bt;
    Solution sol;

    vector<int> v1 = {3,4,5,1,2,NULL,NULL,NULL,NULL,0}, v2 = {4,1,2};
    TreeNode* root = bt.createTree(v1), *subRoot = bt.createTree(v2);
    bool isSubtree = sol.isSubtree(root, subRoot);
    if(isSubtree) cout << "subtree";
    else cout << "not a subtree";
 
    return 0;
}