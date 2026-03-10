#include<stack>
class SpecialStack {
    public:
    stack<int> s;
    int min;
        
    void push(int data) {
        // check if inserting first elem
        if(s.empty()){
            s.push(data);
            min = data;
        }
        else{
            if(data<min){
                s.push(2*data-min);
                min = data;
            }
            else{
                s.push(data);
            }
        }
    }

    void pop() {
        // Implement the pop() function.
        if(s.empty()){
            cout<<"stack undeflow";
        }
        int curr = s.top();
        s.pop();
        if(curr>min){
            return ;
        }
        else{
            int prevMini = min;
            int val = 2*min - curr;
            min = val;
        }
    }

    int top() {
        // Implement the top() function.
        if(s.empty()){
            return -1;
        }
        int curr = s.top();
        if(curr<min){
            return min;
        }
        else{
            return curr;
        }
    }

    int getMin() {
        // Implement the getMin() function.
        if(s.empty()){
            return -1;
        }
        return min;
    }  
};