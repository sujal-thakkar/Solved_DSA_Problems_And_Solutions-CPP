/* 102. Binary Tree Level Order Traversal (https://leetcode.com/problems/binary-tree-level-order-traversal/description/):

Given the root of a binary tree, return the level order traversal 
of its nodes' values. (i.e., from left to right, level by level). */

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            vector<int> curLevel;
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                curLevel.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
            ans.push_back(curLevel);
        }
        return ans;
    }
};

int main() {
    TreeNode bt;
    Solution sol;
    vector<int> v = {3,9,20,NULL,NULL,15,7};
    TreeNode* root = bt.createTree(v);
    bt.printTree(root); cout << endl;
    vector<vector<int>> ans = sol.levelOrder(root);
    for(int i=0; i<ans.size(); i++) {
        cout << '[';
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << ']' << endl;
    } 

 
    return 0;
}