#include <iostream>
using namespace std;
// this is method is full correct but it has 2 unneccesary variable -> start and next
// void swap(int arr[],int n) {
//     int start = 0;
//     int next = start + 1;

//     while(next<n) {
//         swap(arr[start],arr[next]);
//         start = start + 2;
//         next = next + 2;
//     }
// }

void swapAlternate(int arr[], int n){
    for(int i=0; i<n; i+=2){
        if(i+1<n){
            swap(arr[i],arr[i+1]);
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<' ';
    }
}

int main() {

     int arr[5] = {1,2,3,4,5};
     int brr[6] = {1,2,3,4,5,6};

     swapAlternate(arr,5);
     printArray(arr,5);

     cout<<endl;

     swapAlternate(brr,6);
     printArray(brr,6);


    return 0;
}