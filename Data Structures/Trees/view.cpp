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


/* ---------------------------------Top View--------------------------------- */              
vector<int> top_view(Node* root) {
    vector<int> ans;
    map<int, int> mp;
    queue<pair<Node*, int>> q;

    int size = 1;
    q.push({root, 0});
    while (!q.empty()) {
        int j = 0;
        for (int i = 0; i < size; i++) {
            pair<Node*, int> m = q.front();
            q.pop();
            if (mp.find(m.second) == mp.end()) mp[m.second] = m.first->data;

            if (m.first->left != NULL) {
                q.push({m.first->left, m.second-1});
                j++;
            }
            if (m.first->right != NULL) {
                q.push({m.first->right, m.second+1});
                j++;
            }
        }
        size = j;
    }

    for (const auto& pair : mp) {
        ans.push_back(pair.second);
    }
    return ans;
}


/* ---------------------------------Bottom View--------------------------------- */              
vector<int> bottom_view(Node* root) {
    vector<int> ans;
    map<int, int> mp;
    queue<pair<Node*, int>> q;

    int size = 1;
    q.push({root, 0});
    while (!q.empty()) {
        int j = 0;
        for (int i = 0; i < size; i++) {
            pair<Node*, int> m = q.front();
            q.pop();
            mp[m.second] = m.first->data;

            if (m.first->left != NULL) {
                q.push({m.first->left, m.second-1});
                j++;
            }
            if (m.first->right != NULL) {
                q.push({m.first->right, m.second+1});
                j++;
            }
        }
        size = j;
    }

    for (const auto& pair : mp) {
        ans.push_back(pair.second);
    }
    return ans;
}


/* ---------------------------------Left View--------------------------------- */  
vector<int> left_view (Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        int level = INT_MIN;
        for(int i=0; i<size; i++) {
            Node *node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            
            if (level == INT_MIN) level = node->data;
        }
        ans.push_back(level);
    }

    return ans;
}


/* ---------------------------------Right View--------------------------------- */  
vector<int> right_view (Node* root) {
    vector<int> ans;
    if(root == NULL) return ans;

    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int size = q.size();
        int level;
        for(int i=0; i<size; i++) {
            Node *node = q.front();
            q.pop();
            if(node->left != NULL) q.push(node->left);
            if(node->right != NULL) q.push(node->right);
            
            level = node->data;
        }
        ans.push_back(level);
    }

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
    root->left->left->left = new Node(8);
    
    
    // Front View
    vector<int> sol = top_view(root);
    for (auto item : sol) cout << item << " ";
    cout << endl;

    // Bottom View
    vector<int> sol2 = bottom_view(root);
    for (auto item : sol2) cout << item << " ";
    cout << endl;

    // Left View
    vector<int> sol3 = left_view(root);
    for (auto item : sol3) cout << item << " ";
    cout << endl;

    // Right View
    vector<int> sol4 = right_view(root);
    for (auto item : sol4) cout << item << " ";
    cout << endl;
}