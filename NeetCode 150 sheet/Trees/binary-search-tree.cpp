#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int val;
    Node* left, *right;

    Node(int val) {
        this->val = val;
        left = right = NULL;
    }
};

Node* insert(Node* root, int val) {
    if(!root) return new Node(val);

    if(val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);

    return root;
}

Node* createBST(vector<int> v) {
    Node* root = NULL;

    for(int val : v) {
        root = insert(root, val);
    }

    return root;
}

void printBST(Node* root) {     
    if(!root) return;
    printBST(root->left);
    cout << root->val << " ";
    printBST(root->right);
}

bool searchBST(Node* root, int tar) {
    if(!root) return false;
    if(root->val == tar) return true;
    else if(root->val > tar) searchBST(root->left, tar);
    else searchBST(root->right, tar);
}

int main() {
    vector<int> v = {5,8,6,3,1,9,14};
    Node* root = createBST(v);
    printBST(root); cout << endl;
    bool isPresent = searchBST(root, 65);
    if(isPresent) cout << "present";
    else cout << "not present";
 
    return 0;
}