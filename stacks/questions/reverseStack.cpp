void pushAtbottom(stack<int>& myStack,int x){
    if(myStack.empty()){
        myStack.push(x);
        return ;
    }

    int no = myStack.top();
    myStack.pop();

    pushAtbottom(myStack,x);

    myStack.push(no);
}
void reverseStack(stack<int> &stack) {
    // Write your code here
    if(stack.empty()){
        return ;
    }

    int no = stack.top();
    stack.pop();

    reverseStack(stack);

    pushAtbottom(stack,no);
}