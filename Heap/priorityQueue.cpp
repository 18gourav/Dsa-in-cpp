#include<iostream>
#include<queue>
using namespace std;

int main(){

    //max heap
    priority_queue<int> maxHeap;

    maxHeap.push(4);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(3);

    cout<<"element at top is "<<maxHeap.top()<<endl;
    maxHeap.pop();
    cout<<"element at top is "<<maxHeap.top()<<endl;
    cout<<"max heap size "<<maxHeap.size()<<endl;

    //min heap
    priority_queue<int, vector<int>, greater<int>> minHeap;

    minHeap.push(4);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(3);

    cout<<"element at top is "<<minHeap.top()<<endl;
    minHeap.pop();
    cout<<"element at top is "<<minHeap.top()<<endl;
    cout<<"max heap size "<<minHeap.size()<<endl;


    return 0;
}