#include<iostream>
using namespace std;

void update2(int &n) {
    n++;
}

void update(int n) {
    n++;
}

int main() {
    //what is reference varibale? --> it means have 2 variable pointing to same memory(eg - i,j pointing to 5)

    int i = 6;

    //this is syntax how reference variable created
    int &j = i;

    cout<<i<<endl;
    i++;
    cout<<i<<endl;
    j++;
    cout<<i<<endl;

    //here a qsn arise --> Why we need it?
    //in this when we call update function the "i" was updated in the update func not in main function
    //This concept is called pass by value
    cout<<i<<endl;
    update(i);
    cout<<i<<endl;

//now here ref variable comes in play --> what if we pass ref var in update --> then the i will also update
// in update2 and name but with diff names
//This concept is called pass by refrence
    cout<<i<<endl;
    update2(i);
    cout<<i<<endl;

    return 0;
}