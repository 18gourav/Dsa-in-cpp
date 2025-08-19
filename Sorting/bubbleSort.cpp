// time complexity = O(n^2)
// best= O(n) worst = O(n^2)
// space complexity = O(1)

#include <bits/stdc++.h> 
void bubbleSort(vector<int>& arr, int n)
{   
    // Write your code here.
    bool swapped = false;
    for(int i=1; i<n; i++){
        for(int j = 0; j<n-i; j++){
            if(arr[j]>arr[j+1]){
                swapped = true;
                swap(arr[j],arr[j+1]);
            }
        }
        if(swapped == false){
            break;
        }
    }
}