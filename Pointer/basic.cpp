#include<iostream>
using namespace std;

int main() {

    //basically it means we created a block num which has a address(for eg 200) in which we have 5
    int num = 5;

    //after that in a table called 'symbol table' num is mapped to address 200
    //then this cout statment go to table check address of num and go to that address and print that value
    cout<<num<<endl;

    //this give address of the num in hexadecimal address
    cout<<&num<<endl;

    //*ptr this is called the pointer which store the address of the num
    //*ptr also means insert value in ptr
    int *ptr = &num;

    //in this we get output - 5
    //how?-- *ptr means value in ptr --> which is 100--> 100 refers to num-->which is 5
    cout<< *ptr;

    //we created a *pt which is pointing toward a int value has some grabage value
    //this is meant to be a bad practice cuz we are pointing a no which does not exist
    // int *pt;

    int i = 8;
    int *p = 0;
    //we can also declare pointer after writing it null
    p = &i;

    cout<<p<<endl;
    cout<<*p;
    //let assume address of i is 200
    
    //we think its ans would be 201, but its not
    //int has 4 bits stored so it is --> 204
    p = p + 1;
    

    //copying of pointer
    int *q = p;
    //output will be 8
    cout<<*q;
    

    return 0;
}