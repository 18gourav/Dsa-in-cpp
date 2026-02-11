/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/


//here is the 1st approach or brute force approach to solve this problem 
//tc:o(n)
//sc:0(n)
Node* sortList(Node *head){
    // Write your code here.
    map<int,int> map1;

    Node* temp = head;
    map1[temp->data] = 0;

    while(temp!=NULL){
        map1[temp->data]++;
        temp = temp->next;
    }

    int a = map1[0];
    int b = map1[1];
    int c = map1[2];

    temp = head;

    int i=1;
    while(i<=a){
        temp->data = 0;
        temp = temp->next;
        i++;
    }

    i=1;
    while(i<=b){
        temp->data = 1;
        temp = temp->next;
        i++;
    }

    i=1;
    while(i<=c){
        temp->data = 2;
        temp = temp->next;
        i++;
    }

    return head;
}

//this is the 2nd approach to solve the problem
//in this we created sep linked list 0,1,2
//and then we merge them and return head
void insertatTail(Node *& node,Node* curr){
    node->next = curr;
    node=curr;
}
Node* sortList(Node *head){
    Node * zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node * oneHead = new Node(-1);
    Node *oneTail = oneHead;
    Node * twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node* curr = head;

    while(curr!=NULL){
        int value = curr->data;
        if(value == 0){
            insertatTail(zeroTail,curr);
        }
        else if(value == 1){
            insertatTail(oneTail,curr);
        }
        else if(value == 2){
            insertatTail(twoTail,curr);
        }
        curr = curr->next;
    }

    //merge all the three lists now to get thee result

    if(oneHead != NULL){
        zeroTail->next=oneHead->next;
    }
    else{
        zeroTail->next=twoHead->next;
    }

    oneTail->next=twoHead->next;
    twoTail->next = NULL;

    head= zeroHead->next;

    delete oneHead;
    delete twoHead;
    delete zeroHead;

    return head;
}