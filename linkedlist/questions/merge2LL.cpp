#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
void insertatTail(Node<int> *& node,Node<int>* curr){
    node->next = curr;
    node=curr;
}

Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    // Write your code here
    Node<int>* outputHead = new Node(-1);
    Node<int>* outputTail = outputHead;

    Node<int>* First = first;
    Node<int>* Sec = second;
    
    while(First!=NULL && Sec!=NULL){
        if(First->data < Sec->data){
            insertatTail(outputTail,First);
            First = First->next;
        }
        else{
            insertatTail(outputTail,Sec);
            Sec = Sec->next;
        }
    }

    while(First!=NULL){
        insertatTail(outputTail,First);
        First = First->next;
    }

    while(Sec!=NULL){
        insertatTail(outputTail,Sec);
        Sec = Sec->next;
    }

    Node<int>* head = outputHead->next;

    delete outputHead;
    return head;

}
