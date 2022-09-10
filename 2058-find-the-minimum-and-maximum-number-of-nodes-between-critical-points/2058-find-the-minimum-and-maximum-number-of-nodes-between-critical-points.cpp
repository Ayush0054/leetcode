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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head==NULL || head-> next == NULL || head-> next -> next == NULL){
            return{-1,-1};
        }
        ListNode* prev = head;
        ListNode*  curr = prev -> next;
        ListNode* next = curr -> next;
        vector<int> v;
        int cnt =1;
        while(next!=NULL){
            if((curr-> val > prev->val && curr->val > next->val) ||(curr-> val < prev->val && curr->val < next->val)){
                v.push_back(cnt);
            }
            cnt++;
            prev=curr;
            curr = next;
            next = next -> next;
        }
        if(v.size()<2){
            return {-1,-1};
        }
        int mini = INT_MAX;
        for(int i=1;i<v.size();i++){
            mini = min(mini,v[i] - v[i-1]);
        }
        
        return {mini,v.back() - v[0]};
    }
};