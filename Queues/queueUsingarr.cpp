#include <bits/stdc++.h> 
class Queue {
    int *arr;
    int size;
    int qfront;
    int rear;

public:
    Queue() {
        // Implement the Constructor
        size = 100001;
        qfront=0;
        rear = 0;
        arr = new int[size];
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // first queue is empty
        if(qfront==rear){
            return true;
        }
        else{
            return false;
        }
    }

    void enqueue(int data) {
        //first check if queue is full or not
        if(rear == size){
            cout<<"the queue is full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }

    int dequeue() {
        //first check queue is empty
        if(qfront==rear){
            return -1;;
        }
        else{
            int ans = arr[qfront];
            arr[qfront] = -1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear=0;
            }
            return ans;
        }
       

    }

    int front() {
        //first check queue is empty or not
        if(qfront == rear){
            return -1;
        }
        else{
            return arr[qfront];
        }
    }
};