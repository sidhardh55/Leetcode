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
    map<int,int> mp;
    int preindx = 0;
    TreeNode* dnc(vector<int>& preorder, vector<int>& inorder,int left,int right){
        
        if(left>right){
            return NULL;
        }

        int rootval =preorder[preindx++];
        TreeNode* root = new TreeNode(rootval);
        
        int rootind = mp[rootval];

        root->left = dnc(preorder,inorder,left,rootind-1);
        root->right = dnc(preorder,inorder,rootind+1,right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
         }
        return dnc(preorder,inorder,0,inorder.size()-1); 
    }
};