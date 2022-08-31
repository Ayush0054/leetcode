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
      ListNode* solve(ListNode* list1, ListNode* list2){
          
          //if only one element is present in list1
          if(list1->next==NULL){
              list1-> next = list2;
              return list1;
          }
          ListNode* curr1 = list1;
          ListNode* curr2 = list2;
          ListNode* next1 = list1->next;
          ListNode* next2 = list2->next;
          while(next1!=NULL && curr2!=NULL){
              
          if(curr2->val >=curr1->val && curr2->val<=next1->val){
              //add node between list1
              curr1->next = curr2;
              next2=curr2-> next;
              curr2->next=next1;
              
              //update pointers
              curr1 = curr2 ;
              curr2=next2;
          }
          else{
              curr1 =next1;
              next1 = next1->next;
              
              if(next1==NULL){
                  curr1->next = curr2;
                  return list1;
              }
              
          }
          }
          return list1;
      }
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1==NULL){
            return list2;
        }
        if(list2==NULL){
            return list1;
        }
        if(list1->val<=list2->val){
          return  solve(list1,list2);
        }
        else{
           return solve(list2,list1);
        }
    }
};

//////////////////recursive approach 
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
  {
		// if list1 happen to be NULL
		// we will simply return list2.
		if(l1 == NULL)
        {
			return l2;
		}
		
		// if list2 happen to be NULL
		// we will simply return list1.
		if(l2 == NULL)
        {
			return l1;
		} 
		
		// if value pointend by l1 pointer is less than equal to value pointed by l2 pointer
		// we wall call recursively l1 -> next and whole l2 list.
		if(l1 -> val <= l2 -> val)
        {
			l1 -> next = mergeTwoLists(l1 -> next, l2);
			return l1;
		}
		// we will call recursive l1 whole list and l2 -> next
		else
        {
			l2 -> next = mergeTwoLists(l1, l2 -> next);
			return l2;            
		}
	}
};	
