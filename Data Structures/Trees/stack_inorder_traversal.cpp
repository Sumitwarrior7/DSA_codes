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


// Main approach
void push_lefts(stack<Node*> &st, Node* node) {
    while (node != NULL) {
        st.push(node);
        node = node->left;
    }
}

vector<int> stack_inorder(Node* root) {
    vector<int> ans;
    stack<Node*> st;
    push_lefts(st, root);
    while (!st.empty()) {
        ans.push_back(st.top() -> data);
        Node* rt = st.top() -> right;
        st.pop();
        if (rt != NULL) {
            push_lefts(st, rt);
        }
    }
    return ans;
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

    vector<int> sol = stack_inorder(root);
    for (auto item: sol) cout << item << " ";

    return 0;
}