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
    void traversal(TreeNode* root,vector<string> &vect){
        if(root==NULL){
            vect.push_back("null");
            return;
        }
        vect.push_back(to_string(root->val));
        traversal(root->left,vect);
        traversal(root->right,vect);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<string> v1;
        vector<string> v2;
        traversal(p,v1);
        traversal(q,v2);
        return v1==v2;
    }
};