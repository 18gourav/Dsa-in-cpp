#include<iostream>
using namespace std;

int printArray(int arr[], int size) {
    for(int i =0; i<size; i++) {
        cout<< arr[i] << endl;
    }
}

int main() {
    
    int array[15] = {2,6,7};


    // the problem with this is that it returns the original size we have declared of that arry not acc to elements 
    //stored in array
    // int size = sizeof(arr)/sizeof(int);

    // cout<<"the size of arr is "<<size;
    
    //now in this i have defined no of element present in array as array size
    //this is good than that above formula
    printArray(array, 3);
    
    return 0;
}