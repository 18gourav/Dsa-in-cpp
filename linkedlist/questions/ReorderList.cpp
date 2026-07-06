// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed

class Solution {
    ListNode* findMiddle(ListNode* head){
        if(head == NULL || head ->next == NULL){
            return head;
        }

        if(head->next->next == NULL){
            return head->next;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != NULL){
            fast = fast->next;
            if(fast!=NULL){
                fast = fast -> next;
            }
            slow = slow -> next;
        }

        return slow;
    }

    void reverseLL(ListNode* &head){
        if(head == NULL || head->next == NULL){
            return ;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
    }
public:
    void reorderList(ListNode* head) {
        if(head == NULL){
            return ;
        }

        if(head->next == NULL){
            return ;
        }

        //step1 -> find middle of linked list
        ListNode* temp = findMiddle(head);

        //step2->now separate linked list after middle
        ListNode* head1 = temp->next;
        temp->next = NULL;

        //step2 -> now reverse linked list
        reverseLL(head1);

        //step3 ->now attach all head1 node to head node
        ListNode* first = head;
        ListNode* sec = head1;

        while(sec != NULL){
            ListNode* temp1 = first->next;
            ListNode* temp2 = sec->next;

            first->next = sec;
            sec->next = temp1;

            first = temp1;
            sec = temp2;                                                                                
        }

    }
};