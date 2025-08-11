#include<iostream>
using namespace std;
// ye vali approach galat ha kyuki ye bs array ko reverse ma print karta ha, na ki actually reverse karta ga
// void ReverseArray(int arr[],int n) {

//     for(int i=n-1; i>=0 ; i--) {
//         cout<<arr[i]<<" ";
//     }
// }

//ye vali approach sahi ha kyuki ye main memory ma bhi array ko reverse kar rahi ha
void ReverseArray(int arr[], int n){
    int start = 0;
    int end = n-1;

    while(start <= end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void printArray(int arr[],int n){
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
}

int main() {
    
    int arr[7] = {1,2,3,4,5,8,9};
    int arb[6] = {4,6,2,8,9,3};

    ReverseArray(arr,7);
    printArray(arr,7);

    cout<<endl;

    ReverseArray(arb,6);
    printArray(arb,6);

    return 0;
}