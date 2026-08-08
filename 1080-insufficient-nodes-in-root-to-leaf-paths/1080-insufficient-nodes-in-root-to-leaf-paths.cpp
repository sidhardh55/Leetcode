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
    TreeNode* dfs(TreeNode *root,int limit,int sum){
       
        sum = sum + root->val;
        if(!root->left && !root->right){
            if(limit>sum){
                return NULL;
            }else{
                return root;
            }
        }
        if(root->left) root->left= dfs(root->left,limit,sum);
        if(root->right) root->right = dfs(root->right,limit,sum);

        if(root->left || root->right){
            return root;
        }else{
            return NULL;
        }

    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int sum = 0;
        return dfs(root,limit,sum);
        // return root;
    }
};