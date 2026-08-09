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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*> que;
        que.push(root);
        int i=0;
        vector<int> vec;
        while(!que.empty()){
            int size = que.size();
            if(i%2 == 0) vec.clear();
            while(size--){
                TreeNode* temp = que.front();
                if(i%2!=0){
                    cout<<temp->val<<"->"<<vec[vec.size()-1]<<endl;
                    temp->val = vec[vec.size()-1];
                    vec.pop_back();
                } 
                que.pop();
                if(temp->left){
                    que.push(temp->left);
                    if(i%2==0){
                        cout<<"pushing :"<<temp->left->val<<endl;
                        vec.push_back(temp->left->val);
                    } 
                } 
                if(temp->right){
                    que.push(temp->right);
                    if(i%2==0){
                        cout<<"pushing :"<<temp->right->val<<endl;
                        vec.push_back(temp->right->val);
                    }
                } 
            }
            i++;
        }
        return root;
    }
};