//stack is the data structure whi follow the LIFO(last in first out) principle
//its major operations are:
//push->push an element into the stack
//pop->remove the latest element from the stack
//peek/top->give the top of the stack eg: 1 2 3 4-> here top elem is the 4
//empty->give bool value by checking the stack is empty or not

#include<iostream>
#include<stack>
using namespace std;

int main(){

    stack<int> s;

    s.push(2);
    //stack->2
    s.push(3);
    //stack->2,3

    cout<<"the top element is "<< s.top()<<endl;
    //output-3

    s.pop();
    //stack->2

    cout<<"the top element after pop "<< s.top()<<endl;
    //output-2

    if(s.empty()){
        cout<<"the stack is empty"<<endl;
    }
    else{
        cout<<"the stack is not empty"<<endl;
    }

    cout<<"the size of stack is "<<s.size();


    return 0;
}