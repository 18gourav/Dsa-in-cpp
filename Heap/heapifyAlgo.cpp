//Heapify Algo --> It is a algo in which we place a node at its correct place

#include<iostream>
using namespace std;

void heapify(int arr[],int n,int index){
    int largest = index;
    int left = largest * 2;
    int right = largest * 2 + 1;

    if(left < n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right < n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != index){
        swap(arr[largest],arr[index]);
        heapify(arr,n,largest);
    }

}
//TC of heapify algo is O(logn)

int main(){

    //in a heap
    //Leaf nodes range are n/2 + 1 --> n
    //Now suppose if we have to heapify all nodes in a tree, then we do not have to heapify all nodes cuz leaf nodes are itself a heap
    //so we run heapify func in loop till n/2 to heapify full tree

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    for(int i = n/2; i > 0; i-- ){
        heapify(arr,n,i);
    }

    for(int i=1; i<=n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}