//the circular LL is of two types:

//1.Single circular LL ----> In this all things remain like single LL, only one change that is the last node points to first node
// instead of null which makes it circular

//2.Double circular LL ----> In this all things remain like double LL, only one change that is last node point to first and first point to
//last that makes it circular

//In this file we will talk about the "Single circular LL"

//'VERY IMP'
//in this we only do 'Tail' because through that we can access tail and head both
#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            next=NULL:
        }
        cout<<"memory free for node with data "<<value;
    }
}

void insertElem(Node* &Tail,int elem,int d){
    
    //empty list
    if(Tail==NULL){
        Node * newNode = new Node(d);
        tail = newNode;
        newNode->next=newNode;
    }
    else{
        //non empty list
        //assuming that elem is present in the list

        Node * curr = Tail;

        while(curr->data != elem){
            curr = curr->next;
        }

        //element founded and curr is on that elem
        Node* Node1 = new Node(d);
        Node1->next=curr->next;
        curr->next=Node1;
    }
}