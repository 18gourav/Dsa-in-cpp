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

    ~Node() {
        int value = this->data;
        if(this->next!= NULL){
            delete next;
            this ->next = NULL;
        }
        cout <<"the memory is free for node contain data "<<value<<endl;
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

void insertAtHead(Node* &head,Node* &tail,int d){
    if(head == NULL){
        Node* newNode = new Node(d);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* Node1 = new Node(d);
        Node1->next = head;
        head->prev=Node1;
        head = Node1;
    }
    
}

void insertAttail(Node* &head,Node* &tail,int d){
    if(tail == NULL){
        Node* newNode = new Node(d);
        tail = newNode;
        head = newNode;
    }
    else {
        Node * node2 = new Node(d);
        node2->prev = tail;
        tail->next=node2;
        tail = node2;
    }
    
}

void insertAtposn(Node * &tail,Node * &head,int d,int posn){
    if(posn == 1){
        insertAtHead(head,tail,d);
        return ;
    }

    Node * temp = head;
    int cnt = 1;

    while(cnt<posn-1){
        temp = temp->next;
        cnt++;
    }

    if(temp->next == NULL){
        insertAttail(head,tail,d);
        return ;
    }

    Node * node3 = new Node(d);
    node3->next=temp->next;
    temp->next->prev = node3;
    node3->prev=temp;
    temp->next=node3;
}

void deletingNode(Node* &head,int posn){
    if(posn == 1){
        Node* temp = head;
        head = head->next;
        temp->next=NULL;
        head->prev=NULL;
        delete temp;
    }
    else {
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;

        while(cnt<posn){
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        curr->prev = NULL;
        prev->next=curr->next;
        curr->next=NULL;

        delete curr;
    }
}

int main(){

    Node *head = NULL;
    Node *tail = NULL;

    insertAttail(head,tail,15);
    printdll(head);

    insertAtHead(head,tail,16);
    insertAttail(head,tail,28);
    printdll(head);

    insertAtposn(tail,head,22,2);
    printdll(head);

    deletingNode(head,4);
    printdll(head);

    // cout<<head->data<<endl;
    // cout<<tail->data<<endl;

    cout<<getLen(head)<<endl;
    return 0;
}