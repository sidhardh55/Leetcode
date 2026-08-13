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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>> que;
        que.push({root,0});
        int maxi = 1;

        while(!que.empty()){
            int size = que.size();
            unsigned long long left = 0, right = 0;

            for(int i = 0; i < size; i++){
                auto node = que.front();
                que.pop();

                if(i == 0) left = node.second;
                if(i == size - 1) right = node.second;

                if(node.first->left){
                    que.push({node.first->left, 2*(node.second)});
                }
                if(node.first->right){
                    que.push({node.first->right, 2*(node.second)+1});
                }
            }

            maxi = max(maxi, (int)(right - left + 1));
        }
        return maxi;
    }
};