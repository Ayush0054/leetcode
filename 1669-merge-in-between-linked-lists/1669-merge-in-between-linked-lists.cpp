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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        ListNode* curr2 = list1;
        for(int cnt=0;cnt<a-1;cnt++){
            curr = curr->next;
        }
        for(int cnt = 0;cnt<b;cnt++){
            curr2 = curr2->next;
        }
        curr->next = list2;
        while(list2->next!=NULL){
            list2 = list2->next;
        } 
        list2 ->next = curr2->next;
           return list1;    
    }
    
};