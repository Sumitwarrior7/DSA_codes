#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


bool check_bst(Node* node, int lr, int rr) {
    if ((lr >= node->data) || (node->data >= rr)) return false;
    
    if (node-> left == NULL && node->right == NULL) return true;
    else if (node->left == NULL) {
        return check_bst(node->right, node->data, rr);
    }
    else if (node->right == NULL) {
        return check_bst(node->left, lr, node->data);
    }
    else {
        bool l = check_bst(node->right, node->data, rr);
        bool r = check_bst(node->left, lr, node->data);
        return (l && r);
    }
}


int bst(Node* root) {
    bool ans = check_bst(root, INT_MIN, INT_MAX);
    return ans;
}



int main() {
    Node* root = new Node(4);

    root->left = new Node(2);
    root->right = new Node(6);

    root->left->left = new Node(0);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(8);

    bool ans = bst(root);
    cout << ans;
}