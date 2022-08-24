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
    private:
     int getcount(ListNode* head){
         ListNode* temp = head;
         int cnt =0;
         while(temp!=NULL){
             temp = temp -> next;
             cnt++;
         }
         return cnt;
     }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || getcount(head)<k){
            return head;
        }
        
        
        ListNode* curr = head;
        ListNode* prev =NULL;
        ListNode* forward = NULL;
        int cnt =0;
        while(curr!=NULL && cnt<k){
            forward = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            cnt++;
        }
        
       if(forward != NULL){
           head -> next = reverseKGroup(forward,k);
       } 
        return prev;
    }
};