
#include <bits/stdc++.h>
using namespace std;

// Declaration of a Node
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
    
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};


/*  ---------------------------------------Anticlockwise Boundary Traversal--------------------------------------- */
vector<int> left_boundary(Node* root) {
    Node* node = root;
    vector<int> lb;
    
    while(true) {
        if ((node -> left == NULL) && (node -> right == NULL)) break;
        lb.push_back(node -> data);
        
        if (node -> left != NULL) {
            node = node -> left;
        } else {
            node = node -> right;
        }
        
    }
    return lb;
}


vector<int> right_boundary(Node* root) {
    Node* node = root;
    vector<int> rb;
    
    while(true) {
        if ((node -> left == NULL) && (node -> right == NULL)) break;
        if (node != root) rb.push_back(node -> data);
        
        if (node -> right != NULL) node = node -> right;
        else node = node -> left;
    }
    reverse(rb.begin(), rb.end());
    return rb;
}


// Pre Order Traversal
void pre_order(Node* &node, vector<int> &ans) {
    if (node == NULL) return;

    if ((node -> left == NULL) && (node -> right == NULL)) ans.push_back(node -> data);
    pre_order(node -> left, ans);
    pre_order(node -> right, ans);
}

vector<int> leaves(Node* root) {
    vector<int> ans;
    pre_order(root, ans);
    return ans;    
}


int main() {
    // Creating a bigger binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    
    
    // Anticlockwise boundarty traversal
    vector<int> left = left_boundary(root);
    vector<int> right = right_boundary(root);
    vector<int> down = leaves(root);
    for (auto item : left) cout << item << " ";
    for (auto item : down) cout << item << " ";
    for (auto item : right) cout << item << " ";
}

