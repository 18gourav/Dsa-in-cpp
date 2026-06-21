#include <bits/stdc++.h> 
void heapify(vector <int> &ans,int n,int index){
    int largest = index;
    int left = largest * 2 + 1;
    int right = largest * 2 + 2;

    if(left < n && ans[largest] < ans[left]){
        largest = left;
    }
    if(right < n && ans[largest] < ans[right]){
        largest = right;
    }

    if(largest != index){
        swap(ans[largest],ans[index]);
        heapify(ans,n,largest);
    }

}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2) {
    // step 1-> merge two arrays into the ans 
    vector<int> ans;

    for(auto i:arr1){
        ans.push_back(i);
    }
    for(auto i:arr2){
        ans.push_back(i);
    }

    //step 2 -. now heapify the array
    int size = ans.size();
    for(int i = size/2-1; i >= 0; i-- ){
        heapify(ans,size,i);
    }

    return ans;

}