/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = root;
        while(node!=NULL){
            if((p->val < node->val) && (q->val < node->val)){
                node = node->left;
                continue;
            }

            if((p->val > node->val) && (q->val > node->val)){
                node = node->right;
                continue;
            }

            if((p->val>node->val && node->val>q->val)||
               (p->val<node->val && node->val<q->val)){
                break;
            }

            if(node->val==p->val || node->val == q->val){
                break;
            }
        }
        return node;
    }
};