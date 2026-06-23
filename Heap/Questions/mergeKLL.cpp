class compare{
    public:
        bool operator()(Node* a,Node* b){
            return a->data > b->data;
        }
};
Node* mergeKLists(vector<Node*> &listArray){
    int k = listArray.size();

    if(k == 0){
        return NULL;
    }

    priority_queue<Node*,vector<Node*>,compare> minHeap;

    //step1 -> sab ll ke head ko min heap ma daldo
    for(int i=0; i<k; i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }
    }

    Node* head = NULL;
    Node* tail = NULL;

    //step 2:
    while(!minHeap.empty()){
        Node* top = minHeap.top();
        minHeap.pop();

        if(top -> next != NULL){
            minHeap.push(top->next);
        }
        if(head == NULL){
            head = top;
            tail = top;
        }
        else{
            tail -> next = top;
            tail = top;
        }
    }

    return head;
}
//TC: O(n*k(logk))
//TC: O(k)