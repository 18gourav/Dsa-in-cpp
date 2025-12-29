// You are given a positive integer ‘n’.
// Your task is to find and return its square root. If ‘n’ is not a perfect square, then return the floor 
// value of sqrt(n)
#include<iostream>
using namespace std;

long long int binarySearch(int n){
    int s = 0;
    int e = n;
    int ans = 0;

    long long int mid = s + (e-s)/2;

    while (s<=e)
    {
        long long int sqr = mid * mid;

        if(sqr == n){
            return mid;
        }
        else if(sqr<n){
            ans = mid;
            s = mid + 1;
        }
        else if(sqr>n){
            e = mid + 1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int main() {

   int output = binarySearch(1000000);

   cout<<output;


    return 0;
}