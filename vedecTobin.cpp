
#include<iostream>
using namespace std;

int main() {
    int n,bits;
    cin >> n;
    int no = -n;

    no = ~no;

    no = no|1;  

    for(int i=31; i>0; i--) {
        cout << ((n>>1)&1) << endl;
    }
    
    return 0;
}      