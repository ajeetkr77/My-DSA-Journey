class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        // code here
        
        // Inserting at beginning 
        Node* temp;
        
        if(data <= head->data){
            //insertAtBeginning
            Node* newNode = new Node(data);
            
            
            // Finding last Element
            temp = head;
            
            while(temp->next != head){
                temp = temp->next;
            }
            
            temp->next = newNode;
            newNode->next = head;
            
            return newNode;
        }
        
        // Inserting at the End
        temp = head;
        
        while(temp->next != head){
            temp = temp->next;
        }
        
        if(temp->data < data){
            Node* newNode = new Node(data);
            temp->next = newNode;
            newNode->next = head;
            return head;
        }
        
        
        //Inserting at the middle 
        
        Node* Prev;
        Node* Next = head;
        
        while(Next->next != head){
            if(Next->data < data){
                Prev = Next;
                Next = Next->next;
            }
                
            else 
                break;
        }
        
        Node* newNode = new Node(data);
        Prev->next = newNode;
        newNode->next = Next;
        
        return head;
    }
};
