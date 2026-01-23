int getLen(Node *&head){
    int len =0;
    Node *temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}
Node* kReverse(Node* head, int k) {
    // Write your code here.
    if(head == NULL){
        return NULL;
    }

    int len = getLen(head);

    if(k>len){
        return head;
    }

    Node* curr = head;
    Node* prev = NULL;
    Node* forward = NULL;
    int i=0;

    while(curr != NULL && i<k){
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        i++;
    }

    if(forward != NULL){
        head->next = kReverse(forward,k);
    }

    return prev;

}