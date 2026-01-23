//approach 1
int getlen(Node* &head){
    int len=0;
    Node* temp = head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }

    return len;
}

Node *findMiddle(Node *head) {
    // Write your code here
    if(head == NULL || head->next == NULL){
        return head;
    }

    int len = getlen(head)/2;
    int i=1;
    Node* temp1 = head;

    while(i<(len+1)){
        temp1=temp1->next;
        i++;
    }

    return temp1;
}

//approach 2
Node *findMiddle(Node *head) {
    // Write your code here
    if(head == NULL || head->next == NULL){
        return head;
    }

    if(head->next->next == NULL){
        return head->next;
    }

    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
        }
        slow = slow->next;
    }

    return slow;
}