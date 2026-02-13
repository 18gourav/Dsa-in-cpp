//iss ques ma hama 2 linked list ko add karde ek ll return karni ha
//hum pehle jo 2 linked list di hui ha unko reverse kardenge
//fir reversed linked list ko add kardenge
//fir add karke jo linked list bani ha usko reverse kardenge
//fir return ans
class Solution {
  private:
  Node* trimLeadingZeros(Node* head) {
    while (head != NULL && head->data == 0 && head->next != NULL) {
            head = head->next;
         }
        return head;
    }
  Node* reverse(Node* &head){
      
    if(head == NULL || head->next == NULL){
        return head;
    }
      
      Node* prev = NULL;
      Node* curr = head;
      Node* next = NULL;
      
      while(curr!=NULL){
          next = curr->next;
          curr->next = prev;
          prev=curr;
          curr = next;
      }
      
      return prev;
  }
  
  void insertAtTail(Node* &head, Node* &Tail, int d){
    Node* node = new Node(d);

    if(head == NULL){
        head = node;
        Tail = node;
        return;
    }

    Tail->next = node;
    Tail = node;
}

  public:
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        head1 = trimLeadingZeros(head1);
        head2 = trimLeadingZeros(head2);
        
        head1 = reverse(head1);
        head2 = reverse(head2);
        Node* outputHead = NULL;
        Node* outputTail = NULL;
        int carry=0;
        
        while(head1!=NULL || head2!=NULL || carry!=0){
            int val1=0;
            if(head1!=NULL){
                val1=head1->data;
            }
            
            int val2=0;
            if(head2!=NULL){
                val2=head2->data;
            }
            
            int ans = val1 + val2 + carry;
            int finalAns = ans%10 ;
            insertAtTail(outputHead,outputTail,finalAns);
            carry = ans/10;
            if(head1!=NULL)
                head1 = head1->next;
                
            if(head2!=NULL)
                head2 = head2->next;
        }
        
        
        outputHead = reverse(outputHead);
        
        return outputHead;;
       
    }
};