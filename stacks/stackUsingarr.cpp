#include<iostream>
using namespace std;

class stack{
    public:
        int *arr;
        int top;
        int size;

    stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int elem){
        if(size-top > 1){
            top++;
            arr[top] = elem;
        }
        else{
            cout<<"Stack is Overflow"<<endl;
        }
    }

    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top>=0){
            return arr[top];
        }
        else{
            return -1;
        }
    }

    bool isEmpty(){
        if(top>=0){
            return false;
        }
        else{
            return true;
        }
    }

};

int main(){

    stack st(5);

    st.push(22);
    st.push(23);
    st.push(28);

    cout<<"the top elem of stack is "<<st.peek()<<endl;

    st.pop();
    cout<<"the top elem of stack is "<<st.peek()<<endl;


    return 0;
}