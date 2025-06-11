/* 110. Balanced Binary Tree (https://leetcode.com/problems/balanced-binary-tree/description/):

Given a binary tree, determine if it is height-balanced.

Height-Balanced:
A height-balanced binary tree is a binary tree in which the depth of the two subtrees 
of every node never differs by more than one. */

#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
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
    int height(TreeNode* root) {
        if(!root) return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if(lh == -1 or rh == -1 or abs(lh - rh) > 1) return -1;
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

int main() {
    TreeNode bt;
    Solution sol;

    vector<int> v = {1,2,2,3,3,NULL,NULL,4,4};

    TreeNode* root = bt.createTree(v);

    bool isBalanced = sol.isBalanced(root);

    cout << "the tree is "; 
    if(isBalanced) cout << "balanced"; 
    else cout << "not balanced";
 
    return 0;
}