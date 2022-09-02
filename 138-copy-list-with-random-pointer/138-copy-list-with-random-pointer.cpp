/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    private:
      void insertattail(Node* &head,Node* &tail,int data){
          Node* temp = new Node(data);
          if(head==NULL){
              head = temp;
              tail = temp;
              return;
          }
          else{
              tail->next = temp;                                                
              tail = temp;
          }
      }
public:
    Node* copyRandomList(Node* head) {                                //tc-> O(n) and sc-> O(1)
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        
        Node* temp = head;
        // clone ll with normal next pointers
        while(temp!=NULL){
            insertattail(clonehead,clonetail,temp->val);
            temp = temp -> next;
        }
        
      Node* original = head;
      Node* clone =clonehead;
      
     while(original!=NULL && clone!=NULL){
            Node* next = original -> next;
         original-> next = clone;
         original = next;
         
         next = clone -> next; 
         clone -> next=original;
        clone = next;
     }
        
     temp=head;
        while(temp!=NULL){
          if(temp->next!=NULL){
        temp -> next -> random = temp ->random ? temp -> random -> next : temp->random;      
          }
         temp = temp -> next  -> next;   
            }
        
   
        
     original = head;
     clone = clonehead;
     while(original!=NULL && clone!=NULL){
     original -> next = clone -> next; 
        original = original -> next;
         
         if(original!=NULL){
         clone -> next = original -> next;
         }
         clone = clone -> next;
     }
     return clonehead;
    }
};