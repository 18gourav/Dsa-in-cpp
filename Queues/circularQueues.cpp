#include <bits/stdc++.h> 
class CircularQueue{
    public:
    int size;
    int front;
    int rear;
    int *arr;
    CircularQueue(int n){
        size = n;
        front = rear = -1;
        arr = new int[size];
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value){
        // first check queue is full 
        if((front == 0 && rear == size-1) || (rear == (front-1)%(size-1))){
                return false;
        }
        //ab hum ye dekhenge ki ab first elem hai ya nhi
        else if(rear == -1){
            front = rear =0;
        }
        //ab hum vo vala case dekhenge jisma rear last ma ho or
        //vo fir first ma insert kare
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = value;
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue(){
        // check if queue is empty
        if(front == -1){
            return -1;
        }
        int ans = arr[front];
        arr[front] = -1;
        //pop first elem
        if(front == rear){
            front =rear= -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            front++;
        }
        return ans;
    }
};