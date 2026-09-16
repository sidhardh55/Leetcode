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
    void dfs(unordered_map<int,int> &hm,TreeNode* root){
        if(!root){
            return;
        }
        hm[root->val]++;
        dfs(hm,root->left);
        dfs(hm,root->right);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> hm;
        dfs(hm,root);
        vector<int> res;
        int maxi=INT_MIN;
        for(auto it : hm){
            if(it.second>maxi){
                maxi = it.second;
            }
        }
        for(auto it : hm){
            if(maxi == it.second){
                res.push_back(it.first);
            }
        }
        return res;
    }
};