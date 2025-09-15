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
    int *ptr = &num;

    return 0;
}