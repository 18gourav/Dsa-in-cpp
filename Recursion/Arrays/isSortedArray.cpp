#include<iostream>
using namespace std;

bool isSorted(int arr[],int size){
    //best case
    if(size == 0 || size == 1){
        return true;
    }

    if(arr[0] > arr[1]){
        return false;
    }
    else{
        int remPart = isSorted(arr+1,size-1);
        return remPart;
    }


}

int main(){

    int arr[5] = {1,2,3,37,32};
    int size = 5;

    int ans = isSorted(arr,size);
    if(ans)
    cout<<"the array is sorted";

    else
    cout<<"the array is not sorted";

    return 0;
}