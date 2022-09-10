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
class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        head = head -> next;
        if(head==NULL){
            return NULL;
        }
        ListNode* temp = head;
        while(temp!=NULL){
        ListNode* end = temp;
        int ans =0;
        while(end->val!=0){
            ans = ans + end-> val; 
          end = end-> next;
        }
            temp -> val = ans;
            temp ->next = end -> next;
            temp = temp -> next;
            }
        return head;
        
    }
};