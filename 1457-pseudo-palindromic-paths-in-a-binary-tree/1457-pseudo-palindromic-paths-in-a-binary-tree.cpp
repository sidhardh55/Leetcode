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
    bool palindromic(vector<int> &vec){
        int odd=0;
        for(int cnt : vec){
            if(cnt%2!=0){
                odd++;
            }
        }
        return odd<=1;
    }
    void helper(TreeNode * root, vector<int> &vec,int &count){
            if(root == NULL){
                return;
            }
            vec[root->val]++;
           
            if(!root->left && !root->right){
               if(palindromic(vec)){
                    count++;
               }
            }

            helper(root->left,vec,count);
            helper(root->right,vec,count);
            vec[root->val]--;  
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        vector<int> vec(10,0);
        helper(root,vec,count);
        return count;
    }



};