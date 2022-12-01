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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
//          map<int ,vector<int> >  nodes;
//            queue<pair<int ,TreeNode* > > q;
//         vector<vector<int>>res;
        
//         if(root==NULL){
//             return res;
//         }
        
//            q.push(make_pair(0 ,root));
//         while(!q.empty()){
//              pair<int ,TreeNode*> temp = q.front();
//             q.pop();
//             TreeNode* frontnode = temp.second;
//             int hd = temp.first;
            
//             nodes[hd].push_back(frontnode->val);
            
//             if(frontnode->left){
//                q.push(make_pair(hd-1 ,frontnode->left));
//             }
//             if(frontnode->right){
//                 q.push(make_pair(hd-1 ,frontnode->right));
//             }
//         }
         map<int, map<int,vector<int> > > nodes;
        queue< pair<TreeNode*, pair<int,int> > > q;
        vector<vector<int>> res;
        
        if(root == NULL)
            return res;
            
        q.push(make_pair(root, make_pair(0,0)));
        
        while(!q.empty()) {
            pair<TreeNode*, pair<int,int> > temp = q.front();
            q.pop();
            TreeNode* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->val);
            
            if(frontNode->left)
                q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
                
            if(frontNode->right)
                q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
        }

              
    //     for(auto i:nodes){
    //     vector<int>ans;
    //         sort(i.second.begin(), i.second.end());
    //     for(auto j:i.second){
    //             ans.push_back(j);
    //     }
    //     res.push_back(ans);
    // }
             for(auto i:nodes){
        vector<int>ans;
        for(auto j:i.second){
            sort(j.second.begin(), j.second.end());
            for(auto k:j.second){
                ans.push_back(k);
            }
        }
        res.push_back(ans);
    }
    return res;
    }
};