#include<iostream>
using namespace std;

int firstOcuurence(int arr[],int n, int k){
   int s = 0;
   int e=n-1;
   int ans = -1;
   int mid = s + (e-s)/2;

   while(s<=e){
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

   return ans;
}

int secOcuurence(int arr[],int n, int k){
   int s = 0;
   int e=n-1;
   int ans = -1;
   int mid = s + (e-s)/2;

   while(s<=e){
    if(arr[mid] == k){
        ans = mid;
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

   return ans;
}

int main() {
    int arr[5] = {1,2,2,3,5};
    int first = firstOcuurence(arr,5,2);
    int sec = secOcuurence(arr,5,2);

    cout<<"first occ is "<<first<<endl<<"second occ is "<<sec;
    
}