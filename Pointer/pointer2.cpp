#include<iostream>
using namespace std;

int main() {

   int arr[10] = {2,5,6};

// it indicates arr[0] address
   cout<<arr<<endl;

// it indicates arr[0] address
   cout<<&arr<<endl;

// it indicates arr[0] address
   cout<<&arr[0]<<endl;

   //we know arr point to addres of arr[0] --> *arr--> value at arr-->so it prints value at arr[0] 
   cout<<"4th "<< *arr << endl;
   //output is 2

   //output --> 3
   cout<< "5th " << *arr + 1<<endl;

   cout<<*(arr+2)<<endl;
   //in general we make a formula --> arr[i] = *(arr + i)
   //even if we write it also like--> i[arr] = *(i + arr)

   int i = 2;
   //basicall means arr[2]
   cout<<i[arr]<<endl;

   int temp[10];

   cout<<sizeof(temp)<<endl;
   int *ptr = &temp[0];
   cout<<sizeof(*ptr)<<endl;

    return 0;
}