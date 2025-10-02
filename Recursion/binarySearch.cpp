#include<iostream>
using namespace std;

bool binarySearch(int arr[],int s,int e,int key){
    if(s>e){
        return false;
    }

    int mid = s + (e-s)/2;
    if(arr[mid] == key){
        return true;
    }

    else if(arr[mid]<key){
        return binarySearch(arr,mid+1,e,key);
    }
    else{
        return binarySearch(arr,s,mid-1,key);
    }

}


int main(){

    int arr[5] = {1,2,3,4,5};
    int size = 5;

    int ans = binarySearch(arr,0,4,4);

    if(ans){
        cout<<"the elem is present";
    }
    else {
        cout<<"the elem is not present";
    }
    
    return 0;
}