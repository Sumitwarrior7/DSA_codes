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



// To find maximum depth of a binary tree (Root to Leaf)
class Solution {
    public:
    int max_depth (Node* root) {
        if (root == NULL) return 0;

        int left_height = max_depth(root->left);
        int right_height = max_depth(root->right);

        return 1+max(left_height, right_height);
    }
};