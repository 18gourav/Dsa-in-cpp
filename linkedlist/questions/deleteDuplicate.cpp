/**
 * Definition of doubly linked list:
 * class Node {
 * public:
 *      int data;
 *      Node *prev;
 *      Node *next;
 *      Node() {
 *          this->data = 0;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node(int data) {
 *          this->data = data;
 *          this->prev = NULL;
 *          this->next = NULL;
 *      }
 *      Node (int data, Node *next, Node *prev) {
 *          this->data = data;
 *          this->prev = prev;
 *          this->next = next;
 *      }
 * };
 *
 *************************************************************************/
Node * removeDuplicates(Node *head)
{
    if(head==NULL){
        return NULL;
    }
    Node* temp = head;
                                     
    while(temp->next != NULL){
        if(temp->data == temp->next->data){
            Node* nodeTodelete = temp->next;
            Node* next_next = temp->next->next;
            temp->next=next_next;
            if(next_next != NULL){
                next_next->prev = temp;
            }
            delete nodeTodelete;
        }
        else{
            temp=temp->next;
        }
    }

    return head;
}
