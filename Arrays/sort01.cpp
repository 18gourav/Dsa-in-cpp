#include<iostream>
using namespace std;

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

void Sort(int arr[],int n){
    int left = 0;
    int right = n-1;

    while(left < right){
        if(arr[left] == 0){
            left++;
        }
        if(arr[right] == 1){
            right--;
        }
        if(arr[left]==1 && arr[right]==0){
            swap(arr[left],arr[right]);
            left++;
            right--;
        }
    }
}

int main() {
    int arr[6] = {1,0,1,1,0,1};
    Sort(arr,6);
    printArray(arr,6);
}