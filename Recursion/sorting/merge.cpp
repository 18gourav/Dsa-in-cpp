#include<iostream>
using namespace std;

void merge(int *arr,int s,int e){

    int mid = (s+e)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    int *first = new int[len1];
    int *second = new int[len2];


    int k = s;
    for(int i=0; i<len1; i++){
        first[i] = arr[k++];
    }

   k=mid+1;
    for(int i=0; i<len2; i++){
        second[i] = arr[k++];
    }

    
    int firstIndex = 0;
    int secondIndex = 0;
    k = s;

    while(firstIndex<len1 && secondIndex<len2){
        if(first[firstIndex] < second[secondIndex]){
            arr[k++] = first[firstIndex++];
        }
        else{
            arr[k++] = second[secondIndex++];
        }
    }
    while(firstIndex<len1){
        arr[k++] = first[firstIndex++];
    }

    while(secondIndex<len2){
        arr[k++] = second[secondIndex++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr,int s,int e){
    if(s>=e){
        return ;
    }

    int mid = (s+e)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}

int main() {

    int arr[5] = {4,2,8,5,1};
    mergeSort(arr,0,4);

    for(int i=0; i<5; i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}   