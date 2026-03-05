//this is the solution which i think on my own
#include <bits/stdc++.h> 
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    vector<int> arr;
    while(!myStack.empty()){
        int n = myStack.top();
        myStack.pop();
        arr.push_back(n);
    }

    myStack.push(x);

    for(int i=arr.size();i--; i>0){
        myStack.push(arr[i]);
    }

    return myStack;
}

//this is the more optimised solution
//in this solution we used recursion
#include <bits/stdc++.h> 
void solve(stack<int>& myStack,int x){
    if(myStack.empty()){
        myStack.push(x);
        return ;
    }

    int no = myStack.top();
    myStack.pop();

    solve(myStack,x);

    myStack.push(no);
}
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
    // Write your code here.
    solve(myStack,x);
    return myStack;
}
