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
    map<int,map<int,multiset<int>>> values;
public:
    void helper(TreeNode* root,int row,int col  ) {

        if (root == NULL)
            return;

        values[col][row].insert(root->val);

        

        helper(root->left,row + 1, col - 1);
        helper(root->right, row + 1, col + 1);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        helper(root, 0, 0);

        vector<vector<int>> ans;

        for (auto &col :values) {

            vector<int> vec;


            for (auto &row : col.second) {
                vec.insert(vec.end(),row.second.begin(),row.second.end());
            }

            ans.push_back(vec);
        }

        return ans;
    }
};