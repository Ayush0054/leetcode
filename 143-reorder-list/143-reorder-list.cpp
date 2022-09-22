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
    ListNode* getmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast -> next->next;
        }
        return slow;
    }
    
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head){
            next = head->next;
            head-> next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* mid= getmid(head);
        ListNode* second = reverse(mid->next);
        mid ->next = NULL;
        
        while(second){
            
            ListNode* temp1 = head-> next;
            ListNode* temp2 = second -> next;
            head -> next = second;
            second -> next = temp1;
            head = temp1;
            second = temp2;
        }
    }
};