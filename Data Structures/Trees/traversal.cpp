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



/* -----------------------------------------------DFS Traversal----------------------------------------------- */
// Time Complexity : O(n)
// Space Complexity : O(n)

// Pre Order Traversal
void pre_order(Node* node) {
    if (node == NULL) return;

    print(node -> data);
    pre_order(node -> left);
    pre_order(node -> right);
}

// In Order Traversal
void in_order(Node* node) {
    if (node == NULL) return;

    in_order(node -> left);
    print(node -> data);
    in_order(node -> right);
}

// Post Order Traversal
void post_order(Node* node) {
    if (node == NULL) return;

    post_order(node -> left);
    post_order(node -> right);
    print(node -> data);
}


// Level Order Traversal
class Solution {
    public:
    vector<vector<int>> levelOrder (Node* root) {
        vector<vector<int>> ans;
        
        if(root == NULL) return ans;

        queue<Node*> q;
        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> level;
            for(int i=0; i<size; i++) {
                Node *node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                level.push_back(node->data);
            }
            ans.push_back(level);
        }
        return ans;
    }
};


// ZigZag Traversal
class Solution {
    public:
    vector<vector<int>> zigzag_traversal (Node* root) {
        vector<vector<int>> st;
        queue<Node*> q;

        q.push(root);
        int size = 1;
        int flag = 0;
        while (!q.empty()) {
            int j = 0;
            vector<int> level;
            for (int i = 0; i < size; i++) {
                Node* m = q.front();
                q.pop();

                if (m -> left != NULL) {
                    q.push(m -> left);
                    j++;
                }
                if (m -> right != NULL) {
                    q.push(m -> right);
                    j++;
                }

                level.push_back(m -> data);
            }

            if (flag == 1) reverse(level.begin(), level.end());
            st.push_back(level);
            flag = 1-flag;
            size = j;
        }

        return st;
    }
};
