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

int idx = -1;
Node* createTree(vector<int> preorder_seq) {
    idx++;
    if(preorder_seq[idx] == -1) return NULL;
    Node* root = new Node(preorder_seq[idx]);
    root->left = createTree(preorder_seq);
    root->right = createTree(preorder_seq);
    return root;
}

// Preorder traversal:
void preorder(Node* root) {
    if(!root) return;

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Inorder traversal:
void inorder(Node* root) {
    if(!root) return;
    
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// Postorder traversal:
void postorder(Node* root) {
    if(!root) return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

// level order traversal:
void levelOrder(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()) {
        Node* frontEle = q.front();
        q.pop();

        if(frontEle == NULL) {
            cout << endl;
            if(q.empty()) break;
            q.push(NULL);
        }
        else {
            cout << frontEle->val << " ";
            if(frontEle->left) q.push(frontEle->left);
            if(frontEle->right) q.push(frontEle->right);
        }
    }
}

// Calc Height of a tree:
int height(Node* root) {
    if(!root) return 0;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int countOfNodes(Node* root) {
    if(!root) return 0;
    int leftCnt = countOfNodes(root->left);
    int rightCnt = countOfNodes(root->right);
    return leftCnt+rightCnt+1;
}

int sumOfNodes(Node* root) {
    if(!root) return 0;

    int leftSum = sumOfNodes(root->left);
    int rightSum = sumOfNodes(root->right);
    return leftSum + rightSum + root->val;
}   


int main() {
    vector<int> preorder_seq = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node* root = createTree(preorder_seq);
    // preorder(root); cout << endl;
    // inorder(root); cout << endl;
    // postorder(root); cout << endl;
    // levelOrder(root);
    // cout << "Height: " << height(root);
    // cout << "nodes count: " << countNodes(root);
    cout << "node count: " << sumOfNodeVal(root);
 
    return 0;
}