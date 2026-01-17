//What is a linkedList? --> the linked list is a linear data structure which is a collection of the nodes
//what are nodes? --> it consist (data and next node address)

//why we need linked list? --> Because it is dynamic in nature(it can shrink or grow at aany time)
//in case of insertion/deletion we don't need to shift elements like in arrays

//the first node in linked list is called (HEAD)
//linked list has 4 types: Single LL, Double LL, Circular LL, Double Circular LL

//To create a node we will create a class for it

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    
    Node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(Node* &Head,int d){
    Node* first = new Node(d);
    first -> next = Head;
    Head = first;
}

void insertAtTail(Node* &Tail,int d){
    Node* first = new Node(d);
    Tail -> next = first;
    Tail = first;
}

void insertAtMid(Node* &Head,int d,int posn){
    if(posn == 1){
        insertAtHead(Head,d);
        return;
    }
    Node *temp = Head;
    int cnt = 1;

    while(cnt < posn-1){
        temp = temp -> next;
        cnt++;
    }

    Node * NodeToinsert = new Node(d);
    NodeToinsert->next = temp->next;
    temp->next = NodeToinsert;
}

void printLL(Node * Head){
    Node *temp = Head;
    while(temp != NULL){
        cout<<temp ->data<<' ';
        temp = temp->next;
    }
    cout<<endl;
};

int main() {

    //we do this to get it into heap memory
    Node* newNode = new Node(10);
    //cout<<newNode -> data<<endl;
    //cout<<newNode -> next;

    Node* Head = newNode;
    Node* Tail = newNode;

    printLL(Head);

    insertAtTail(Tail,12);
    printLL(Head);

    insertAtTail(Tail,13);
    printLL(Head);

    insertAtMid(Head,15,1);
    printLL(Head);

}

