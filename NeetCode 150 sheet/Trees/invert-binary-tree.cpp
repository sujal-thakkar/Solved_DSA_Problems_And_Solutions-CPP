/* 226. Invert Binary Tree (https://leetcode.com/problems/invert-binary-tree/description/):

Given the root of a binary tree, invert the tree, and return its root.
https://assets.leetcode.com/uploads/2021/03/14/invert1-tree.jpg */

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
    TreeNode *invertTree(TreeNode *root) {
        if(!root) return NULL;
        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }
};

int main() {
    Solution sol;
    TreeNode bt;

    vector<int> preorder_seq = {4,2,7,1,3,6,9};

    TreeNode* tree = bt.createTree(preorder_seq);
    bt.printTree(tree); cout << endl;

    TreeNode* invertedTree = sol.invertTree(tree);
    bt.printTree(invertedTree);

    return 0;
}