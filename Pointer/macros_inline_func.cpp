#include<iostream>
using namespace std;
//these are called macros
//it cannot change by anyone
//it does not occupy any space
//solve all problem mentioned below
#define PI 3.14

//synatx of declaring inline var
inline int getNo(int& a,int& b){
    return (a<b)? a:b;
}

int main() {

    int r = 5;

    //suppose we need PI 1000 times in this code,instead of writing 3.14 we declare it as a variable then use it
    //its good but not optimal-->why?
    //first it will take some space
    //anyone can change it
    // double PI = 3.14
    //solution? --> macros see line 3rd
    double area = PI * r * r;
    cout<<area;


    //inline func
    int a = 2,b = 3;
    int ans = getNo(a,b);;

    // if(a<b){
    //     ans = a;
    // }
    // else {
    //     ans = b;
    // }
    //instead of writing all this in one line we can write
    ans = (a<b) ? a : b;

    return 0;
}