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
public: int minValue(TreeNode* root) {
     
    TreeNode* temp = root;
      if(temp==NULL){
          return -1;
      }
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->val;
}
    TreeNode* deleteNode(TreeNode* root, int key) {
         if(root==NULL){
        return NULL;
      }
      if(root->val==key){
         //0
         if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
         }
        //1
         if(root->left!=NULL && root->right==NULL){
            TreeNode* temp=root->left;
            delete root;
            return temp;
         }
         if(root->left==NULL && root->right!=NULL){
            TreeNode* temp=root->right;
            delete root;
            return temp;
         }
       //2
        if(root->left!=NULL && root->right!=NULL){
             //two method right ka minimum lelo ya left ka maximum
            int minii = minValue(root->right);
            root->val=minii;
             root->right=deleteNode(root->right,minii);
             return root;
         }
      }
      else if(root->val > key){
          root->left=deleteNode(root->left,key);
          return root;
      }
      else if(root->val < key){
          root->right=deleteNode(root->right,key);
          return root;
      }
       return root; 
    }
};