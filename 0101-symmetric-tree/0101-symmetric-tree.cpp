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
    bool isSymmetric(TreeNode* root) {
        return root == NULL || symmetric_check(root->left,root->right);
    }
    bool symmetric_check(TreeNode* left,TreeNode* right){
        if(left == NULL || right == NULL){
            return right == left;
        }
        if(left->val != right->val) return false;

        return symmetric_check(left->left,right->right) && symmetric_check(left->right,right->left);
    }
};