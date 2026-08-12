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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> hm;
        unordered_set<int> child;

        TreeNode* root = NULL;

        for (int i = 0; i < descriptions.size(); i++) {

            int parent = descriptions[i][0];
            int c = descriptions[i][1];
            int isLeft = descriptions[i][2];

            if (!hm[parent]) {
                hm[parent] = new TreeNode(parent);
            }

            if (!hm[c]) {
                hm[c] = new TreeNode(c);
            }

            if (isLeft == 1) {
                hm[parent]->left = hm[c];
            } 
            else {
                hm[parent]->right = hm[c];
            }

            child.insert(c);
        }

        for (auto it : hm) {
            if (child.find(it.first) == child.end()) {
                root = it.second;
                break;
            }
        }

        return root;
    }
};