#include<iostream>
using namespace std;

int main() {

    //When a program is about to execute it has 2 types of memory --> 'Stack'(Small) & 'Heap'(Large)
    //At time of compiling compiler allocates stack memory

    //now when we declare size of array like 50 --> program says to compiler that bring a stack for arr[50]
    int arr[50];

    //now in this case --> compiler give a stack memory to program --> now 2 cases arise:
    //case 1: if input taken is < stack memory --> code will run;
    //case 2: if input taken is > stack memory --> code will crash
    //allocating memory through stack is called 'static memory allocation'
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }

    //Now to solve case 2 we have to call heap memory which is big enough than any input taken
    //to call this memory we use keyword 'new'
    //allocating memory through heap is called 'dynamic memory allocation'

    int n;
    cin>>n;
    //this is how we call stack memory
    int* arr = new int[n];
    //right side is in stack // left was in heap
    //total memory taken = 8 + 4*n

    for(int i = 0; i<n; i++){
        cin>>arr[i];
    }

    for(int j=0; j<n; j++){
        cout<<arr[j]<<" ";
    }

    //what will happen during execution?
    while(true){
        int f =5;
    }
    //during execution when while block hits i=5 then after coming out of block this memory will release
    //so there is no memory waste in stack

    while(true){
        int* j = new int;
    }
    //now in this left part that was in stack will release after every execution but in right part that is heap that will not relase
    //it is adding in heap like --> 8+8+8+8...................

    //to avoid this bad practice
    delete j;

    return 0;
}