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
          }                                                                                                    //tc and sc are O(n)
      }
    public:
    Node *copyList(Node *head)
    {
        Node* clonehead = NULL;
        Node* clonetail = NULL;
        
        Node* temp = head;
        // clone ll with normal next pointers
        while(temp!=NULL){
            insertattail(clonehead,clonetail,temp->data);
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
      clone -> arb = oldtoNewNode[original-> arb];
         original = original -> next;
         clone = clone -> next;
     }
     return clonehead;
