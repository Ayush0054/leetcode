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
public: void inorder(TreeNode* root,vector<int>& res){

       if(root==NULL){
           return;
       }
       inorder(root->left,res);
          res.push_back(root->val); 
       inorder(root->right,res);
}
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        vector<int>ans;
        inorder(root,ans);
        for(int i=1;i<ans.size();i++){
            // cout<<ans[i]<<" ";
            if(ans[i-1]>=ans[i]){
              return false;
            }
            
        }
        return true;
    }
};