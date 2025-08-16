#include<iostream>
using namespace std;

int Occurence(int arr[],int n,int k){
    int s = 0,e=n-1;
    int ans = -1;
    int anss = -1;

    int mid = s + (e-s)/2;

    while(s<e){
       if(arr[mid] == k){
           ans = mid;
           e = mid-1;
       }
       else if(k>arr[mid]){
         s = mid+1;
       }
       else if(k<arr[mid]){
          e = mid-1;
       }

       mid = s + (e-s)/2;
    }

    while(s<e){
       if(arr[mid] == k){
           anss = mid;
           s = mid+1;
       }
       else if(k>arr[mid]){
         s = mid+1;
       }
       else if(k<arr[mid]){
          e = mid-1;
       }

       mid = s + (e-s)/2;
    }

    return anss;
    
}

int main() {
    int arr[5] = {1,2,3,3,5};
    cout<<"occurence of 3 is "<<Occurence(arr,5,3);
}