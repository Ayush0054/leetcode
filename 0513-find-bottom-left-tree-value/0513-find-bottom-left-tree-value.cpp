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
    void solve(TreeNode* root,int &ans,int lv,int &maxlv){
        if(root==NULL){
            return;
        }
        if(lv>maxlv){
        ans = root->val;
            maxlv = lv;
        }
         solve(root->left,ans,lv+1,maxlv);
        cout<<"pehla"<<lv<<endl;
         solve(root->right,ans,lv+1,maxlv);
    }
    int findBottomLeftValue(TreeNode* root) {
      int ans;
        int maxlv = 0;
        solve(root,ans,1,maxlv);
        return ans;
    }
    
//      int findBottomLeftValue(TreeNode* root) {
//            queue<TreeNode*>q;
//         TreeNode* front;
//            q.push(root);
//         while(!q.empty()){
//             front = q.front();
//            q.pop();
//             if(front->right){
//                 q.push(front->right);
//             }
//             if(front->left){
//                 q.push(front->left);
//             }
        
//         }
//         return front->val;
         
//      }
};