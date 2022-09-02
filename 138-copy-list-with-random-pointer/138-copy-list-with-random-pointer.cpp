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
    Node* copyRandomList(Node* head) {
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        
        Node* temp = head;
        // clone ll with normal next pointers
        while(temp!=NULL){
            insertattail(clonehead,clonetail,temp->val);
            temp = temp -> next;
        }
    //create a map and copy original random pointers to clone
      unordered_map<Node*,Node*> oldtoNewNode;
      Node* original = head;
      Node* clone =clonehead;
      
     while(original!=NULL && clone!=NULL){
         oldtoNewNode[original]= clone;
         original = original -> next;
         clone = clone -> next;
     }
     original = head;
     clone = clonehead;
     
     while(original!=NULL){
      clone -> random = oldtoNewNode[original-> random];
         original = original -> next;
         clone = clone -> next;
     }
     return clonehead;
    }
};