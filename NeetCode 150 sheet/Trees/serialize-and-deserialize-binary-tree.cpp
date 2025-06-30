/* 297. Serialize and Deserialize Binary Tree (https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/):

Serialization is the process of converting a data structure or object into a 
sequence of bits so that it can be stored in a file or memory buffer, 
or transmitted across a network connection link to be reconstructed later 
in the same or another computer environment.

Design an algorithm to serialize and deserialize a binary tree. There is no restriction 
on how your serialization/deserialization algorithm should work. 
You just need to ensure that a binary tree can be serialized to a string and 
this string can be deserialized to the original tree structure.

Clarification: The input/output format is the same as how LeetCode 
serializes a binary tree. You do not necessarily need to follow this format, 
so please be creative and come up with different approaches yourself. */

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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if(cur) {
                    ans += to_string(cur->val) + ',';
                    q.push(cur->left);
                    q.push(cur->right);
                }
                else ans += "null,";
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        vector<string> v;
        string s = "";
        for(char c : data) {
            if(c == ',') {
                v.push_back(s);
                s = "";
            }
            else s += c;
        }
        if(!s.empty()) v.push_back(s);
        if(v[0] == "null") return NULL;
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(v[0]));
        q.push(root);
        int idx = 1;
        while(!q.empty() and idx < v.size()) {
            int sz = q.size();
            for(int i=0; i<sz; i++) {
                TreeNode* cur = q.front();
                q.pop();
                if(idx < v.size() and v[idx] != "null") {
                    cur->left = new TreeNode(stoi(v[idx]));
                    q.push(cur->left);
                }
                idx++;
                if(idx < v.size() and v[idx] != "null") {
                    cur->right = new TreeNode(stoi(v[idx]));
                    q.push(cur->right);
                }
                idx++;
            }
        }
        return root;
    }
};

int main() {
    Codec ser, deser;
    TreeNode bt;

    vector<int> v = {1,2,3,NULL,NULL,4,5};
    TreeNode* root = bt.createTree(v);
    string data = ser.serialize(root);
    cout << "encoded: " << data; cout << endl;
    TreeNode* deserRoot = deser.deserialize(data); cout << endl;
    cout << "decoded: "; bt.printTree(deserRoot);
 
    return 0;
}