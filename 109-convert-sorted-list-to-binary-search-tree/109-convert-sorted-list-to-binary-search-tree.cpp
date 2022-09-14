/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    private:
    pair<ListNode*,ListNode*> findmiddle(ListNode* head){
        if(head==NULL || head->next==NULL){
            return {NULL,head};
        }
        
        ListNode* slow = head;
        ListNode* fast = head-> next;
        ListNode* prev = NULL;
        
        while(fast != NULL && fast->next !=NULL){
            fast = fast -> next -> next;
            prev = slow ;
            slow = slow -> next;
        }
        return {prev,slow};
    }
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head ==NULL){
            return NULL;
        }
        pair<ListNode*,ListNode*> p = findmiddle(head);
        ListNode* prev= p.first;
        ListNode* middle = p.second;
        
        TreeNode* root = new TreeNode(middle->val);
        
        if(prev!=NULL){
            prev-> next = NULL;
            
            root -> left =sortedListToBST(head);
        }
        
        root-> right = sortedListToBST(middle->next);
        return root;
    }
};