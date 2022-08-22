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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head-> next == NULL){
            return head;
        }
        // aprroch 1 recursive way 
        ListNode* newhead = reverseList(head-> next);
        head-> next -> next =head ;
        head -> next =NULL;
        return newhead;
        
        
        //aproach two 
        // ListNode* curr = head;
        // ListNode* prev = NULL;
        // while(head!= NULL){
        //     ListNode* forward = curr-> next;
        //     curr-> next =prev;
        //     curr = forward;
        //     prev = curr;
        // }
        // return prev;
    }
};