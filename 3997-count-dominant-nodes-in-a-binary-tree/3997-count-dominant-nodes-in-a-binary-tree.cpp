// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:

//     void helper(TreeNode* root,int count,int leftmax,int rightmax){
        
//         if(!root->left && !root->right) {
//             count++;
//             return;
//         }
//         helper(root->left,count,leftmax,rightmax);
//         helper(root->right,count,leftmax,rightmax);

//         if(root->left->val>leftmax){
//             leftmax = root->left->val;
//         }
//         if(root->right->val>rightmax){
//             rightmax = root->right->val;
//         }

//         int maxi = max(root->left->val,root->right->val);

//          if(maxi<=root->val) count++;
//     }
  
    
//     int countDominantNodes(TreeNode* root) {
        
//         int count=0;
//         int leftmax = 0;
//         int rightmax = 0;

//         helper(root,count,leftmax,rightmax);

//        return count;
       
        

       
        
//        \
//     }
// };

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

    int helper(TreeNode* root, int &count) {

        if (!root)
            return INT_MIN;

        int leftmax = helper(root->left, count);
        int rightmax = helper(root->right, count);

        int maxi = max(leftmax,rightmax);

        if (maxi <= root->val) count++;

        return max(root->val,maxi);
       

  
    }

    int countDominantNodes(TreeNode* root) {

        int count = 0;

        helper(root, count);

        return count;
    }
};