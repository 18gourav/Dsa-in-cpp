/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
       data = x;
       next = NULL;
    }
};
*/

//iss solution ma hum log linke list ka middle nikal raha ha
//fir us middle ka aage sa array ko reverse kar de raha ha
//then compary after middle and before
class Solution {
    private:
    Node* getMiddle(Node* head){
        Node* slow = head;
        Node* fast = head->next;
        
        while(fast != NULL && fast->next !=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
    
    Node* reverse(Node* head){
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev=curr;
            curr = next;
        }
        
        return prev;
    }
  public:
    bool isPalindrome(Node *head) {
        //  code here
        if(head == NULL || head->next==NULL){
            return true;
        }
        
        Node* middle = getMiddle(head);
        Node* temp = middle->next;
        middle->next = reverse(temp);
        
        Node* curr = head;
        Node* curr2 = middle->next;
        
        while(curr2!=NULL){
            if(curr->data != curr2->data){
                return false;
            }
            curr = curr->next;
            curr2 = curr2->next;
        }
        
        return true;
    }
};