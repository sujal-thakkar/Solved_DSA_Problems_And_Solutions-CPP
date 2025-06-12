#include <bits/stdc++.h>
using namespace std;

struct Node {
    // Definition for a binary tree node.
    int val;
    Node *left;
    Node *right;
    Node() : val(0), left(nullptr), right(nullptr) {}
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}

    // construct tree using level order, iterative algorithm
    Node* createTree(vector<int> v) { 
        if(v.empty()) return NULL;

        Node* root = new Node(v[0]);
        queue<Node*> q;
        q.push(root);

        int i = 1;
        while(!q.empty() and i < v.size()) {
            Node* cur = q.front();
            q.pop();

            if(i < v.size()) {
                cur->left = new Node(v[i]);
                q.push(cur->left);
                i++;
            }

            if(i < v.size()) {
                cur->right = new Node(v[i]);
                q.push(cur->right);
                i++;
            }
        }

        return root;
    }

    // Print binary tree
    void printTree(Node* root) {
        if(!root) return;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            cout << cur->val << " ";
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
    }
};


class Solution {
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        if(!root) return {};

        vector<int> ans;
        queue<pair<Node*, int>> q;
        map<int, Node*> m;

        q.push({root, 0});

        while(!q.empty()) {
            Node* curNode = q.front().first;
            int curHD = q.front().second;
            q.pop();

            if(curNode->left) q.push({curNode->left, curHD - 1});
            if(curNode->right) q.push({curNode->right, curHD + 1});

            if(!m.count(curHD)) m[curHD] = curNode;
        }
        for(auto it : m) ans.push_back(it.second->val);

        return ans;
    }
};

int main() {
    Solution sol;
    Node bt;

    vector<int> v = {1, 2, NULL, NULL, 3, 4, NULL, NULL, 5, NULL, NULL};

    Node* root = bt.createTree(v);

    bt.printTree(root); cout << endl;

    vector<int> topView = sol.topView(root);
    for(int i : topView) cout << i << " ";

    return 0;
}