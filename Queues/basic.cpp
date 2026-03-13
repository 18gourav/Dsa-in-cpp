//Queue is a data structure which follows the FIFO rule
//Functions:it has same functions like stack
//stack.push()
//stack.pop()

//now in a stack we have 2 pointers: 1.Rear --> sabse piche wala
                                  // 2. Front --> sabse aaga wala
//They both are at !st elem at begining

//On pushing elem in stack rear will move forward
//On popping elem in stack front will move forward

#include<iostream>
#include<queue>
using namespace std;

int main() {

    queue<int> q;

    q.push(1);
    q.push(3);
    q.push(4);

    q.pop();
    cout<<"the front of queue is "<<q.front()<<endl;
    cout<<"the size of queue is "<<q.size()<<endl;

    q.pop();
    
    if(!q.empty()){
        cout<<"the queue is not empty";
    }
    else{
        cout<<"the queue is empty";
    }


    return 0;
}