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
    ListNode* mergetwo(ListNode* list1,ListNode* list2){
         if(list1==NULL){
             return list2;
         }
         if(list2==NULL){
             return list1;
         }
        if(list1->val < list2->val){
            list1 -> next = mergetwo(list1->next,list2);
            return list1;
        }
        else{
            list2->next = mergetwo(list1,list2->next);
            return list2;
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* result = NULL;
        
        for(int i=0;i<lists.size();i++){
            result = mergetwo(result,lists[i]);
        }
        return result;
    }
};
     // soln 2
// class Solution {
// public:
//     struct comp{
//         bool operator()(const ListNode* l, ListNode* r){
//             return l->val > r->val;
//         }
//     };
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         priority_queue<ListNode*,vector<ListNode*>,comp>q;
        
//             for(int i=0;i<lists.size();i++){
//                 ListNode* temp = lists[i];
//                 if(temp!=NULL){
//                     q.push(temp);
//                 }
//             }  
        
//         ListNode* dummy = new ListNode(0);
//         ListNode* curr = dummy;
        
//         while(q.size()>0){
//             ListNode* temp = q.top();
//             q.pop();
            
//             curr ->next = temp;
//             curr = curr->next;
            
//             if(temp->next!=NULL){
//                 q.push(temp->next);
//             }
//         }
//         return dummy-> next;
             
//     }
// };