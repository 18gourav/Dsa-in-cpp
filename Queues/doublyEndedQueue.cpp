#include <bits/stdc++.h> 
class Deque
{
public:
    int *arr;
    int front;
    int rear;
    int size;
    // Initialize your data structure.
    Deque(int n)
    {
       size = n;
       front = rear = -1;
       arr = new int[size];
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        // check queue full or not
        if(isFull()){
            return false;
        }
        //push front first elem
        else if(front == -1){
            front = rear = 0;
        }
        //now a lop to make sure queue is doubly ended
        else if(front == 0){
            front = size-1;
        }
        else{
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        // first check queue is full 
        if(isFull()){
            return false;
        }
        //ab hum ye dekhenge ki ab first elem hai ya nhi
        else if(rear == -1){
            front = rear =0;
        }
        //now a lop to make sure queue is doubly ended
        else if(rear == size-1 && front != 0){
            rear = 0;
        }
        else {
            rear++;
        }
        arr[rear] = x;
        return true;
        
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        // check if queue is empty
        if(isEmpty()){
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

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
        // check if queue is empty
        if(isEmpty()){
            return -1;
        }
        int ans = arr[rear];
        arr[rear] = -1;
        //pop first elem
        if(front == rear){
            front =rear= -1;
        }
        else if(rear == 0){
            rear = size-1;
        }
        else{
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
        if(isEmpty()){
            return -1;
        }
        else{
            return arr[rear];
        }
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1){
            return true;
        }
        else{
            return false;
        }
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
        if((front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1))){
            return true;
        }
        else{
            return false;
        }
    }
};