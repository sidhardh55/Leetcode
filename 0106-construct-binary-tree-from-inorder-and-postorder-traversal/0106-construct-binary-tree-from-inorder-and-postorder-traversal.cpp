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
    TreeNode* dnc(vector<int>& postorder, vector<int>& inorder,int left,int right, int &postindx){
        
        if(left>right){
            return NULL;
        }

        int rootval =postorder[postindx--];
        TreeNode* root = new TreeNode(rootval);
        
        int rootind = mp[rootval];

        root->right = dnc(postorder,inorder,rootind+1,right,postindx);
        root->left = dnc(postorder,inorder,left,rootind-1,postindx);
        

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postindx = postorder.size()-1; 
        for(int i=0;i<inorder.size();i++){
           mp[inorder[i]] = i;
        }
        return dnc(postorder,inorder,0,inorder.size()-1,postindx); 
    }
};