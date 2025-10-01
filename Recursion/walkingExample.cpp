#include<iostream>
using namespace std;


//in this example we call this function recursively with updated src value and with a base case also
void reachedHome(int src,int dest) {
    cout<<"Source "<<src<<" "<<"Destination "<<dest<<endl;
    if(src == dest) {
        cout<<"reached destination";
        //in base case it is mandate to have a return statement
        return ;
    }

    src++;
    reachedHome(src,dest);
}

int main() {

    int src = 1;
    int dest = 10;

    reachedHome(src,dest);

    return 0;
}