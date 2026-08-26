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
    int preindx = 0;
    map<int,int> hm;
    TreeNode* dnc(vector<int> &preorder,vector<int> &inorder,int st,int end){

        if(st>end){
            return NULL;
        }

        int rootval = preorder[preindx++];
        int rootind = hm[rootval];
        TreeNode* root = new TreeNode(rootval);

        root->left = dnc(preorder,inorder,st,rootind-1);
        root->right = dnc(preorder,inorder,rootind+1,end);

        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inorder = preorder;

        sort(inorder.begin(),inorder.end());

        for(int i=0;i<inorder.size();i++){
            hm[inorder[i]] = i;
        }

        return dnc(preorder,inorder,0,inorder.size()-1);
    }
};