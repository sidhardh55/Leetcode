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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(root == NULL) return newNode;
        TreeNode* temp = root;
        TreeNode* insert = NULL;
        int l=0;
        while(temp!=NULL){
            if(temp->val > val){
                insert = temp;
                temp = temp->left;
                l=0;
            }else{
                insert = temp;
                temp = temp->right;
                l=1;
            }
        }
        if(l==0){
            insert->left = newNode;
        }else{
            insert->right = newNode;
        }
        return root;
    }
};