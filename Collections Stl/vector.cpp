#include<iostream>
#include<vector>
using namespace std;

int main() {
    // vector is dynamic

    //capacity --> it is the noo of elements it can occupy
    //size --> it is the current size of vector means the no of elem stored

    vector<int> v;
    cout<<"the size of vector v is "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"the capacity of vector v is "<<v.capacity()<<endl;
    cout<<"the size of vector v is "<<v.capacity()<<endl;


    v.push_back(5);
    // when we push back(push any elem in vector) it doubles it capacity
    cout<<"the capacity of vector v is "<<v.capacity()<<endl;
    cout<<"the size of vector v is "<<v.capacity()<<endl;


    v.push_back(8);
    cout<<"the capacity of vector v is "<<v.capacity()<<endl;
    cout<<"the size of vector v is "<<v.size()<<endl;

    // syntax of printing the vector
    for(int i:v){
        cout<<i<<" ";
    }

    cout<<endl;

    // this means we create a vector a with 5 elem 1 only
    vector<int> a(5,1);
    for(int j:a){
        cout<<j<<" ";
    }

    return 0;
}