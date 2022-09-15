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
    private: pair<ListNode*,ListNode*>  middlenode(ListNode* head){
        if(head==NULL || head->next==NULL){
            return {NULL,head};
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        
        
        while(fast!=NULL && fast->next!=NULL){
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        }
        
        return {prev,slow};
    }
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==NULL||head->next == NULL){
            return NULL;
        }
        if(head->next->next==NULL){
            head -> next = NULL;
            return head;
        }
         pair<ListNode*,ListNode*> p = middlenode(head);
        ListNode* prev= p.first;
        ListNode* middle = p.second;
        
        prev -> next = middle -> next;
        middle -> next = NULL;
        delete middle;
        
        return head;
        
        //aproach 2
        //   ListNode*slow=head;
        // ListNode*fast=head;
        // ListNode*prev=slow;
        // if(head->next==NULL)return NULL;
        // while(fast&&fast->next)
        // {
        //     prev=slow;
        //     slow=slow->next;
        //     fast=fast->next->next;
        // }
        // prev->next=slow->next;
        // delete(slow);
        // return head;
    }
};