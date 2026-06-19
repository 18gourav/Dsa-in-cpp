#include <bits/stdc++.h> 
void heapify(vector<int> &arr,int n,int index){
    int largest = index;
    int left = largest * 2 + 1;
    int right = largest * 2 + 2;

    if(left < n && arr[largest] > arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] > arr[right]){
        largest = right;
    }

    if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,n,largest);
    }

}
vector<int> buildMinHeap(vector<int> &arr)
{

    int n = arr.size();

    for(int i = n/2; i >= 0; i-- ){
        heapify(arr,n,i);
    }

    return arr;
}
