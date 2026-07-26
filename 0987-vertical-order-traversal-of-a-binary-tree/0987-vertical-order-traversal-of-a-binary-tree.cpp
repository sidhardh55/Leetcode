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
    void helper(TreeNode* root,
                unordered_map<int, vector<pair<int,int>>>& hm,
                int row,
                int col,
                int &minCol,
                int &maxCol) {

        if (root == NULL)
            return;

        minCol = min(minCol, col);
        maxCol = max(maxCol, col);

        hm[col].push_back({row, root->val});

        helper(root->left, hm, row + 1, col - 1, minCol, maxCol);
        helper(root->right, hm, row + 1, col + 1, minCol, maxCol);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        unordered_map<int, vector<pair<int,int>>> hm;

        int minCol = INT_MAX;
        int maxCol = INT_MIN;

        helper(root, hm, 0, 0, minCol, maxCol);

        vector<vector<int>> ans;

        for (int i = minCol; i <= maxCol; i++) {

            vector<pair<int,int>> vec = hm[i];

            sort(vec.begin(), vec.end());

            vector<int> temp;

            for (auto &p : vec) {
                temp.push_back(p.second);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};