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
    private:                            //tc->O(n) sc->O(1)
    ListNode* getmid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head -> next;
        while(fast != NULL && fast ->next != NULL){
            fast = fast -> next -> next ;
            slow = slow -> next;
        }
        return slow;
    }
    ListNode* reverse(ListNode* head){
        ListNode* curr = head;
        ListNode* prev =NULL;
        ListNode* next =NULL;
        while(curr!=NULL){
            next = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    public:
    bool isPalindrome(ListNode* head) {
        //single element
        if(head->next==NULL){
            return true;
        }
        ListNode* middle = getmid(head);
        
        //step2 -> reverse List after Middle
        ListNode* temp = middle -> next;
        middle -> next = reverse(temp);
        
         //step3 - Compare both halves
        ListNode* head1 = head;
        ListNode* head2 = middle -> next ;
        while(head2!=NULL){
            if(head2->val!=head1->val){
                return false;
            }
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
        
         //step4 - repeat step 2   (optional step to make ll back as in question)
        temp = middle->next;
        middle-> next = reverse(temp);
        return true;
    }
};

//approach two   by converting ll into array 
class Solution {
private:
    bool checkpalindrome(vector<int>arr){
        int n = arr.size();                  //tc - O(n),sc -O(n) in 1st approach
        int e = n-1;
        int s =0;                                     
        while(s<=e){
            if(arr[s]!=arr[e]){
                return 0;
            }
            s++;
            e--;
        }
        return 1;
    }
    public:
    bool isPalindrome(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp=temp->next;
        }
        return checkpalindrome(arr);
    }
};
