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
    struct comp{
        bool operator()(const ListNode* l, ListNode* r){
            return l->val > r->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,comp>q;
        
            for(int i=0;i<lists.size();i++){
                ListNode* temp = lists[i];
                if(temp!=NULL){
                    q.push(temp);
                }
            }  
        
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        
        while(q.size()>0){
            ListNode* temp = q.top();
            q.pop();
            
            curr ->next = temp;
            curr = curr->next;
            
            if(temp->next!=NULL){
                q.push(temp->next);
            }
        }
        return dummy-> next;
             
    }
};