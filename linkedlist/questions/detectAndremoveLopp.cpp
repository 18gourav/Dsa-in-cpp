/*************************************************
    
    class Node {
        public :

        int data;
        Node *next;

        Node(int data) {
            this -> data = data;
            this -> next = NULL;
        }
    };

*************************************************/

Node *removeLoop(Node *head)
{
    // Write your code here.
    if(head==NULL || head->next==NULL){
        return head;
    }

    Node* fast = head;
    Node* slow = head;
    bool hasLoop = false;

    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow==fast){
            hasLoop=true;
            break;
        }
    }
    if(!hasLoop){
        return head;
    }

    slow = head;
    while(slow!=fast){
        slow = slow->next;
        fast = fast->next;
    }

    while(fast->next!=slow){
        fast=fast->next;
    }

    fast->next = NULL;

    return head;

}