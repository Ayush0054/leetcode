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
    ListNode* reversell(ListNode* head){
        if(head==NULL || head-> next == NULL){
            return head;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    
  int getlength(ListNode* head){
    ListNode* temp= head;
     if ( head == NULL ) return 0;
        
        int count = 1;
        
        while( temp->next != NULL ) {
            temp = temp->next;
            count++;
        }
        
        return count;
    }
    
    
   ListNode* removeLastNode(ListNode* head){

    if (head == NULL)
        return NULL;
 
    if (head->next == NULL) {
        delete head;
        return NULL;
    }
 
    // Find the second last node
    ListNode* second_last = head;
    while (second_last->next->next != NULL)
        second_last = second_last->next;
 
    // Delete last node
    delete (second_last->next);
 
    // Change next of second last
    second_last->next = NULL;
 
    return head;
}
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = getlength(head);
        if(n>len){
            return NULL;
        }
        if(n==1 && len==1){
            return NULL;
        }
        if(n==1){
            removeLastNode(head);
            return head;
        }
        head = reversell(head);
        ListNode* temp = head;
        int cnt =1;
        while(cnt<n-1 && temp-> next!=NULL){
            temp = temp -> next;
            cnt++;
        }
        ListNode* Next = temp-> next;
        if(temp-> next!=NULL){
        temp -> next = Next -> next;
        }
        //Next -> next = NULL;
        delete Next;

        head =reversell(head);
        return head;
    }
};