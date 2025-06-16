/* 199. Binary Tree Right Side View (https://leetcode.com/problems/binary-tree-right-side-view/description/):

Given the root of a binary tree, imagine yourself standing on the right side of it, 
return the values of the nodes you can see ordered from top to bottom. */

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
    vector<int> ans;
    void reversePreOrder(TreeNode* root, int level) {
        if(!root) return;
        if(level == ans.size()) ans.push_back(root->val);
        if(root->right) reversePreOrder(root->right, level+1);
        if(root->left) reversePreOrder(root->left, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        reversePreOrder(root, 0);
        return ans;
    }
};


int main() {
    Solution sol;
    TreeNode bt;
    vector<int> v = {1,2,3,4,NULL,NULL,NULL,5};
    TreeNode* root = bt.createTree(v);
    bt.printTree(root); cout << endl;
    vector<int> ans = sol.rightSideView(root);
    for(int i : ans) cout << i << " ";
 
    return 0;
}