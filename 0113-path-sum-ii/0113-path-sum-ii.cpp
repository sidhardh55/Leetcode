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
    vector<vector<int>> ans;
    void helper(TreeNode* root,vector<int> &vec,int sum,int target){
        if(root == NULL){
            return;
        }
        sum = sum + root->val;
        vec.push_back(root->val);
        if(!root->left && !root->right){
            if(sum == target){
                ans.push_back(vec);
            }
        }
        helper(root->left,vec,sum,target);
        helper(root->right,vec,sum,target);
        vec.pop_back();

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> vec;
        helper(root,vec,0,targetSum);
        return ans;
    }
};