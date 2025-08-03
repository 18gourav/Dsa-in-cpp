#include<iostream>
using namespace std;

int main() {
     
    int n,sum=0;
    cin>>n;

    int i =1;

    while(i<=n) {
       if(i % 2 == 0) {
           sum += i; // Add only even numbers
       }
       i=i+1;
    }

    cout<<sum<<endl;


    return 0;
}