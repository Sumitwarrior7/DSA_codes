/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool rec(TreeNode* n1, TreeNode* n2) {
        if(n1->val != n2->val) return false;

        if(n1->left == NULL && n2->right != NULL) return false;
        else if(n1->left != NULL && n2->right == NULL)return false;
        else if(n1->left != NULL && n2->right != NULL) {
            if(rec(n1->left, n2->right) == false) return false;
        }

        if(n1->right == NULL && n2->left != NULL) return false;
        else if(n1->right != NULL && n2->left == NULL)return false;
        else if(n1->right != NULL && n2->left != NULL) {
            if(rec(n1->right, n2->left) == false) return false;
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if(root->left == NULL && root->right == NULL) return true;
        else if(root->left == NULL) return false;
        else if(root->right == NULL) return false;
        else {
            bool check = rec(root->left, root->right);
            if(check) return true;
            else return false;
        }
    }
};