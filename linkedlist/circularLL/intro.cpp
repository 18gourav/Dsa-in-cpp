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
            next=NULL;
        }
        cout<<"memory free for node with data "<<value<<endl;
    }
};

void insertElem(Node* &Tail,int elem,int d){
    
    //empty list
    if(Tail==NULL){
        Node * newNode = new Node(d);
        Tail = newNode;
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

void print(Node* &Tail){
    Node* temp = Tail;

    if(Tail == NULL){
        cout<<"list is empty"<<endl;
        return ;
    }

   do
   {
    cout<<temp->data<<" ";
    temp = temp->next;
   } while (temp!=Tail);

   cout<<endl;
   
}

void deleteElem(Node * &Tail,int value){

    if(Tail == NULL){
        cout<<"try again"<<endl;
        return ;
    }

    else{
        Node* prev = Tail;
        Node* curr = prev->next;

        while(curr->data!=value){
            prev = curr;
            curr=curr->next;
        }
        if(curr == prev){
            Tail = NULL;
        }

        else if(Tail == curr){
            Tail = prev;
        }

        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
        
    }
}

int main(){
    Node* Tail = NULL;

    insertElem(Tail,5,3);
    print(Tail);

    insertElem(Tail,3,5);
    print(Tail);

    insertElem(Tail,5,8);
    print(Tail);

    insertElem(Tail,5,7);
    print(Tail);

    insertElem(Tail,8,9);
    insertElem(Tail,3,4);
    print(Tail);

    deleteElem(Tail,3);
    print(Tail);

    return 0;
}