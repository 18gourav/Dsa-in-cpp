class kQueues {
    public:
    int *arr;
    int * front;
    int *rear;
    int freespot;
    int *next;

  public:
    kQueues(int n, int k) {
        // Initialize your data members
        arr = new int[n];
        front = new int[k];
        rear = new int[k];
        
        for(int i=0; i<k; i++){
            front[i] = -1;
            rear[i] = -1;
        }
        
        next = new int[n];
        for(int i=0; i<n; i++){
            next[i] = i+1;
        }
        next[n-1] = -1;
        
        freespot = 0;
    }

    void enqueue(int x, int i) {
        // enqueue element x into queue i
        
        //first check overflow
        if(freespot == -1){
            return;
        }
        
        //now check index to insert
        int index = freespot;
        
        //update freespt
        freespot = next[index];
        
        //check if that elem is first to insert
        if(front[i]  == -1){
            front[i] = index;
        }
        else{
            next[rear[i]] = index;
        }
        
        //now update the next arrau
        next[index] = -1;
        
        //now update rear f that
        rear[i] =index;
        
        //now insert that
        arr[index] = x;
    }

    int dequeue(int i) {
        // dequeue element from queue i
        
        //to check underflow
        if(front[i] == -1){
            return -1;
        }
        
        //first btain the index f element we have to pop
        int index = front[i];
        
        //now shift front
        front[i] = next[index];
        
        //is pop elem is last element
        // // Queue became empty
        // if(front[i] == -1){
        //     rear[i] = -1;
        // }
        
        //now handle that freespot after removing value from that index
        next[index] = freespot;
        freespot = index;
        
        return arr[index];
    }

    bool isEmpty(int i) {
        // check if queue i is empty
        
        if(front[i] == -1){
            return true;
        }
        else{
            return false;
        }
    }

    bool isFull() {
        // check if array is full
        if(freespot == -1){
            return true;
        }
        else{
            return false;
        }
    }
};
