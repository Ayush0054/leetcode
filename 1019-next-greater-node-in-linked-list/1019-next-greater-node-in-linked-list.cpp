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
  ListNode* reverse1(ListNode* head){
    //base case
    if(head==NULL || head-> next == NULL){
        return head;
    }
    ListNode* chotahead = reverse1(head-> next);
    head-> next-> next =head;
    head -> next = NULL;
    return chotahead;
}
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        stack<int> st;
        head = reverse1(head);
        while(head!=NULL){
            if(st.empty()){
                res.push_back(0);
                st.push(head->val);
                head = head->next;
            }
            else if(st.top() > head->val){
                res.push_back(st.top());
                st.push(head->val);
                head = head ->next;
            }
            else
                st.pop();
            
        }
        reverse(res.begin(),res.end());
        return res;
    }
};