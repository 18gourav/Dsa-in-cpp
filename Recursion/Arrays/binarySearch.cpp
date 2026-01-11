#include<iostream>
using namespace std;

bool binarySearch(int arr[],int s,int e,int key){
    //base case
    //if this condition satisfies mean arr does not contain target
    if(s>e){
        return false;
    }

    int mid = s + (e-s)/2;

    if(arr[mid] == key){
        return true;
    }
    if(arr[mid]>key){
        return binarySearch(arr,s,mid-1,key);
    }
    else{
        return binarySearch(arr,mid+1,e,key);
    }

}


int main(){

    int arr[5] = {1,2,3,4,9};
    int size = 5;

    int ans = binarySearch(arr,0,4,12);

    if(ans){
        cout<<"the elem is present";
    }
    else {
        cout<<"the elem is not present";
    }
    
    return 0;
}