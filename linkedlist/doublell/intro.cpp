//double linked list node has three parts: prev(pointing to previous node),data(data of that node),next(pointing to the next node)
#include<iostream>
using namespace std;

class Node {
    public:
    Node* prev;
    Node* next;
    int data;

    Node(int data){
        this ->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};

void printdll(Node* &head){
    Node *temp = head;
    while(temp != NULL){
        cout<< temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getLen(Node *&head){
    int len =0;
    Node *temp = head;
    while(temp != NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void insertAtHead(Node* &head,int d){
    Node* Node1 = new Node(d);
    Node1->next = head;
    head->prev=Node1;
    head = Node1;
}

int main(){
    Node *newNode = new Node(10);

    Node *head = newNode;
    printdll(head);

    insertAtHead(head,15);
    printdll(head);

    cout<<getLen(head)<<endl;
    return 0;
}