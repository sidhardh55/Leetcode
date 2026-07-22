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
    void helper(TreeNode* root,string st,vector<string> &vecstr){
         
        if(root==NULL){
            return;
        }



        st += to_string(root->val);

        if(!root->left && !root->right){
              vecstr.push_back(st);
        }
        if(root->left || root->right){
            st+="->";
        }

        helper(root->left,st,vecstr);
        helper(root->right,st,vecstr);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> vecstr;
        string ans = "";
        
        if(!root->left && !root->right){
            vecstr.push_back(to_string(root->val));
            return vecstr;
        }
       
        helper(root,ans,vecstr);
        return vecstr;
    }
};