/*
class Node {
  public:
    int data;
    Node* next;
    Node* random;

    Node(int x) {
        data = x;
        next = NULL;
        random = NULL;
    }
};
*/
#include <unordered_map>
class Solution {
    private:
    void insertToTail(Node* &head,Node* &tail,int d){
    Node* newNode = new Node(d);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return ;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
}
  public:
    Node* cloneLinkedList(Node* head) {
        // code here
       Node*  cloneHead = NULL;
       Node*  cloneTail = NULL;
       
       Node* temp = head;
       
       while(temp!=NULL){
           insertToTail(cloneHead,cloneTail,temp->data);
           temp = temp->next;
       }
       
       temp = head;
       Node* temp1 = cloneHead;
       unordered_map<Node* , Node*> newToOld;
       
       while(temp!=NULL && temp1!=NULL){
           newToOld[temp] = temp1;
           temp=temp->next;
           temp1=temp1->next;
       }
       
       temp1 = cloneHead;
       temp=head;
       while(temp1!=NULL){
           temp1->random=newToOld[temp->random];
           temp=temp->next;
           temp1=temp1->next;
       }
       
       return cloneHead;
       
       
    }
};