/* 1448. Count Good Nodes in Binary Tree (https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/):

Given a binary tree root, a node X in the tree is named good 
if in the path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree. */

// t.c= O(n) (if the tree is skewed), s.c.= O(h), h = height of the tree. 
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
    int dfs(TreeNode* node, int maxVal) {
        if(!node) return 0;
        int ans = node->val >= maxVal? 1 : 0;
        maxVal = max(maxVal, node->val);
        ans += dfs(node->left, maxVal);
        ans += dfs(node->right, maxVal);
        return ans;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root, root->val); 
    }
};

int main() {
    Solution sol;
    TreeNode bt;
    vector<int> v = {2,NULL,4,10,8,NULL,NULL,4};
    TreeNode* root = bt.createTree(v);
    bt.printTree(root); cout << endl;
    int ans = sol.goodNodes(root);
    cout << ans;
 
    return 0;
}