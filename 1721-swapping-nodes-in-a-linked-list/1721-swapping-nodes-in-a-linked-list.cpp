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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* curr =head;
        ListNode* left = head;
        ListNode* right = head;
        
        int cnt =1;
        while(curr!=NULL){
            if(k>cnt){
                left = left -> next;
            }
            if(k<cnt){
                right = right -> next;
            }
            curr = curr -> next;
            cnt++;
        }
        
        int temp = left -> val;
        left -> val = right -> val;
        right -> val = temp;
        
        return head;
    }
};