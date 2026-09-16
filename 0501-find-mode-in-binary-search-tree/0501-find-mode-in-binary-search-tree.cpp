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
    vector<int> res;
    int curCount=0;
    int maxCount=0;
    bool first=true;
    int prev=0;
    void inorder(TreeNode* root){
        if(!root){
            return;
        }
        inorder(root->left);

        if(first|| root->val!=prev){
            first=false;
            curCount=1;
        }else{
            curCount++;
        }

        if(curCount>maxCount){
            maxCount=curCount;
            res.clear();
            res.push_back(root->val);
        }else if(curCount == maxCount){
            res.push_back(root->val);
        }

        prev = root->val;

        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};