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
    void dfs(TreeNode* root,long long &mini1, long long &mini2){
        if(root == NULL) return;
        if(mini1>root->val){
            mini2 = mini1;
            mini1 = root->val;
        }
        if(mini2>root->val && mini1<root->val){
            mini2 = root->val;
        }
        dfs(root->left,mini1,mini2);
        dfs(root->right,mini1,mini2);


    }
    int findSecondMinimumValue(TreeNode* root) {
        long long mini1 = LLONG_MAX;
        long long mini2 = LLONG_MAX;
        dfs(root, mini1, mini2);
        if(mini2 == LLONG_MAX) return -1;
        return (int)mini2;
    }
};