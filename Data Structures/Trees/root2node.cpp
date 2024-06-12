#include <bits/stdc++.h>
using namespace std;

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



void traversal(Node* node, int targ, vector<int> &ans, vector<int> &main_ans) {
    if (node == NULL) return;
    ans.push_back(node->data);
    
    if (node->data == targ) {
        main_ans = ans;
        return;
    }
    
    traversal(node->left, targ, ans, main_ans);
    if (node->left != NULL) ans.pop_back();
    
    traversal(node->right, targ, ans, main_ans);
    if (node->right != NULL) ans.pop_back();
}


vector<int> path(Node* root, int target) {
    vector<int> main_ans;
    vector<int> ans;
    traversal(root, target, ans, main_ans);
    return main_ans;
}


int main()
{
    // Creating a binary tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    root->left->left = new Node(4);
    root->left->right = new Node(5);

    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);

    vector<int> sol = path(root, 3);
    for (auto item: sol) cout << item << " ";

    return 0;
}